/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:52:14 by obelhami          #+#    #+#             */
/*   Updated: 2024/07/24 20:37:59 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_is_full(t_table *table)
{
	long	i;

	i = 0;
	while (i < table->nbr_philosophers)
	{
		M_LOCK(&table->mutex_full);
		if (table->philos[i].full == false)
		{
			M_UNLOCK(&table->mutex_full);
			return (0);
		}
		M_UNLOCK(&table->mutex_full);
		i++;
	}
	return (1);
}

void	check_all_full(t_table *table, int *_bool)
{
	long	idx;

	idx = 0;
	while (idx < table->nbr_philosophers && *_bool)
	{
		if (all_is_full(table) == 1)
		{
			M_LOCK(&table->mutex);
			table->end_simmulation = true;
			M_UNLOCK(&table->mutex);
			*_bool = 0;
			break ;
		}
		idx++;
	}
}

void	check_philos_death(t_table *table, int *_bool)
{
	long	idx;

	idx = 0;
	while (idx < table->nbr_philosophers && *_bool)
	{
		M_LOCK(&table->mutex_monitor);
		if (table->philos[idx].last_meal_time != 0 && get_time()
			- table->philos[idx].last_meal_time > table->time_to_die)
		{
			M_UNLOCK(&table->mutex_monitor);
			M_LOCK(&table->mutex);
			table->end_simmulation = true;
			printf("%ld %d died\n", get_time()
				- table->start_simmulation, table->philos[idx].id);
			M_UNLOCK(&table->mutex);
			*_bool = 0;
			break ;
		}
		M_UNLOCK(&table->mutex_monitor);
		idx++;
	}
}

void	*monitor(void *ptr)
{
	t_table	*table;
	int		_bool;

	table = (t_table *)ptr;
	_bool = 1;
	while (_bool)
	{
		check_all_full(table, &_bool);
		if (_bool)
		{
			check_philos_death(table, &_bool);
		}
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:28:51 by obelhami          #+#    #+#             */
/*   Updated: 2024/07/26 03:45:45 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_table *table)
{
	long	i;

	i = 0;
	while (i < table->nbr_philosophers)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].last_meal_time = get_time();
		table->philos[i].full = false;
		table->philos[i].meals_counter = 0;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1)
			% table->nbr_philosophers];
		if (i == table->nbr_philosophers - 1)
		{
			table->philos[i].right_fork = &table->forks[i];
			table->philos[i].left_fork = &table->forks[(i + 1)
				% table->nbr_philosophers];
		}
		i++;
	}
}

void	init_forcks(t_table *table)
{
	long	i;

	i = 0;
	while (i < table->nbr_philosophers)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

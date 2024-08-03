/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:58:28 by obelhami          #+#    #+#             */
/*   Updated: 2024/07/26 03:42:56 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_full(t_philo *philo)
{
	M_LOCK(&philo->table->mutex_full);
	if (philo->table->nbr_limit_meals != -1 && philo->meals_counter
		>= philo->table->nbr_limit_meals)
	{
		philo->full = true;
		M_UNLOCK(&philo->table->mutex_full);
		return (1);
	}
	M_UNLOCK(&philo->table->mutex_full);
	return (0);
}

void	*routine(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->id % 2 == 0)
		ft_sleep(60, philos);
	M_LOCK(&philos->table->mutex);
	while (philos->table->end_simmulation == false)
	{
		M_UNLOCK(&philos->table->mutex);
		if (eat(philos))
			return (NULL);
		if (check_full(philos))
			return (NULL);
		if (_sleep(philos))
			return (NULL);
		if (think(philos))
			return (NULL);
		ft_sleep(((philos->table->time_to_die - (get_time()
						- philos->last_meal_time)) / 2), philos);
		M_LOCK(&philos->table->mutex);
	}
	M_UNLOCK(&philos->table->mutex);
	return (NULL);
}

int	creat_threads(t_table *table)
{
	long		i;

	i = -1;
	table->start_simmulation = get_time();
	while (++i < table->nbr_philosophers)
	{
		if (pthread_create(&table->philos[i].th,
				NULL, &routine, &table->philos[i]))
		{
			return (1);
		}
	}
	monitor(table);
	i = -1;
	while (++i < table->nbr_philosophers)
		pthread_join(table->philos[i].th, NULL);
	return (0);
}

int	data_init(t_table *table)
{
	table->philos = malloc(sizeof(t_philo) * table->nbr_philosophers);
	if (!table->philos)
		return (1);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_philosophers);
	if (!table->forks)
		return (1);
	M_INIT(&table->mutex, NULL);
	M_INIT(&table->mutex_monitor, NULL);
	M_INIT(&table->mutex_full, NULL);
	init_forcks(table);
	init_philos(table);
	creat_threads(table);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	else
	{
		memset(&table, 0, sizeof(t_table));
		if (parsing(argc, argv, &table))
			return (1);
		if (table.nbr_philosophers == 0)
			return (1);
		if (table.nbr_limit_meals == 0)
			return (0);
		if (data_init(&table))
			return (1);
	}
	free(table.philos);
	free(table.forks);
	return (0);
}

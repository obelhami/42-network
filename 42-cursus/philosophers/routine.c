/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:01:29 by obelhami          #+#    #+#             */
/*   Updated: 2024/07/24 21:47:40 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	message(t_philo *philo, char *msg)
{
	M_LOCK(&philo->table->mutex);
	if (philo->table->end_simmulation == false)
	{
		printf("%ld %d %s\n", get_time()
			- philo->table->start_simmulation, philo->id, msg);
		M_UNLOCK(&philo->table->mutex);
		return (0);
	}
	M_UNLOCK(&philo->table->mutex);
	return (1);
}

int	think(t_philo *philo)
{
	if (message(philo, "is thinking"))
		return (1);
	return (0);
}

void	get_last_meal_time(t_philo *philo)
{
	M_LOCK(&philo->table->mutex_monitor);
	philo->last_meal_time = get_time();
	philo->meals_counter++;
	M_UNLOCK(&philo->table->mutex_monitor);
}

int	eat(t_philo *philo)
{
	if (philo->table->nbr_philosophers == 1)
	{
		M_LOCK(philo->left_fork);
		if (message(philo, "has taken a left fork"))
		{
			M_UNLOCK(philo->left_fork);
			return (1);
		}
		return (3);
	}
	even_eat(philo);
	return (0);
}

int	_sleep(t_philo *philo)
{
	if (message(philo, "is sleeping"))
		return (1);
	ft_sleep(philo->table->time_to_sleep, philo);
	return (0);
}

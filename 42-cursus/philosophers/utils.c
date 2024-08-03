/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:02:19 by obelhami          #+#    #+#             */
/*   Updated: 2024/07/26 03:44:17 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	check_end(t_philo *philo)
{
	M_LOCK(&philo->table->mutex);
	if (philo->table->end_simmulation == true)
	{
		M_UNLOCK(&philo->table->mutex);
		return (1);
	}
	M_UNLOCK(&philo->table->mutex);
	return (0);
}

void	ft_sleep(long time, t_philo *philo)
{
	long	current_time;

	current_time = get_time();
	while (get_time() - current_time < time && check_end(philo) == 0)
		usleep(500);
}

int	even_eat(t_philo *philo)
{
	M_LOCK(philo->left_fork);
	if (message(philo, "has taken a fork"))
	{
		M_UNLOCK(philo->left_fork);
		return (1);
	}
	M_LOCK(philo->right_fork);
	get_last_meal_time(philo);
	if (message(philo, "has taken a fork"))
	{
		M_UNLOCK(philo->right_fork);
		M_UNLOCK(philo->left_fork);
		return (1);
	}
	if (message(philo, "is eating"))
	{
		M_UNLOCK(philo->right_fork);
		M_UNLOCK(philo->left_fork);
		return (1);
	}
	ft_sleep(philo->table->time_to_eat, philo);
	M_UNLOCK(philo->right_fork);
	M_UNLOCK(philo->left_fork);
	return (0);
}

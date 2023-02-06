/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:59:46 by sasha             #+#    #+#             */
/*   Updated: 2023/01/26 13:56:15 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
	set start time
	set stop = 0
	count meals eaten
	check if someone's dead
	if stop=TRUE, then lock print
*/
void	ft_loop(t_table *table, t_philo *philo)
{
	int		i;
	int		full;

	usleep(2000000);
	table->start_time = ft_set_time();
	pthread_mutex_unlock(table->stop_lock);
	while (1)
	{
		i = 0;
		full = 0;
		while (i < table->philo_num)
		{
			if (ft_is_dead(philo + i, table))
				return ;
			if (ft_all_is_full(philo + i, &full, table))
				return ;
			i++;
		}
	}
}

int	ft_is_dead(t_philo *philo, t_table *table)
{
	long	time;

	time = ft_get_time(table->start_time);
	pthread_mutex_lock(philo->meal_lock);
	if (philo->last_meal_time + table->time_to_die < time)
	{
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_lock(table->stop_lock);
		table->stop = 1;
		pthread_mutex_unlock(table->stop_lock);
		printf("%lu %d died\n", time, philo->num);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	ft_all_is_full(t_philo *philo, int *full, t_table *table)
{
	pthread_mutex_lock(philo->meal_lock);
	if (table->meal_num == -1)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (0);
	}
	if (philo->meal_eaten >= table->meal_num)
	{
		(*full)++;
	}
	pthread_mutex_unlock(philo->meal_lock);
	if (*full == table->philo_num)
	{
		pthread_mutex_lock(table->stop_lock);
		table->stop = 1;
		pthread_mutex_unlock(table->stop_lock);
		return (1);
	}
	return (0);
}

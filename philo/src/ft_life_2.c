/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:28:01 by sasha             #+#    #+#             */
/*   Updated: 2023/02/07 10:44:34 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	all the function here return 1 when stop = 1 or the loop should end
*/

int	ft_think(t_philo *philo, t_table *table)
{
	long			time;

	pthread_mutex_lock(philo->stop_lock);
	if (table->stop == 1)
	{
		pthread_mutex_unlock(philo->stop_lock);
		return (1);
	}
	time = ft_get_time(table->start_time);
	printf("%lu %u is thinking\n", time, philo->num);
	pthread_mutex_unlock(philo->stop_lock);
	if (table->time_to_eat >= table->time_to_sleep && table->philo_num % 2)
		ft_usleep(table->time_to_eat - table->time_to_sleep + 1, table);
	return (0);
}

int	ft_eat(t_philo *philo, t_table *table)
{
	long	time;

	pthread_mutex_lock(philo->stop_lock);
	if (table->stop == 1)
	{
		pthread_mutex_unlock(philo->stop_lock);
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		return (1);
	}
	time = ft_get_time(table->start_time);
	printf("%lu %u is eating\n", time, philo->num);
	pthread_mutex_unlock(philo->stop_lock);
	pthread_mutex_lock(philo->meal_lock);
	philo->meal_eaten++;
	philo->last_meal_time = time;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(table->time_to_eat, table);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (0);
}

int	ft_get_fork1(t_philo *philo, t_table *table)
{
	long	time;

	pthread_mutex_lock(philo->fork1);
	time = ft_get_time(table->start_time);
	pthread_mutex_lock(philo->stop_lock);
	if (table->stop == 1)
	{
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->stop_lock);
		return (1);
	}
	printf("%lu %u has taken a fork\n", time, philo->num);
	pthread_mutex_unlock(philo->stop_lock);
	return (0);
}

int	ft_get_fork2(t_philo *philo, t_table *table)
{
	long	time;

	if (philo->fork1 == philo->fork2)
	{
		pthread_mutex_unlock(philo->fork1);
		return (1);
	}
	pthread_mutex_lock(philo->fork2);
	time = ft_get_time(table->start_time);
	pthread_mutex_lock(philo->stop_lock);
	if (table->stop == 1)
	{
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		pthread_mutex_unlock(philo->stop_lock);
		return (1);
	}
	printf("%lu %u has taken a fork\n", time, philo->num);
	pthread_mutex_unlock(philo->stop_lock);
	return (0);
}

int	ft_sleep(t_philo *philo, t_table *table)
{
	long	time;

	pthread_mutex_lock(philo->stop_lock);
	if (table->stop == 1)
	{
		pthread_mutex_unlock(philo->stop_lock);
		return (1);
	}
	time = ft_get_time(table->start_time);
	printf("%lu %u is sleeping\n", time, philo->num);
	pthread_mutex_unlock(philo->stop_lock);
	ft_usleep(table->time_to_sleep, table);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:28:01 by sasha             #+#    #+#             */
/*   Updated: 2023/01/25 16:36:52 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(int num, long start_time, t_mutex *lock[], int *data)
{
	long	time;

	time = ft_get_time(start_time);
	pthread_mutex_lock(lock[PRINT]);
	if (data[STOP])
	{
		pthread_mutex_unlock(lock[PRINT]);
		return (1);
	}
	printf("%lu %u ", time, num);
	printf("is thinking\n");
	pthread_mutex_unlock(lock[PRINT]);
	return (0);
}

int	ft_eat(t_philo *philo, long start_time, t_mutex *lock[], int *data)
{
	int		num;
	long	time;

	num = philo->num;
	pthread_mutex_lock(lock[PRINT]);
	if (data[STOP])
	{
		pthread_mutex_unlock(lock[FORK_L]);
		pthread_mutex_unlock(lock[FORK_R]);
		return (1);
	}
	time = ft_get_time(start_time);
	printf("%lu %u ", time, num);
	printf("is eating\n");
	pthread_mutex_unlock(lock[PRINT]);
	philo->meal_eaten++;
	philo->last_meal_time = time;
	ft_usleep(data[TIME_TO_EAT], data);
	pthread_mutex_unlock(lock[FORK_L]);
	pthread_mutex_unlock(lock[FORK_R]);
	return (0);
}

int	ft_get_fork_1(int num, long start_time, t_mutex *lock[], int *data)
{
	long	time;

	pthread_mutex_lock(lock[FORK_L]);
	time = ft_get_time(start_time);
	pthread_mutex_lock(lock[PRINT]);
	if (data[STOP])
	{
		pthread_mutex_unlock(lock[FORK_L]);
		pthread_mutex_unlock(lock[PRINT]);
		return (1);
	}
	printf("%lu %u ", time, num);
	printf("has taken a fork\n");
	pthread_mutex_unlock(lock[PRINT]);
	return (0);
}

int	ft_get_fork_2(int num, long start_time, t_mutex *lock[], int *data)
{
	long	time;

	if (lock[FORK_L] == lock[FORK_R])
	{
		pthread_mutex_unlock(lock[FORK_L]);
		return (1);
	}
	pthread_mutex_lock(lock[FORK_R]);
	pthread_mutex_lock(lock[PRINT]);
	time = ft_get_time(start_time);
	if (data[STOP])
	{
		pthread_mutex_unlock(lock[FORK_L]);
		pthread_mutex_unlock(lock[FORK_R]);
		pthread_mutex_unlock(lock[PRINT]);
		return (1);
	}
	printf("%lu %u ", time, num);
	printf("has taken a fork\n");
	pthread_mutex_unlock(lock[PRINT]);
	return (0);
}

int	ft_sleep(int num, long start_time, t_mutex *lock[], int *data)
{
	long	time;

	pthread_mutex_lock(lock[PRINT]);
	time = ft_get_time(start_time);
	if (data[STOP])
	{
		pthread_mutex_unlock(lock[PRINT]);
		return (1);
	}
	printf("%lu %u ", time, num);
	printf("is sleeping\n");
	pthread_mutex_unlock(lock[PRINT]);
	ft_usleep(data[TIME_TO_SLEEP], data);
	return (0);
}

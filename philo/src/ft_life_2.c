/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:28:01 by sasha             #+#    #+#             */
/*   Updated: 2023/01/21 21:56:03 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(int num, long start_time, p_mutex *print)
{
	long	time;

	time = ft_get_time(start_time);
	pthread_mutex_lock(print);
	printf("%lu %u ", time, num);
	printf("is thinking\n");
	pthread_mutex_unlock(print);
}

void	ft_eat(t_philo *philo, long start_time, p_mutex *print, int time_to_eat)
{
	int 	num;
	long	time;

	num = philo->num;
	pthread_mutex_lock(print);
	time = ft_get_time(start_time);
	printf("%lu %u ", time, num);
	printf("is eating\n");
	pthread_mutex_unlock(print);
	philo->meal_eaten++;
	philo->last_meal_time = time;
	ft_usleep(time_to_eat);
}

void	ft_get_fork(int num, long start_time, p_mutex *print, p_mutex *fork)
{
	long	time;

	pthread_mutex_lock(fork);
	time = ft_get_time(start_time);
	pthread_mutex_lock(print);
	printf("%lu %u ", time, num);
	printf("has gotten a fork\n");
	pthread_mutex_unlock(print);
}

void	ft_release_fork(p_mutex *fork1, p_mutex *fork2)
{
	pthread_mutex_unlock(fork1);
	pthread_mutex_unlock(fork2);
}

void	ft_sleep(int num, long start_time, p_mutex *print, int time_to_sleep)
{
	long	time;

	pthread_mutex_lock(print);
	time = ft_get_time(start_time);
	printf("%lu %u ", time, num);
	printf("is sleeping\n");
	pthread_mutex_unlock(print);
	ft_usleep(time_to_sleep);
}

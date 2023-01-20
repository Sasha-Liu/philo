/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:32:02 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/20 16:58:52 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->stop)
		;
	if (philo->num % 2)
		ft_usleep((philo->table->time_to_eat) / 10);
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}

void	ft_think(t_philo *philo)
{
	t_table	*table;
	long	time;
	int		num;

	table = philo->table;
	time = ft_get_time(table);
	num = philo->num;
	pthread_mutex_lock(&(table->print));
	printf("%lu %u ", time, num);
	printf("is thinking\n");
	pthread_mutex_unlock(&(table->print));
}

void	ft_eat(t_philo *philo)
{
	t_table	*table;
	int		num;
	long	time;

	table = philo->table;
	num = philo->num;
	ft_get_fork(philo);
	time = ft_get_time(table);
	pthread_mutex_lock(&(table->print));
	printf("%lu %u ", time, num);
	printf("is eating\n");
	pthread_mutex_unlock(&(table->print));
	philo->meal_eaten++;
	philo->last_meal_time = time;
	ft_usleep(table->time_to_eat);
	pthread_mutex_unlock(table->fork + num);
	pthread_mutex_unlock(table->fork + (num + 1) % table->philo_num);
}

void	ft_get_fork(t_philo *philo)
{
	t_table	*table;
	int		num;
	long	time;

	table = philo->table;
	num = philo->num;
	pthread_mutex_lock(table->fork + num);
	time = ft_get_time(table);
	pthread_mutex_lock(&(table->print));
	printf("%lu %u ", time, num);
	printf("has gotten a fork\n");
	pthread_mutex_unlock(&(table->print));
	pthread_mutex_lock(table->fork + (num + 1) % table->philo_num);
	time = ft_get_time(table);
	pthread_mutex_lock(&(table->print));
	printf("%lu %u ", time, num);
	printf("has gotten a fork\n");
	pthread_mutex_unlock(&(table->print));
}

void	ft_sleep(t_philo *philo)
{
	t_table	*table;
	long	time;

	table = philo->table;
	time = ft_get_time(table);
	pthread_mutex_lock(&(table->print));
	printf("%lu %u ", time, philo->num);
	printf("is sleeping\n");
	pthread_mutex_unlock(&(table->print));
	ft_usleep(table->time_to_sleep);
}
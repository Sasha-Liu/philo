/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:50:37 by sasha             #+#    #+#             */
/*   Updated: 2023/01/21 12:30:57 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	main thread lock stop
*/
int	ft_init(t_table *table, int argc, char **argv)
{
	ft_init_table(table, argc, argv);
	if (ft_init_mutex(table))
	{
		write(2, "pthread_mutex_init fails\n", 25);
		return (1);
	}
	ft_init_philo(table);
	pthread_mutex_lock(table->stop_lock);
	return (0);
}

void	ft_init_table(t_table *table, int argc, char **argv)
{
	int	n;
	
	table->philo_num = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->meal_num = -1;
	table->stop = 0;
	if (argc == 6)
		table->meal_num = ft_atoi(argv[5]);
	n = table->philo_num;
	table->print_lock = &(table->lock[n]);
	table->stop_lock = &(table->lock[n + 1]);
}

void	ft_init_philo(t_table *table)
{
	int		i;
	int		n;
	t_philo	*philo;

	i = 0;
	n = table->philo_num;
	philo = table->philo;
	while (i < n)
	{
		philo[i].num = i;
		philo[i].meal_eaten = 0;
		philo[i].stop = (&(table->stop));
		philo[i].last_meal_time = 0;
		philo[i].fork1 = &(table->lock[i]); 
		philo[i].fork2 = &(table->lock[(i + 1) % n]);
		philo[i].print_lock = &(table->lock[n]);
		philo[i].stop_lock = &(table->lock[n + 1]);
		philo[i].table = table;
		i++;
	}
}

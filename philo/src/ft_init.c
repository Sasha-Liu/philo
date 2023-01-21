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

int	ft_init(t_table *table, int argc, char **argv)
{
	ft_init_table(table, argc, argv);
	ft_init_philo(table);
	if (ft_init_mutex(table))
	{
		write(2, "pthread_mutex_init fails\n", 25);
		return (1);
	}
	return (0);
}

void	ft_init_table(t_table *table, int argc, char **argv)
{
	table->data[PHILO_NUM] = ft_atoi(argv[1]);
	table->data[TIME_TO_DIE] = ft_atoi(argv[2]);
	table->data[TIME_TO_EAT] = ft_atoi(argv[3]);
	table->data[TIME_TO_SLEEP] = ft_atoi(argv[4]);
	table->data[MEAL_NUM] = -1;
	if (argc == 6)
		table->data[MEAL_NUM] = ft_atoi(argv[5]);
	table->data[STOP] = 1;
}

void	ft_init_philo(t_table *table)
{
	int		i;
	int		n;
	t_philo	*philo;

	i = 0;
	n = table->data[PHILO_NUM];
	philo = table->philo;
	while (i < n)
	{
		philo[i].num = i;
		philo[i].meal_eaten = 0;
		philo[i].last_meal_time = 0;
		philo[i].table = table;
		i++;
	}
}

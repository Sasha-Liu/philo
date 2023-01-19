/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:50:37 by sasha             #+#    #+#             */
/*   Updated: 2023/01/19 21:20:51 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*ft_init(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philo;

	table = ft_init_table(argc, argv);
	if (table == NULL)
	{
		return (NULL);
	}
	if (ft_init_mutex(table))
	{
		free(table)
		return (NULL);
	}
	philo = ft_init_philo(table);
	if (philo == NULL)
	{
		free(table);
		return (NULL);
	}
	table->philo = philo;
	philo->table = table;
	return (table);
}

t_table *ft_init_table(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
	{
		write(2, "malloc fails\n", 13);
		return (NULL);
	}
	table->philo_num = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->meal_num = -1;
	if (argc == 6)
		table->meal_num = ft_atoi(argv[5]);
	table->stop = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * table->philo_num);
	if (table->fork == NULL)
	{
		write(2, "malloc fails\n", 13);
		free(table);
		return (1);
	}
	return (table);
}

int	ft_init_mutex(t_table *table)
{
	unsigned int	i;
	unsigned int	n;
	
	i = 0;
	n = table->philo_num;
	if (pthread_mutex_init(table->print, NULL) != 0)
	{
		write(2, "pthread_mutex_init fails\n", 26);
		return (1);
	}
	while (i < n)
	{
		if (pthread_mutex_init(*(table->fork + i), NULL) != 0)
		{
			while (i != 0)
			{
				pthread_mutex_destroy(*(table->fork + i));
				i--;
			}
			write(2, "pthread_mutex_init fails\n", 26);
			return (1);
		}
		i++;
	}
	return (0);
}

t_philo	*ft_init_philo(t_table *table)
{
	unsigned int	i;
	unsigned int	n;
	t_philo			*philo;

	i = 0;
	n = table->philo_num;
	philo = malloc(sizeof(t_philo) * n);
	if (philo == NULL)
	{
		write(2, "malloc fails\n", 13);
		return (NULL);
	}
	while (i < n)
	{
		philo[i].num = i;
		philo[i].meal_eaten = 0;
		philo[i].last_meal_time = 0;
		i++;
	}
	return (philo);
}

void	ft_free(t_table **table)
{
	free(*table->philo);
	*table->philo = NULL;
	free(*table);
	*table = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:23:08 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/06 22:18:48 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*ft_malloc(int philo_num)
{
	t_table			*table;
	t_philo			*philo;
	pthread_mutex_t	*lock;

	table = malloc(sizeof(t_table));
	philo = malloc(sizeof(t_philo) * philo_num);
	lock = malloc(sizeof(pthread_mutex_t) * (philo_num * 2 + 1));
	if (table == NULL || philo == NULL || lock == NULL)
	{
		free(table);
		free(philo);
		free(lock);
		write(2, "malloc fails\n", 13);
		return (NULL);
	}
	table->philo = philo;
	table->lock = lock;
	return (table);
}

/*
	free resources
*/
void	ft_free(t_table **table)
{
	free((*table)->philo);
	(*table)->philo = NULL;
	free((*table)->lock);
	(*table)->lock = NULL;
	free(*table);
	*table = NULL;
}

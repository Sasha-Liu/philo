/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:23:08 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/20 11:20:25 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*ft_malloc(unsigned int philo_num)
{
	t_table			*table;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	unsigned int	i;

	table = malloc(sizeof(t_table));
	philo = malloc(sizeof(t_philo) * philo_num);
	fork = malloc(sizeof(pthread_mutex_t) * philo_num);
	if (table == NULL || philo == NULL || fork == NULL)
	{
		free(table);
		free(philo);
		free(fork);
		write(2, "malloc fails\n", 13);
		return (NULL);
	}
	table->philo = philo;
	return (table);
}

//free resources
void	ft_free(t_table **table)
{
	free((*table)->philo);
	free((*table)->fork);
	(*table)->philo = NULL;
	(*table)->fork = NULL;
	free(*table);
	*table = NULL;
}

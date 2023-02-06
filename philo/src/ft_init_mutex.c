/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:06:29 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/25 15:04:27 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_table *table)
{
	int	i;
	int	n;

	i = 0;
	n = table->philo_num * 2 + 1;
	while (i < n)
	{
		if (pthread_mutex_init(&(table->lock[i]), NULL))
		{
			while (i != 0)
			{
				pthread_mutex_destroy(&(table->lock[i]));
				i--;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_destroy_mutex(t_table *table)
{
	int	i;
	int	n;

	i = 0;
	n = table->philo_num * 2 + 1;
	while (i < n)
	{
		if (pthread_mutex_destroy(&(table->lock[i])))
		{
			write(2, "pthread_mutex_destroy fails\n", 28);
		}
		i++;
	}
	return (0);
}

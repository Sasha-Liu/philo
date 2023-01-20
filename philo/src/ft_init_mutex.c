/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:06:29 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/20 11:10:41 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_table *table)
{
	unsigned int	i;
	unsigned int	n;
	
	i = 0;
	n = table->philo_num;
	if (pthread_mutex_init(&(table->print), NULL))
	{
		return (1);
	}
	while (i < n)
	{
		if (pthread_mutex_init(table->fork + i, NULL))
		{
			while (i != 0)
			{
				pthread_mutex_destroy(table->fork + i);
				i--;
			}
			pthread_mutex_destroy(&(table->print));
			return (1);
		}
		i++;
	}
	return (0);
}

int ft_destroy_mutex(t_table *table)
{
    unsigned int	i;
	unsigned int	n;
    int             err;
	
	i = 0;
	n = table->philo_num;
    err = 0;
    if (pthread_mutex_destroy(&(table->print)))
    {
        err = 1;
    }
    while (i < n)
    {
        if (pthread_mutex_destroy(table->fork + i))
            err = 1;
        i++;
    }
    if (err)
    {
        write(2, "pthread_mutex_destroy fails\n", 28);
    }
    return (err);
}

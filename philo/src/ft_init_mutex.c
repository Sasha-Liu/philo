/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:06:29 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/23 17:39:32 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//#include <errno.h>

int	ft_init_mutex(t_table *table)
{
	int	i;
	int	n;
	
	i = 0;
	n = table->data[PHILO_NUM];
	while (i <= n)
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

int ft_destroy_mutex(t_table *table)
{
    int	i;
	int	n;
    int	err;
	
	i = 0;
	n = table->data[PHILO_NUM];
    err = 0;
    while (i <= n)
    {
        if (pthread_mutex_destroy(&(table->lock[i])))
		{
			err = 1;
			//perror("pthread_mutex_destroy");	
		}
        i++;
    }
	/*if (err)
	{
		write(2, "pthread_mutex_destroy fails\n", 28);
	}*/
    return (err);
}

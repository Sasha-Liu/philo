/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:38:43 by sasha             #+#    #+#             */
/*   Updated: 2023/01/20 11:21:35 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//if all goes well return 0
//else (thread creation fails) return 1
int	ft_create_thread(t_table *table, t_philo *philo)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = table->philo_num;
	table->start_time = ft_set_time();
	while (i < n)
	{
		if (pthread_create(&(philo[i].tid), NULL, ft_routine, &(philo[i])))
		{
			write(2, "pthread_create fails\n", 21);
			//table->stop = 1;
			return (1);
		}
		i++;
	}
}

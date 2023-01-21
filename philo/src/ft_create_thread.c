/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:38:43 by sasha             #+#    #+#             */
/*   Updated: 2023/01/21 12:39:26 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//if all goes well return 0
//else (thread creation fails) return 1
//pthread_detach error is not protected 
//(since all resoucre return to systen after main exit) 
int	ft_create_thread(t_table *table, t_philo *philo)
{
	int	i;
	int	n;

	i = 0;
	n = table->data[PHILO_NUM];
	while (i < n)
	{
		if (pthread_create(&(philo[i].tid), NULL, ft_life, &(philo[i])))
		{
			write(2, "pthread_create fails\n", 21);
			return (1);
		}
		pthread_detach(philo[i].tid);
		i++;
	}
	return (0);
}

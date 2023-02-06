/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:38:43 by sasha             #+#    #+#             */
/*   Updated: 2023/01/25 15:09:16 by hsliu            ###   ########.fr       */
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
	n = table->philo_num;
	while (i < n)
	{
		if (pthread_create(&(philo[i].tid), NULL, ft_life, &(philo[i])))
		{
			write(2, "pthread_create fails\n", 21);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_thread_join(t_table *table, t_philo *philo)
{
	int		i;
	void	*ret;

	i = 0;
	while (i < table->philo_num)
	{
		pthread_join(philo[i].tid, &ret);
		i++;
	}
}

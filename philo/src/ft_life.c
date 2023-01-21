/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:03:11 by sasha             #+#    #+#             */
/*   Updated: 2023/01/21 14:12:31 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
 void	*ft_life(void *arg)
{
	t_philo	*philo;
	int		num;
	int		*data;
	long	*start_time;
	p_mutex	*lock;
	
	philo = (t_philo *)arg;
	num = philo->num;
	data = philo->table->data;
	start_time = &(philo->table->start_time);
	lock = philo->table->lock;
	while (philo->table->data[STOP])
		;
	if (philo->num % 2)
		ft_usleep((philo->table->data[TIME_TO_EAT]));
	while (1)
	{
		ft_get_fork(num, *start_time, &(lock[data[PHILO_NUM]]), &(lock[num]));
		ft_get_fork(num, *start_time, &(lock[data[PHILO_NUM]]), &(lock[(num + 1) % data[PHILO_NUM]]));
		ft_eat(philo, *start_time, &(lock[data[PHILO_NUM]]), data[TIME_TO_EAT]);
		ft_release_fork(&(lock[num]), &(lock[(num + 1) % data[PHILO_NUM]]));
		ft_sleep(num, *start_time, &(lock[data[PHILO_NUM]]), data[TIME_TO_SLEEP]);
		ft_think(num, *start_time, &(lock[data[PHILO_NUM]]));
	}
	return (0);
}

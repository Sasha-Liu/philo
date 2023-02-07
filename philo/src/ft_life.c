/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:03:11 by sasha             #+#    #+#             */
/*   Updated: 2023/02/07 11:08:54 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_life(void *arg)
{
	t_philo				*philo;
	long unsigned int	time;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->stop_lock);
	pthread_mutex_unlock(philo->stop_lock);
	time = ft_get_time(philo->table->start_time);
	printf("%lu %u is thinking\n", time, philo->num);
	if (philo->num % 2)
		ft_usleep(philo->table->time_to_eat, philo->table);
	while (1)
	{
		if (ft_get_fork1(philo, philo->table))
			break ;
		if (ft_get_fork2(philo, philo->table))
			break ;
		ft_eat(philo, philo->table);
		ft_sleep(philo, philo->table);
		ft_think(philo, philo->table);
	}
	return (0);
}

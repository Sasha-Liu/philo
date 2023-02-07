/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:03:11 by sasha             #+#    #+#             */
/*   Updated: 2023/02/07 10:47:34 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_life(void *arg)
{
	t_philo				*philo;
	long unsigned int	time;
	/*t_philo	*philo_l;
	t_philo	*philo_r;*/

	philo = (t_philo *)arg;
	/*philo_l = &(philo->table->philo[(philo->num - 1) % philo->table->philo_num]);
	philo_r = &(philo->table->philo[(philo->num + 1) % philo->table->philo_num]);*/
	pthread_mutex_lock(philo->stop_lock);
	pthread_mutex_unlock(philo->stop_lock);
	time = ft_get_time(philo->table->start_time);
	printf("%lu %u is thinking\n", time, philo->num);
	if (philo->num % 2)
		ft_usleep(philo->table->time_to_eat, philo->table);
	while (1)
	{
		/*while (ft_neighbor_are_both_eating(philo_l, philo_r))
			;*/
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

/*
int	ft_neighbor_are_both_eating(t_philo *philo_l, t_philo *philo_r)
{
	int	res1;
	int	res2;

	pthread_mutex_lock(philo_l->eat_lock);
	if (philo_l->eat == 1)
		res1 = 1;
	else
		res1 = 0;
	pthread_mutex_unlock(philo_l->eat_lock);
	pthread_mutex_lock(philo_r->eat_lock);
	if (philo_r->eat == 1)
		res2 = 1;
	else
		res2 = 0;
	pthread_mutex_unlock(philo_r->eat_lock);
	if (res1 == 1 && res2 == 1)
		return (1);
	return (0);
}
*/
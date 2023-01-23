/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:03:11 by sasha             #+#    #+#             */
/*   Updated: 2023/01/23 17:27:12 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
void	*ft_life(void *arg)
{
	t_philo	*philo;
	int		num;
	int		*data;
	long	*start_time;
	p_mutex	*lock[3];
	
	philo = (t_philo *)arg;
	num = ft_init_life(philo, &data, &start_time, lock);
	while (data[STOP])
		;
	if (num % 2)
		ft_usleep(data[TIME_TO_EAT]);
	while (1)
	{
		ft_get_fork(num, *start_time, lock[PRINT], lock[FORK_L]);
		ft_get_fork(num, *start_time, lock[PRINT], lock[FORK_R]);
		ft_eat(philo, *start_time, lock[PRINT], data[TIME_TO_EAT]);
		ft_release_fork(lock[FORK_L], lock[FORK_R]);
		ft_sleep(num, *start_time, lock[PRINT], data[TIME_TO_SLEEP]);
		ft_think(num, *start_time, lock[PRINT]);
	}
	return (0);
}

int	ft_init_life(t_philo *philo, int **data, long **start, p_mutex *lock[])
{
	int	num;
	int	philo_num;
	
	*data = philo->table->data;
	*start = &(philo->table->start_time);
	num = philo->num;
	philo_num = (*data)[PHILO_NUM];
	lock[PRINT] = &(philo->table->lock[philo_num]);
	lock[FORK_L] = &(philo->table->lock[num]);
	lock[FORK_R] = &(philo->table->lock[(num + 1) % philo_num]);
	return (num);
}

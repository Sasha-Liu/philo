/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:03:11 by sasha             #+#    #+#             */
/*   Updated: 2023/01/25 15:05:25 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_life(void *arg)
{
	t_philo	*philo;
	int		num;
	int		*data;
	long	*start_time;
	t_mutex	*lock[3];

	philo = (t_philo *)arg;
	num = ft_init_life(philo, &data, &start_time, lock);
	while (data[STOP])
		;
	if (num % 2)
		ft_usleep(data[TIME_TO_EAT], data);
	while (!data[STOP])
	{
		if (ft_get_fork_1(num, *start_time, lock, data))
			break ;
		if (ft_get_fork_2(num, *start_time, lock, data))
			break ;
		ft_eat(philo, *start_time, lock, data);
		ft_sleep(num, *start_time, lock, data);
		ft_think(num, *start_time, lock, data);
	}
	return (0);
}

int	ft_init_life(t_philo *philo, int **data, long **start, t_mutex *lock[])
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

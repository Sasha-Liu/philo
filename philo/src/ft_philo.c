/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:03:11 by sasha             #+#    #+#             */
/*   Updated: 2023/01/21 12:40:05 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//locks[0 - 2] = print , fork1, fork2
//data[] = num, philo_num, 
 void	*ft_life(void *arg)
{
	t_philo			*philo;
	int				num;
	unsigned int	philo_num;
	pthread_mutex_t *fork;
	pthread_mutex_t *print;

	philo = (t_philo *)arg;
	num = philo->num;
	philo_num = philo->table->philo_num;
	fork = philo->table->fork;
	print = &(philo->table->print);
	while (philo->table->stop)
		;
	if (philo->num % 2)
		ft_usleep((philo->table->time_to_eat) / 10);
	while (1)
	{
		ft_get_fork();
		ft_eat(fork, num, philo_num);
		ft_usleep();
		ft_sleep(philo);
		ft_usleep();
		ft_think(philo);
	}
	return (0);
}

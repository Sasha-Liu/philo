/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:59:46 by sasha             #+#    #+#             */
/*   Updated: 2023/01/25 15:05:25 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//set start time
//set stop = 0
//count meals eaten
//check if someone's dead
//if stop=TRUE, then lock print
void	ft_loop(t_table *table, t_philo *philo, int *data)
{
	int		i;
	int		full;
	long	start_time;
	t_mutex	*print;

	usleep(2000000);
	print = &(table->lock[data[PHILO_NUM]]);
	table->start_time = ft_set_time();
	table->data[STOP] = 0;
	start_time = table->start_time;
	while (1)
	{
		i = 0;
		full = 0;
		while (i < data[PHILO_NUM])
		{
			if (ft_is_dead(philo + i, start_time, data, print))
				return ;
			if (ft_all_is_full(philo + i, &full, data))
				return ;
			i++;
		}
	}
}

int	ft_is_dead(t_philo *philo, long start_time, int *data, t_mutex *print)
{
	long	time;

	time = ft_get_time(start_time);
	if (philo->last_meal_time + 1000 * data[TIME_TO_DIE] < time)
	{
		data[STOP] = 1;
		pthread_mutex_lock(print);
		printf("%lu %d died\n", time, philo->num);
		pthread_mutex_unlock(print);
		return (1);
	}
	return (0);
}

int	ft_all_is_full(t_philo *philo, int *full, int *data)
{
	if (data[MEAL_NUM] == -1)
		return (0);
	if (philo->meal_eaten >= data[MEAL_NUM])
	{
		(*full)++;
	}
	if (*full == data[PHILO_NUM])
	{
		data[STOP] = 1;
		return (1);
	}
	return (0);
}

void	ft_thread_join(t_table *table, t_philo *philo)
{
	int		i;
	void	*ret;

	i = 0;
	while (i < table->data[PHILO_NUM])
	{
		pthread_join(philo[i].tid, &ret);
		i++;
	}
}

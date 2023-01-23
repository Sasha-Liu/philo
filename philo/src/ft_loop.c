/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:59:46 by sasha             #+#    #+#             */
/*   Updated: 2023/01/23 17:46:53 by sasha            ###   ########.fr       */
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
	p_mutex	*print;

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
			if (ft_all_is_full(philo + i, &full, data, print))
				return ;
			i++;
		}
	}
}

int	ft_is_dead(t_philo *philo, long start_time, int *data, p_mutex *print)
{
	long	time;
	
	time = ft_get_time(start_time);
	if (philo->last_meal_time + 1000 * data[TIME_TO_DIE] < time)
	{
		pthread_mutex_lock(print);
		data[STOP] = 1;
		printf("%lu %d died\n", time, philo->num);
		return (1);
	}
	return (0);
}

int	ft_all_is_full(t_philo *philo, int *full, int *data, p_mutex *print)
{
	if (data[MEAL_NUM] == -1)
		return (0);
	if (philo->meal_eaten >= data[MEAL_NUM])
	{
		(*full)++;
	}
	if (*full == data[PHILO_NUM])
	{
		pthread_mutex_lock(print);
		data[STOP] = 1;
		return (1);
	}
	return (0);
}
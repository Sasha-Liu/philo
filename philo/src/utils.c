/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:46:46 by sasha             #+#    #+#             */
/*   Updated: 2023/01/20 16:43:25 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//return time in millisecond
//use to set the starting time 
long	ft_set_time(void)
{
    struct	timeval	tv;
    long	cur_time;

	gettimeofday(&tv, NULL);
    cur_time = tv.tv_sec * 1000000 + tv.tv_usec;
	return (cur_time / 1000);
}

long	ft_get_time(t_table *table)
{
	long	start_time;
	long	curr_time;

	start_time = table->start_time;
	curr_time = ft_set_time();
	return (curr_time - start_time);
}

unsigned int	ft_atoi(char *num)
{
	unsigned int	sum;

	sum = 0;
	while (*num == ' ' || *num == '+')
		num++;
	while (*num >= '0' && *num <= '9')
	{
		sum += *num - '0';
		num++;
	}
	return (sum);
}

int	ft_usleep(unsigned int sec)
{
	unsigned int	usec;

	usec = sec * 1000000;
	while (usec > 0)
	{
		if (usleep(1000))
		{
			write(2, "usleep fails\n", 13);
			return (1);
		}
		usec -= 1000;
	}
	return (0);
}

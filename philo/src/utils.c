/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:46:46 by sasha             #+#    #+#             */
/*   Updated: 2023/01/26 13:53:05 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//return time in millisecond
//use to set the starting time 
long	ft_set_time(void)
{
	struct timeval	tv;
	long			cur_time;

	gettimeofday(&tv, NULL);
	cur_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (cur_time);
}

long	ft_get_time(long start_time)
{
	long	curr_time;

	curr_time = ft_set_time();
	return (curr_time - start_time);
}

int	ft_atoi(char *num)
{
	int	sum;

	sum = 0;
	while (*num == ' ' || *num == '+')
		num++;
	while (*num >= '0' && *num <= '9')
	{
		sum = sum * 10 + (*num) - '0';
		num++;
	}
	return (sum);
}

//usleep take microsec as arg (10^-6)
//start and now is milli sec
int	ft_usleep(unsigned int millisec, int *data)
{
	long			start;
	long			now;

	now = 0;
	start = ft_set_time();
	while (millisec > now + 1000)
	{
		if (data[STOP])
			return (0);
		if (usleep(1000000))
		{
			write(2, "usleep fails\n", 13);
			return (1);
		}
		now = ft_get_time(start);
	}
	if (millisec > now)
		usleep((millisec - (unsigned int)now) * 1000);
	return (0);
}

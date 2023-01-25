/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:26 by sasha             #+#    #+#             */
/*   Updated: 2023/01/25 11:17:21 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_table	*table;
	
	if (ft_check_input(argc, argv))
	{
		return (0);
	}
	table = ft_malloc(ft_atoi(argv[1]));
	if (table == NULL)
	{
		return (0);
	}
	if (ft_init(table, argc, argv))
	{
		return (0);
	}
    if (ft_create_thread(table, table->philo))
	{
		return (0);
	}
	//supervise
	ft_usleep(5);
	ft_loop(table, table->philo, table->data);
	//table->start_time = ft_set_time();
	//table->data[STOP] = 0;
	//ft_usleep(1);
	//supervise
	ft_destroy_mutex(table);
	ft_free(&table);
}
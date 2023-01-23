/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:26 by sasha             #+#    #+#             */
/*   Updated: 2023/01/23 17:56:56 by sasha            ###   ########.fr       */
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
	int *data = table->data;
	printf("%d %d %d %d %d %d\n", data[0], data[1], data[2], data[3], data[4], data[5]);
	ft_loop(table, table->philo, table->data);
	//table->start_time = ft_set_time();
	//table->data[STOP] = 0;
	//ft_usleep(1);
	//supervise
	ft_destroy_mutex(table);
	ft_free(&table);
}
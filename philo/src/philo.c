/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:26 by sasha             #+#    #+#             */
/*   Updated: 2023/01/20 16:44:19 by hsliu            ###   ########.fr       */
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
	table->start_time = ft_set_time();
	table->stop = 0;
	while(1);
	//supervise
	ft_destroy_mutex(table);
	ft_free(&table);
}
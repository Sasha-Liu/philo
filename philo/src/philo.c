/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:26 by sasha             #+#    #+#             */
/*   Updated: 2023/01/20 11:20:58 by hsliu            ###   ########.fr       */
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
    
    //create thread
    //supervise
    ft_destroy_mutex(table);
	ft_free(&table);
}
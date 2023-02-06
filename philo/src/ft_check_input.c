/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:03:28 by sasha             #+#    #+#             */
/*   Updated: 2023/01/25 14:57:18 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
	if error return 1
	else return 0
*/
int	ft_check_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_is_num(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
	if it's a non negative number, return 1
	else return 0
	doesn't check overflow / underflow
*/
int	ft_is_num(char *num)
{
	while (*num == ' ')
		num++;
	if (*num == '\0' || *num == '-')
		return (0);
	if (*num == '+')
		num++;
	while (*num >= '0' && *num <= '9')
		num++;
	if (*num == '\0')
		return (1);
	return (0);
}

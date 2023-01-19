/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasha <sasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:30 by sasha             #+#    #+#             */
/*   Updated: 2023/01/19 21:02:50 by sasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h> 
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo t_philo;
typedef struct s_table t_table;

typedef struct s_table{
	unsigned int	philo_num;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				meal_num;
	long			start_time;
	int				stop;
	pthread_mutex_t print;
	pthread_mutex_t *fork;
	t_philo			*philo;
} t_table;

typedef struct s_philo{
	pthread_t		tid;
	int				num;
	int				meal_eaten;
	long			last_meal_time;
	t_table			*table;
} t_philo;

/**********  ft_check_input.c  **********/
int 			ft_check_input(int argc, char **argv);
int 			ft_is_num(char *num);

/**********  ft_init.c  **********/
t_table			*ft_init(int argc, char **argv);
t_table 		*ft_init_table(int argc, char **argv);
t_philo			*ft_init_philo(t_table *table);
void			ft_free(t_table **table);
unsigned int	ft_atoi(char *num);

/**********  utils.c  **********/
unsigned int	ft_atoi(char *num);
long			ft_set_time(void);
long			ft_get_time(t_table *table);

#endif
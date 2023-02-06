/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:33:30 by sasha             #+#    #+#             */
/*   Updated: 2023/01/25 15:09:25 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h> 
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mutex;

typedef struct s_table{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_num;
	int				stop;
	long			start_time;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*stop_lock;
	t_philo			*philo;
}	t_table;

typedef struct s_philo{
	pthread_t		tid;
	int				num;
	int				meal_eaten;
	int				*stop;
	long			last_meal_time;
	pthread_mutex_t	*fork1;	
	pthread_mutex_t	*fork2;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*stop_lock;
	t_table			*table;
}	t_philo;

/**********  ft_check_input.c  **********/
int		ft_check_input(int argc, char **argv);
int		ft_is_num(char *num);

/**********  ft_malloc.c  **********/
t_table	*ft_malloc(int philo_num);
void	ft_free(t_table **table);

/**********  ft_init.c  **********/
int		ft_init(t_table *table, int argc, char **argv);
void	ft_init_table(t_table *table, int argc, char **argv);
void	ft_init_philo(t_table *table);

/**********  ft_init_mutex.c  **********/
int		ft_init_mutex(t_table *table);
int		ft_destroy_mutex(t_table *table);

/**********  ft_create_thread.c  **********/
int		ft_create_thread(t_table *table, t_philo *philo);
void	ft_thread_join(t_table *table, t_philo *philo);

/**********  ft_life.c  **********/
void	*ft_life(void *arg);

/**********  ft_life_2.c  **********/
int		ft_think(t_philo *philo, t_table *table);
int		ft_eat(t_philo *philo, t_table *table);
int		ft_get_fork1(t_philo *philo, t_table *table);
int		ft_get_fork2(t_philo *philo, t_table *table);
int		ft_sleep(t_philo *philo, t_table *table);

/**********  ft_loop.c  **********/
void	ft_loop(t_table *table, t_philo *philo);
int		ft_is_dead(t_philo *philo, t_table *table);
int		ft_all_is_full(t_philo *philo, int *full, t_table *table);

/**********  utils.c  **********/
int		ft_atoi(char *num);
long	ft_set_time(void);
long	ft_get_time(long start_time);
int		ft_usleep(unsigned int sec, t_table *table);

#endif
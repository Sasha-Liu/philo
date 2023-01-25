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

# define PHILO_NUM 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define MEAL_NUM 4
# define STOP 5
# define PRINT 0
# define FORK_L 1
# define FORK_R 2

typedef struct s_table{
	int				data[6];
	long			start_time;
	pthread_mutex_t	*lock;
	t_philo			*philo;
}	t_table;

typedef struct s_philo{
	pthread_t		tid;
	int				num;
	int				meal_eaten;
	long			last_meal_time;
	t_table			*table;
}	t_philo;

/**********  ft_check_input.c  **********/
int		ft_check_input(int argc, char **argv);
int		ft_is_num(char *num);

/**********  ft_malloc.c  **********/
t_table	*ft_malloc(unsigned int philo_num);
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
int		ft_init_life(t_philo *philo, int **data, long **start, t_mutex *lock[]);

/**********  ft_life_2.c  **********/
int		ft_think(int num, long start_time, t_mutex *lock[], int *data);
int		ft_eat(t_philo *philo, long start_time, t_mutex *lock[], int *data);
int		ft_get_fork_1(int num, long start_time, t_mutex *lock[], int *data);
int		ft_get_fork_2(int num, long start_time, t_mutex *lock[], int *data);
int		ft_sleep(int num, long start_time, t_mutex *lock[], int *data);

/**********  ft_loop.c  **********/
void	ft_loop(t_table *table, t_philo *philo, int *data);
int		ft_is_dead(t_philo *philo, long start_time, int *data, t_mutex *print);
int		ft_all_is_full(t_philo *philo, int *full, int *data);

/**********  utils.c  **********/
int		ft_atoi(char *num);
long	ft_set_time(void);
long	ft_get_time(long start_time);
int		ft_usleep(unsigned int sec, int *data);

#endif
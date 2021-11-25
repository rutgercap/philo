/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 09:05:02 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/19 10:38:06 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libc.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include "utils/utils.h"

# define NOT_SET -1
# define STOP -1

# define DEAD 1
# define FULL 2

# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define FORK "has taken a fork"

typedef pthread_mutex_t	t_fork;

enum e_forks
{
	LEFT,
	RIGHT
};

typedef struct s_rules
{
	pthread_mutex_t	write_mut;
	int64_t			die_time;
	int64_t			eat_time;
	int64_t			sleep_time;
	int64_t			start_time;
	int				eat_n;
}	t_rules;

typedef struct s_philo
{
	pthread_mutex_t	data_mutex;
	int64_t			last_eaten;
	t_rules			*rules;
	t_fork			*forks[2];
	int				times_eaten;
	int				id;
}	t_philo;

int		arg_lexing(t_rules *rules, int *philos_n, int argc, char **argv);

int		setup_forks(t_fork **forks_ref, const int forks_n);

int		setup_philos(t_philo **philos, const int philos_n, \
		t_fork *forks, t_rules *rules);

void	*philo_life(void *arg);

int		food_time(t_philo *philos, int philos_n, t_rules *rules);

// utils

int		exit_error(char *msg, int philos_n, t_fork *forks, t_philo *philos);

int		write_error(char *msg);

void	destroy_forks(int forks_n, t_fork *forks);

int		exit_correct(int forks_n, t_fork *forks, t_philo *philos);

int64_t	get_time(void);

int64_t	time_since_start(t_rules *rules);

void    smart_sleep(int64_t ms);

void	print_action(t_philo *philo, char *msg);

#endif

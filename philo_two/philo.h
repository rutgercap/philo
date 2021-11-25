/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 09:05:02 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/25 12:24:26 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libc.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <sys/sem.h>
# include <semaphore.h>
# include <pthread.h>
# include <fcntl.h>
# include "utils/utils.h"

# define NOT_SET -1
# define STOP -1

# define DEAD 1
# define FULL 2

# define CHILD 0

# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define FORK "has taken a fork"

// # define KEY 0x1111

typedef struct s_rules
{
	int64_t	die_time;
	int64_t	eat_time;
	int64_t	sleep_time;
	int64_t	start_time;
	sem_t	*write_sem;
	sem_t	*fork_sem;
	sem_t	*dead_sem;
	int		eat_n;
	int		philos_n;
}	t_rules;

typedef struct s_philo
{
	int			id;
	t_rules		*rules;
	int64_t		last_eaten;
	int			times_eaten;
}	t_philo;

void	arg_lexing(t_rules *rules, int argc, char **argv);

void	setup_sems(t_rules *rules);

void	philo_life(t_philo *philo);

void	*monitor(void *arg);

/*
	utils
*/

int		exit_error(char *msg);

int64_t	get_time(void);

int64_t	time_since_start(t_rules *rules);

int64_t	print_action(t_philo *philo, char *msg);

void    smart_sleep(int64_t ms);

#endif

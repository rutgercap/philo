/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_life.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 09:47:18 by rcappend      #+#    #+#                 */
/*   Updated: 2022/04/05 14:14:43 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_sleep(t_philo *philo)
{
	if (print_action(philo, SLEEPING))
		return (STOP);
	smart_sleep(philo->rules->sleep_time);
	return (CONTINUE);
}

static int	get_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(fork);
	if (print_action(philo, FORK))
	{
		pthread_mutex_unlock(fork);
		return (STOP);
	}
	return (CONTINUE);
}

static int	philo_eat(t_philo *philo)
{
	if (get_fork(philo, philo->forks[LEFT]))
		return (STOP);
	if (get_fork(philo, philo->forks[RIGHT]))
	{
		pthread_mutex_unlock(philo->forks[LEFT]);
		return (STOP);
	}
	pthread_mutex_lock(&philo->data_mutex);
	if (print_action(philo, EATING))
	{
		pthread_mutex_unlock(philo->forks[LEFT]);
		pthread_mutex_unlock(philo->forks[RIGHT]);
		return (STOP);
	}
	philo->times_eaten += 1;
	philo->last_eaten = time_since_start(philo->rules);
	pthread_mutex_unlock(&philo->data_mutex);
	smart_sleep(philo->rules->eat_time);
	pthread_mutex_unlock(philo->forks[LEFT]);
	pthread_mutex_unlock(philo->forks[RIGHT]);
	return (CONTINUE);
}

static void	eat_sleep_think_repeat(t_philo *philo)
{
	while (true)
	{
		if (philo_eat(philo))
			return ;
		if (philo->rules->max_eating && \
			philo->times_eaten == philo->rules->eat_n)
			return ;
		if (philo_sleep(philo))
			return ;
		if (print_action(philo, THINKING))
			return ;
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	eat_sleep_think_repeat(philo);
	pthread_mutex_destroy(&philo->data_mutex);
	return (EXIT_SUCCESS);
}

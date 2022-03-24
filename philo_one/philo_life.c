/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_life.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 09:47:18 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/24 16:49:27 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_sleep(t_philo *philo)
{
	if (print_action(philo, SLEEPING))
		return (EXIT_FAILURE);
	smart_sleep(philo->rules->sleep_time);
	return (EXIT_SUCCESS);
}

static int	get_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(fork);
	if (print_action(philo, FORK))
	{
		pthread_mutex_unlock(fork);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	philo_eat(t_philo *philo)
{
	if (get_fork(philo, philo->forks[LEFT]))
	{
		printf("test\n");
		return (EXIT_FAILURE);
	}
	if (get_fork(philo, philo->forks[RIGHT]))
	{
		pthread_mutex_unlock(philo->forks[LEFT]);
		return (EXIT_FAILURE);
	}
	if (print_action(philo, EATING))
	{
		pthread_mutex_unlock(philo->forks[LEFT]);
		pthread_mutex_unlock(philo->forks[RIGHT]);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&philo->data_mutex);
	philo->times_eaten += 1;
	philo->last_eaten = time_since_start(philo->rules);
	pthread_mutex_unlock(&philo->data_mutex);
	smart_sleep(philo->rules->eat_time);
	pthread_mutex_unlock(philo->forks[LEFT]);
	pthread_mutex_unlock(philo->forks[RIGHT]);
	return (EXIT_SUCCESS);
}

static void	eat_sleep_think_repeat(t_philo *philo)
{
	while (true)
	{
		if (philo_eat(philo))
			return ;
		if (philo->times_eaten == philo->rules->eat_n)
			break ;
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
	if (!philo->id % 2)
		usleep(1000);
	eat_sleep_think_repeat(philo);
	return (EXIT_SUCCESS);
}

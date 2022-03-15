/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_life.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 09:47:18 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/15 13:49:48 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_philo *philo)
{
	print_action(philo, SLEEPING);
	smart_sleep(philo->rules->sleep_time);
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->forks[LEFT]);
	print_action(philo, FORK);
	pthread_mutex_lock(philo->forks[RIGHT]);
	print_action(philo, FORK);
	pthread_mutex_lock(&philo->data_mutex);
	print_action(philo, EATING);
	philo->times_eaten += 1;
	philo->last_eaten = time_since_start(philo->rules);
	pthread_mutex_unlock(&philo->data_mutex);
	smart_sleep(philo->rules->eat_time);
	pthread_mutex_unlock(philo->forks[LEFT]);
	pthread_mutex_unlock(philo->forks[RIGHT]);
	pthread_mutex_lock(&philo->data_mutex);
	pthread_mutex_unlock(&philo->data_mutex);
}

static void	eat_sleep_think_repeat(t_philo *philo)
{
	while (true)
	{
		philo_eat(philo);
		if (philo->times_eaten == philo->rules->eat_n)
			break ;
		philo_sleep(philo);
		print_action(philo, THINKING);
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo->id % 2)
		smart_sleep(5);
	eat_sleep_think_repeat(philo);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_life.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 09:47:18 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/19 10:38:06 by rcappend      ########   odam.nl         */
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
	sem_wait(philo->rules->fork_sem);
	print_action(philo, FORK);
	sem_wait(philo->rules->fork_sem);
	print_action(philo, FORK);
	philo->times_eaten += 1;
	philo->last_eaten = print_action(philo, EATING);
	smart_sleep(philo->rules->eat_time);
	sem_post(philo->rules->fork_sem);
	sem_post(philo->rules->fork_sem);
}

static void	eat_sleep_think_repeat(t_philo *philo)
{
	if (philo->id > philo->rules->philos_n / 2)
		print_action(philo, THINKING);
	while (philo->rules->start_time != STOP)
	{
		philo_eat(philo);
		if (philo->times_eaten == philo->rules->eat_n)
			exit(EXIT_SUCCESS);
		philo_sleep(philo);
		print_action(philo, THINKING);
	}
}

void	philo_life(t_philo *philo)
{
	pthread_t	monitor_tid;
	
	if (pthread_create(&monitor_tid, NULL, &monitor, (void *)philo))
		exit_error("Thread failure");
	pthread_detach(monitor_tid);
	eat_sleep_think_repeat(philo);
	exit(EXIT_SUCCESS);
}

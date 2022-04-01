/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 14:21:31 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/15 14:04:59 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_philo(t_philo *philo, int64_t death_time)
{
	printf("%6lld: ", death_time);
	printf("%d ", philo->id);
	printf("died\n");
}

void	*monitor(void *arg)
{
	t_philo	*philo;
	int64_t	death_time;

	philo = (t_philo *)arg;
	while (TRUE)
	{
		if (time_since_start(philo->rules) - philo->last_eaten > \
			philo->rules->die_time)
		{
			death_time = time_since_start(philo->rules);
			philo->rules->start_time = STOP;
			sem_wait(philo->rules->dead_sem);
			kill_philo(philo, death_time);
			kill(0, SIGQUIT);
		}
	}
}

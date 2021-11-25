/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_action.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 17:13:35 by rutgercappe   #+#    #+#                 */
/*   Updated: 2021/11/17 13:18:32 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	print_action(t_philo *philo, char *msg)
{
	int64_t	time;

	if (philo->rules->start_time == STOP)
		return (EXIT_FAILURE);
	sem_wait(philo->rules->dead_sem);
	sem_wait(philo->rules->write_sem);
	time = time_since_start(philo->rules);
	printf("%6lld: ", time);
	printf("%d ", philo->id);
	printf("%s\n", msg);
	sem_post(philo->rules->dead_sem);
	sem_post(philo->rules->write_sem);
	return (time);
}

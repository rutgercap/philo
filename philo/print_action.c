/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_action.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 17:13:35 by rutgercappe   #+#    #+#                 */
/*   Updated: 2022/03/30 09:51:20 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_action(t_philo *philo, char *msg)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->rules->write_mut);
	if (philo->rules->dead)
	{
		pthread_mutex_unlock(&philo->rules->write_mut);
		return (STOP);
	}
	time = time_since_start(philo->rules);
	printf("%llu: %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->rules->write_mut);
	return (CONTINUE);
}

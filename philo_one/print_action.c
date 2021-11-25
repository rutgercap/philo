/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_action.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 17:13:35 by rutgercappe   #+#    #+#                 */
/*   Updated: 2021/11/19 08:57:16 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	int64_t	time;

	if (philo->rules->start_time == STOP)
		return ;
	pthread_mutex_lock(&philo->rules->write_mut);
	time = time_since_start(philo->rules);
	printf("%6lld: ", time);
	printf("%d ", philo->id);
	printf("%s\n", msg);
	pthread_mutex_unlock(&philo->rules->write_mut);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 12:17:55 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/30 10:11:59 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo(t_philo *philo, t_rules *rules)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->data_mutex);
	if (!philo->checked && philo->times_eaten == rules->eat_n)
	{
		philo->checked = true;
		ret = FULL;
	}
	else if (time_since_start(rules) - philo->last_eaten > rules->die_time)
		ret = DEAD;
	pthread_mutex_unlock(&philo->data_mutex);
	return (ret);
}

static int	kill_philo(const int id, t_rules *rules)
{
	uint64_t	time;

	pthread_mutex_lock(&rules->write_mut);
	rules->dead = true;
	pthread_mutex_unlock(&rules->write_mut);
	time = time_since_start(rules);
	printf("%llu: %d died\n", time, id);
	return (0);
}

int	monitor(t_philo *philos, int philos_n, t_rules *rules)
{
	int		satisfied_philos;
	int		ret;
	int		i;

	satisfied_philos = 0;
	ret = 0;
	i = 0;
	while (TRUE)
	{
		ret = check_philo(&philos[i % philos_n], rules);
		if (ret == DEAD)
			return (kill_philo(i % philos_n + 1, rules));
		else if (ret == FULL)
			satisfied_philos++;
		if (satisfied_philos == philos_n)
			break ;
		usleep(1000);
		i++;
	}
	return (EXIT_SUCCESS);
}

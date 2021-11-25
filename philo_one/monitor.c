/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 12:17:55 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/25 12:28:21 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo(t_philo *philo, t_rules *rules)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->data_mutex);
	if (philo->times_eaten == rules->eat_n)
		ret = FULL;
	else if (time_since_start(rules) - philo->last_eaten > rules->die_time)
		ret = DEAD;
	pthread_mutex_unlock(&philo->data_mutex);
	return (ret);
}

static int	kill_philo(const int id, t_rules *rules)
{
	int64_t	last_time;

	last_time = time_since_start(rules);
	rules->start_time = STOP;
	printf("%6lld: ", last_time);
	printf("%d ", id);
	printf("died\n");
	return (EXIT_SUCCESS);
}

int	food_time(t_philo *philos, int philos_n, t_rules *rules)
{
	int		satisfied_philos;
	int		ret;
	int		i;

	satisfied_philos = 0;
	ret = 0;
	i = 0;
	rules->start_time = get_time();
	while (TRUE)
	{
		ret = check_philo(&philos[i % philos_n], rules);
		if (ret == DEAD)
			return (kill_philo(i % philos_n + 1, rules));
		else if (ret == FULL)
			satisfied_philos += 1;
		if (satisfied_philos == philos_n)
			break ;
		smart_sleep(5);
		i++;
	}
	return (EXIT_SUCCESS);
}

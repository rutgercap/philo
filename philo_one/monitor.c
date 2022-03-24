/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 12:17:55 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/24 16:43:19 by rcappend      ########   odam.nl         */
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
	int64_t	last_time;

	pthread_mutex_lock(&rules->write_mut);
	rules->dead = true;
	last_time = time_since_start(rules);
	ft_putnbr_fd(last_time, 1);
	ft_putstr_fd(": ", 1);
	ft_putnbr_fd(id, 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd("died", 1);
	return (EXIT_SUCCESS);
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
		usleep(250);
		i++;
	}
	return (EXIT_SUCCESS);
}

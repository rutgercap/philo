/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_philos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 15:08:19 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/30 09:56:16 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	config_struct(t_philo *philo, const int philos_n, \
			t_fork *forks, t_rules *rules)
{
	philo->rules = rules;
	philo->times_eaten = 0;
	philo->forks[LEFT] = &forks[philo->id - 1];
	if (philo->id == philos_n)
		philo->forks[RIGHT] = &forks[0];
	else
		philo->forks[RIGHT] = &forks[philo->id];
}

static int	make_structs(t_philo **philos, const int philos_n,
			t_fork *forks, t_rules *rules)
{
	int		i;

	i = 0;
	while (i < philos_n)
	{
		philos[0][i].id = i + 1;
		config_struct(&philos[0][i], philos_n, forks, rules);
		if (pthread_mutex_init(&philos[0][i].data_mutex, NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	start_philos(t_philo *philos, int philos_n)
{
	int	i;

	i = 0;
	philos->rules->start_time = get_time();
	while (i < philos_n)
	{
		if (pthread_create(&philos->tid, NULL, &philo_life, (void *)&philos[i]))
			return (-1);
		pthread_detach(philos->tid);
		usleep(200);
		i++;
	}
	return (0);
}

int	setup_philos(t_philo **philos, const int philos_n, \
	t_fork *forks, t_rules *rules)
{
	*philos = ft_calloc(philos_n + 1, sizeof(t_philo));
	if (!philos)
		return (-1);
	if (make_structs(philos, philos_n, forks, rules))
		return (-1);
	if (start_philos(*philos, philos_n))
		return (-1);
	return (0);
}

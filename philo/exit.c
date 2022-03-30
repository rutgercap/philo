/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 08:41:54 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/30 09:44:03 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(int forks_n, t_fork *forks)
{
	while (forks_n > 0)
	{
		forks_n--;
		pthread_mutex_destroy(&forks[forks_n]);
	}
}

int	write_error(char *msg)
{
	printf("%s\n", msg);
	return (EXIT_FAILURE);
}

int	exit_error(char *msg, int philos_n, t_fork *forks, t_philo *philos)
{
	if (forks)
	{
		destroy_forks(philos_n, forks);
		free(forks);
	}
	if (philos)
		free(philos);
	write_error(msg);
	return (EXIT_FAILURE);
}

void	join_threads(t_philo *philos, int philos_n)
{
	int	i;

	i = 0;
	while (i < philos_n)
	{
		pthread_join(philos[i].tid, NULL);
		i++;
	}
}

int	exit_correct(int forks_n, t_fork *forks, t_philo *philos, t_rules *rules)
{
	join_threads(philos, forks_n);
	pthread_mutex_destroy(&rules->write_mut);
	destroy_forks(forks_n, forks);
	free(philos);
	free(forks);
	return (EXIT_SUCCESS);
}

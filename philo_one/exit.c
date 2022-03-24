/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 08:41:54 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/24 16:28:13 by rcappend      ########   odam.nl         */
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

int	exit_correct(int forks_n, t_fork *forks, t_philo *philos)
{
	destroy_forks(forks_n, forks);
	free(philos);
	free(forks);
	return (EXIT_SUCCESS);
}

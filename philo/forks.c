/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 12:21:51 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/11 14:31:48 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_fork *fork)
{
	if (pthread_mutex_init(fork, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_forks(t_fork *forks, const int forks_n)
{
	int		i;

	i = 0;
	while (i < forks_n)
	{
		if (init_fork(&forks[i]))
		{
			i--;
			if (i > 0)
				destroy_forks(i, forks);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	setup_forks(t_fork **forks, const int forks_n)
{
	*forks = (t_fork *)ft_calloc(forks_n, sizeof(t_fork));
	if (!forks)
		return (EXIT_FAILURE);
	if (init_forks(*forks, forks_n))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

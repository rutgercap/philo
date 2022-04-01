/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 12:21:51 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/30 09:57:10 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_fork *fork)
{
	if (pthread_mutex_init(fork, NULL))
		return (-1);
	return (0);
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
			return (-1);
		}
		i++;
	}
	return (0);
}

int	setup_forks(t_fork **forks, const int forks_n)
{
	*forks = (t_fork *)ft_calloc(forks_n, sizeof(t_fork));
	if (!forks)
		return (-1);
	if (init_forks(*forks, forks_n))
		return (-1);
	return (0);
}

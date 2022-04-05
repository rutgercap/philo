/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 09:11:28 by rcappend      #+#    #+#                 */
/*   Updated: 2022/04/05 14:14:04 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_rules(t_rules *rules)
{
	rules->die_time = 0;
	rules->eat_time = 0;
	rules->sleep_time = 0;
	rules->start_time = 0;
	rules->max_eating = false;
	rules->eat_n = -1;
	rules->dead = false;
}

int	main(int argc, char **argv)
{
	int			philos_n;
	t_rules		rules;
	t_fork		*forks;
	t_philo		*philos;
	pthread_t	*t_ids;

	forks = NULL;
	philos = NULL;
	t_ids = NULL;
	init_rules(&rules);
	if (arg_lexing(&rules, &philos_n, argc, argv))
		return (EXIT_FAILURE);
	if (setup_forks(&forks, philos_n))
		return (exit_error("Error setting up forks", philos_n, forks, philos));
	if (setup_philos(&philos, philos_n, forks, &rules))
		return (exit_error("Error setting up forks", philos_n, forks, philos));
	monitor(philos, philos_n, &rules);
	return (exit_correct(philos_n, forks, philos, &rules));
}

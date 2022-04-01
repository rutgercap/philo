/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 12:03:35 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/30 09:57:00 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argc(int argc)
{
	if (argc < 5 && argc > 6)
		return (write_error("\
Usage: \"./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_to_eat]\""));
	return (0);
}

static int	check_arguments_numeric(int argc, char **argv)
{
	while (argc > 0)
	{
		if (ft_strcheck(argv[argc], &ft_isdigit))
			return (write_error("Arguments can only be numeric"));
		argc--;
	}
	return (0);
}

static int	read_arguments(t_rules *rules, int *philos_n, char **argv)
{
	*philos_n = ft_atoi(argv[1]);
	rules->die_time = ft_atoi(argv[2]);
	rules->eat_time = ft_atoi(argv[3]);
	rules->sleep_time = ft_atoi(argv[4]);
	if (*philos_n < 1 || rules->die_time < 1 || \
		rules->eat_time < 1 || rules->sleep_time < 1)
		return (write_error("One or more arguments are invalid"));
	if (argv[5])
	{
		rules->eat_n = ft_atoi(argv[5]);
		if (rules->eat_n < 1)
			return (write_error("One or more arguments are invalid"));
	}
	return (0);
}

int	arg_lexing(t_rules *rules, int *philos_n, int argc, char **argv)
{
	if (check_argc(argc))
		return (-1);
	if (check_arguments_numeric(argc - 1, argv))
		return (-1);
	if (read_arguments(rules, philos_n, argv))
		return (-1);
	if (pthread_mutex_init(&rules->write_mut, NULL))
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexing.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 12:03:35 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/25 12:26:46 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_argc(int argc)
{
	if (argc < 5 && argc > 6)
		exit_error("\
Usage: \"./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_to_eat]\"");
}

static void	check_arguments_numeric(int argc, char **argv)
{
	while (argc > 0)
	{
		if (ft_strcheck(argv[argc], &ft_isdigit))
			exit_error("Arguments can only be numeric");
		argc--;
	}
}

static void	read_arguments(t_rules *rules, char **argv)
{
	rules->philos_n = ft_atoi(argv[1]);
	rules->die_time = ft_atoi(argv[2]);
	rules->eat_time = ft_atoi(argv[3]);
	rules->sleep_time = ft_atoi(argv[4]);
	if (rules->philos_n  < 1 || rules->die_time < 1 || \
		rules->eat_time < 1 || rules->sleep_time < 1)
		exit_error("One or more arguments are invalid");
	if (argv[5])
	{
		rules->eat_n = ft_atoi(argv[5]);
		if (rules->eat_n < 1)
			exit_error("One or more arguments are invalid");
	}
}

void	arg_lexing(t_rules *rules, int argc, char **argv)
{
	check_argc(argc);
	check_arguments_numeric(argc - 1, argv);
	read_arguments(rules, argv);
}

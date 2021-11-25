/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 09:11:28 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/17 14:47:51 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

static void	init(t_rules **rules_ref, t_philo **philo_ref)
{
	t_rules	*rules;
	t_philo	*philo;
	
	philo = malloc(sizeof(t_philo));
	if (!philo)
		exit_error("Malloc failure");
	philo->times_eaten = 0;
	*philo_ref = philo;
	rules = malloc(sizeof(t_rules));
	if (!rules)
		exit_error("Malloc failure");
	rules->die_time = NOT_SET;
	rules->eat_time = NOT_SET;
	rules->sleep_time = NOT_SET;
	rules->start_time = NOT_SET;
	rules->eat_n = NOT_SET;
	rules->philos_n = NOT_SET;
	*rules_ref = rules;
}

static void	start_forks(t_rules *rules, t_philo *philo)
{
	int		i;
	pid_t	pid;

	i = 1;
	philo->rules = rules;
	philo->rules->start_time = get_time();
	while (i <= rules->philos_n)
	{
		philo->id = i;
		pid = fork();
		if (pid == EXIT_FAILURE)
			exit_error("Forking failure");
		else if (pid == CHILD)
			break ;
		i++;
	}
	if (pid == CHILD)
		philo_life(philo);
	else
		waitpid(-1, NULL, 0);
}

int	main(int argc, char **argv)
{
	t_rules		*rules;
	t_philo		*philo;

	rules = NULL;
	philo = NULL;
	init(&rules, &philo);
	arg_lexing(rules, argc, argv);
	setup_sems(rules);
	start_forks(rules, philo);
	exit(EXIT_SUCCESS);
}

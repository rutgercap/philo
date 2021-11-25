/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   semaphore.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 15:08:19 by rcappend      #+#    #+#                 */
/*   Updated: 2021/11/17 12:23:53 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static sem_t	*setup_sem(const char *name, unsigned int value)
{
	sem_t	*sem;
	
	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0777, value);
	if (sem == SEM_FAILED) 
		exit_error("Error creating semaphore");
	return (sem);
}

void	setup_sems(t_rules *rules)
{
	rules->fork_sem = setup_sem("fork_sem", rules->philos_n);
	rules->write_sem = setup_sem("write_sem", 1);
	rules->dead_sem = setup_sem("dead_sem", 1);
}

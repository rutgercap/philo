/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_action.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 17:13:35 by rutgercappe   #+#    #+#                 */
/*   Updated: 2022/03/15 12:45:22 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	int64_t	time;

	pthread_mutex_lock(&philo->rules->write_mut);
	time = time_since_start(philo->rules);
	ft_putnbr_fd(time, 1);
	ft_putstr_fd(": ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(msg, 1);
	pthread_mutex_unlock(&philo->rules->write_mut);
}

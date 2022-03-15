/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 12:04:59 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/15 14:06:23 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	get_time(void)
{
	struct timeval	time_values;
	int64_t			time;

	gettimeofday(&time_values, NULL);
	time = ((time_values.tv_sec * 1000) + (time_values.tv_usec / 1000));
	return (time);
}

int64_t	time_since_start(t_rules *rules)
{
	return (get_time() - rules->start_time);
}

void	smart_sleep(int64_t ms)
{
	int64_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(5);
}

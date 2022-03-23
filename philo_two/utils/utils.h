/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 10:32:16 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/23 13:37:55 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct timeval	t_timeval;

int		ft_isdigit(int c);

void	ft_bzero(void *s, size_t n);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

int		ft_strcheck(char const *s, int (*f)(int));

int     ft_isspace(int c);

#endif

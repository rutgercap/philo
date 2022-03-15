/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 10:32:16 by rcappend      #+#    #+#                 */
/*   Updated: 2022/03/15 12:43:32 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct timeval	t_timeval;

void	ft_bzero(void *s, size_t n);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

int		ft_strcheck(char const *s, int (*f)(int));

int		ft_isspace(int c);

int		ft_isdigit(int c);

void	ft_putchar_fd(const char c, int fd);

void	ft_putendl_fd(const char *s, int fd);

void	ft_putnbr_fd(int64_t n, int fd);

void	ft_putstr_fd(const char *s, int fd);

size_t	ft_strlen(const char *str);

#endif

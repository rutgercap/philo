NAME		=	philo

SRCS		=	main.c \
				exit.c \
				init.c \
				forks.c \
				setup_philos.c \
				philo_life.c \
				monitor.c \
				time.c \
				print_action.c \
				utils/ft_atoi.c \
				utils/ft_isspace.c \
				utils/ft_isdigit.c \
				utils/ft_calloc.c \
				utils/ft_bzero.c \
				utils/ft_strcheck.c \
				utils/ft_putendl_fd.c \
				utils/ft_putnbr_fd.c \
				utils/ft_putstr_fd.c \
				utils/ft_putchar_fd.c \
				utils/ft_strlen.c
OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

ARGS		=	2 6000 200 200 5

all:		$(NAME)
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME) $(ARGS)

drun: all
	lldb $(NAME) -- $(ARGS)
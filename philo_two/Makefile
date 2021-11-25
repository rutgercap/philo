NAME		=	philo

SRCS		=	main.c \
				lexing.c \
				philo_life.c \
				semaphore.c \
				monitor.c \
				time.c \
				print_action.c \
				utils/ft_atoi.c \
				utils/ft_isspace.c \
				utils/ft_isdigit.c \
				utils/ft_calloc.c \
				utils/ft_bzero.c \
				utils/ft_strcheck.c 
OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

ARGS		=	2 150 100 100

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
SRCS		= ft_atol.c init.c main.c monitor.c parsing.c routine.c utils.c
OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror #-g3 -fsanitize=thread  #-fsanitize=address



NAME = philo

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean:clean
		$(RM) $(NAME)

re:		fclean all

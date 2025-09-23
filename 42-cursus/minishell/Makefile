NAME = minishell
CC = cc
CFLAGS =  -Wall -Wextra -Werror

SRC = ft_copy_env.c ft_malloc.c global.c kill_pid.c main2.c main.c construct/cmd.c construct/pipe_redir_c.c \
      	execution/builtins.c execution/ft_cd.c execution/ft_echo.c execution/ft_env.c execution/ft_execute2.c \
	execution/ft_execute.c execution/ft_exit.c execution/ft_export.c execution/ft_ft_split.c execution/ft_ft_strjoin.c\
       	execution/ft_heredoc.c execution/ft_is_alpha.c execution/ft_pipe.c execution/ft_putstr.c execution/ft_putstr_fd.c \
	execution/ft_pwd.c execution/ft_redirection.c execution/ft_strcmp.c execution/ft_unset.c execution/ft_utils.c execution/get_env2.c\
       	execution/get_env.c execution/runcmd.c lexer/lexer.c lexer/r_pipe2.c lexer/r_pipe.c lexer/split_lexer.c libft/ft_atoi.c \
	libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_itoa.c libft/ft_memset.c \
	libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strrchr.c \
	libft/ft_substr.c signal/handel_siganl.c syntax_appand/appand2.c syntax_appand/appand.c syntax_appand/herdoc_2.c syntax_appand/herdoc.c \
	syntax_appand/split_cmd.c syntax_appand/syantax1.c syntax_appand/syantax.c syntax_appand/syntax_2.c
 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


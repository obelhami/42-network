# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelhami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 14:11:38 by obelhami          #+#    #+#              #
#    Updated: 2024/04/24 14:11:40 by obelhami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MEND_FILES = main.c count_string.c fill_array.c fill_tab.c free_stack.c ft_free.c input_check.c \
			lst_new.c node_size.c sorted_four_five.c sorted_three.c  ft_atol.c \
			ft_swap.c instructions.c sorted_stack.c sorted_two.c searching.c 
SRCS = $(addprefix mendatory/, $(MEND_FILES))

GNL_FILES = get_next_line.c get_next_line_utils.c
GNL = $(addprefix get_next_line/, $(GNL_FILES))

OBJS = $(SRCS:.c=.o)

BONUS_FILES = 	main_bonus.c count_string_bonus.c fill_array_bonus.c fill_tab_bonus.c \
				free_stack_bonus.c ft_free_bonus.c input_check_bonus.c \
				lst_new_bonus.c ft_atol_bonus.c ft_swap_bonus.c instructions_bonus.c \
				ft_strcmp_bonus.c ft_checker_bonus.c check_string_bonus.c node_size_bonus.c 

BONUS = $(addprefix bonus/, $(BONUS_FILES))

BONUS_OBJS = $(BONUS:.c=.o) $(GNL:.c=.o)

BONUS_NAME = checker
NAME 		= push_swap
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f

LIBFT 		= libft/libft.a

all: 		$(NAME)


$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

bonus: 		$(BONUS_NAME) $(LIBFT)

$(NAME): 	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@$(MAKE) -C libft

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)
			$(MAKE) -C libft clean

fclean: 	clean
			$(RM) $(NAME) $(BONUS_NAME)
			$(MAKE) -C libft fclean

re: 		fclean $(NAME)

.PHONY: 	all clean fclean re bonus


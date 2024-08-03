# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelhami <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 03:14:36 by obelhami          #+#    #+#              #
#    Updated: 2024/03/13 03:14:37 by obelhami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MEND_FILES	= ft_strstr.c get_map.c init_game.c \
		parsing.c main.c dbl_free2.c ft_swap.c key_hook.c load_images.c \
		move_player.c position_player.c put_image.c check_rectangle.c \
		check_path.c check_element.c flood_fill.c 
SRC = $(addprefix mend/, $(MEND_FILES))

GNL_FILES = get_next_line.c get_next_line_utils.c
GNL = $(addprefix gnl/, $(GNL_FILES))

OBJS = $(SRC:.c=.o) $(GNL:.c=.o)

BNS_FILES = ft_strstr_bonus.c get_map_bonus.c init_game_bonus.c load_images_bonus.c\
		parsing_bonus.c main_bonus.c dbl_free2_bonus.c ft_swap_bonus.c key_hook_bonus.c \
		move_player_bonus.c position_player_bonus.c put_image_bonus.c check_rectangle_bonus.c \
		check_path_bonus.c check_element_bonus.c flood_fill_bonus.c move_enemy_bonus.c 
BONUS = $(addprefix bons/, $(BNS_FILES))

BONUS_OBJS = $(BONUS:.c=.o) $(GNL:.c=.o)

BONUS_NAME = so_long_bonus
NAME = so_long
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MLXFLAGS		= -lmlx -framework OpenGL -framework AppKit

LIBFT			= libft/libft.a

all:			$(NAME)


$(BONUS_NAME):	$(BONUS_OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLXFLAGS) -o $(BONUS_NAME)

bonus :			$(BONUS_NAME) $(LIBFT)


$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME) 

$(LIBFT):		
				@$(MAKE) -C libft

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				$(MAKE) -C libft clean

fclean:			clean
				$(RM) $(NAME) $(BONUS_NAME)
				$(MAKE) -C libft fclean

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
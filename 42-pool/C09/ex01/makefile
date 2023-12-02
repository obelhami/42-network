CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))
TARGET = libft.a
all: $(TARGET)
$(TARGET) : $(OBJ)
	ar rcs $(TARGET) $(OBJ)
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CFLAGS) -I$(INCDIR) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(TARGET)
re: fclean all

SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)
NAME		=	fixed

CXX			=	c++

CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98


all: $(NAME)


$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


SRC = HumanA.cpp  main.cpp Weapon.cpp HumanB.cpp
OBJS = $(SRC:.cpp=.o)
NAME = weapon

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: $(NAME)
$(NAME) : $(OBJS)
		$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
clean : 
		$(RM) $(OBJS)
fclean : clean
		$(RM) $(NAME)
re : fclean all

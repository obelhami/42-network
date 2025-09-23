FILES		= 	megaphone.cpp

OBJS 		= 	$(FILES:.cpp=.o)

NAME		= 	megaphone

CXX 		=	c++
CXXFLAGS 	=	-Wall -Wextra -Werror -std=c++98
RM 			= 	rm -rf


all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = iter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all%  
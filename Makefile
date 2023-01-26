NAME =ft_containers

SRC=vector.cpp

CPPFLAGS=-Wall -Wextra -Werror -std=c++11 -fsanitize=address -g

OBJ= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all 
NAME =ft_containers

SRC=vector.cpp

CPPFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

OBJ= $(SRC:.cpp=.o)

GA= git add .

GC= git commit -m "working in vector"

GP= git push

all : $(NAME)


$(NAME) : $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

push: fclean
	$(GA) && $(GC) && $(GP) 



re : fclean all 
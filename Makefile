NAME =ft_containers

SRC=vector.cpp

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

CXX=c++

OBJ= $(SRC:.cpp=.o)

GA= git add .

GC= git commit -m "$(ARGS)"

GP= git push

all : $(NAME)


$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

push: fclean
	@ $(GA) && $(GC) && $(GP) 

re : fclean all 
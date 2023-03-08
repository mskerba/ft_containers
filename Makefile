VECO =vector.out

MAPO =map.out

VECS=std::vector_test.cpp

VECF=ft::vector_test.cpp

MAPF=ft::map_test.cpp

MAPS=std::map_test.cpp 

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

CXX=c++


GA= git add .

GC= git commit -m "$(ARGS)"

GP= git push

vector : $(NAME)
	@echo "\033[31m------------------std-------------------------\033[0m\n"
	@CXX $(CXXFLAGS) $(VECS) -o $(VECO)
	@./$(VECO) > std_vector.txt 
	@echo "\033[31m-------------------ft-------------------------\033[0m\n"
	@CXX $(CXXFLAGS) $(VECF) -o $(VECO)
	@./$(VECO)  > ft_vector.txt  
	@echo "\033[31m------------------diff------------------------\033[0m\n\n"
	@diff ft_vector.txt std_vector.txt > diff.log && rm $(VECO) ft_vector.txt std_vector.txt 

map : $(NAME)
	@echo "\033[31m------------------std-------------------------\033[0m\n"
	@CXX $(CXXFLAGS) $(MAPS) -o $(MAPO)
	@./$(VECO) > std_map.txt 
	@echo "\033[31m-------------------ft-------------------------\033[0m\n"
	@CXX $(CXXFLAGS) $(MAPF) -o $(MAPO)
	@./$(VECO)  > ft_map.txt  
	@echo "\033[31m------------------diff------------------------\033[0m\n\n"
	@diff ft_map.txt std_map.txt > diff.log && rm $(MAPO) ft_map.txt std_map.txt 


clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

push: fclean
	@ $(GA) && $(GC) && $(GP) 

re : fclean all 


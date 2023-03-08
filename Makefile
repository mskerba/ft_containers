VECO=vector.out

MAPO=map.out

VECS=test/std::vector_test.cpp

VECF=test/ft::vector_test.cpp

MAPF=test/ft::map_test.cpp

MAPS=test/std::map_test.cpp 

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

CXX=c++


GA= git add .

GC= git commit -m "$(ARGS)"

GP= git push

all:
	@echo "\033[31m------------------std_vector-------------------------\033[0m\n"
	$(CXX) $(CXXFLAGS) $(VECS) -o $(VECO)
	@./$(VECO) > std_vector.txt 
	@echo "\033[31m-------------------ft_vector-------------------------\033[0m\n"
	$(CXX) $(CXXFLAGS) $(VECF) -o $(VECO)
	@./$(VECO)  > ft_vector.txt  
	@echo "\033[31m------------------diff_vector------------------------\033[0m\n\n"
	@diff ft_vector.txt std_vector.txt > vector_diff.log && rm $(VECO) ft_vector.txt std_vector.txt
	@echo "\033[31m------------------std_map-------------------------\033[0m\n"
	$(CXX) $(CXXFLAGS) $(MAPS) -o $(MAPO)
	@./$(MAPO) > std_map.txt 
	@echo "\033[31m-------------------ft_map-------------------------\033[0m\n"
	$(CXX) $(CXXFLAGS) $(MAPF) -o $(MAPO)
	@./$(MAPO)  > ft_map.txt  
	@echo "\033[31m------------------diff_vector------------------------\033[0m\n\n"
	@diff ft_map.txt std_map.txt > map_diff.log && rm $(MAPO) ft_map.txt std_map.txt 


clean:

fclean : clean
	rm -rf vector_diff.log map_diff.log

push: fclean
	@ $(GA) && $(GC) && $(GP) 

re : fclean all 


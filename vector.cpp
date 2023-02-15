#include <iostream>
#include <type_traits>
#include <vector>
#include <stack>
#include <unistd.h>
#include "vector.tmp"
#include "vector.hpp"
#include "ft_containers.hpp"

int main()
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< vector const_iterator tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    /*------------ std::vector ---------*/
    std::vector<int> v((size_t)3, 4);
    std::vector<int>::const_iterator it, it1;
    it = v.begin();
    it1 = v.begin() + 1;
    /*----------------------------------*/
    /*------------ ft::vector ---------*/
    ft::vector<int> my_v((size_t)3, 4);
    ft::vector<int>::const_iterator my_it, my_it1, tmp;
    my_it = my_v.begin();
    my_it1 = my_v.begin() + 1;
    /*----------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::left << " copy constructor "  << "] --------------------]\t\t\033[0m";
    {
        ft::vector<int>::const_iterator ob(my_it);
        std::cout << (&(*my_it) == &(*ob));
    }
}
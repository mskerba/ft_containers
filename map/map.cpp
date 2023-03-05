#include "map.hpp"
#include <unistd.h>
#include <map>
// #include <pair>

int main()
{
    ft::map<int, std::string> ft_m2;
    for (int i = 0; i < 4; ++i)
        ft_m2.insert(ft::make_pair(i, "string2"));
    ft_m2.root.printTree(ft_m2.root.__root, "", 1);
    ft_m2.erase(0);
    // std::cout << std::endl;
    // ft_m2.erase(1);
    // std::cout << std::endl;
    // ft_m2.erase(2);
    // std::cout << std::endl;
    // ft_m2.erase(3);
    // ft_m2.erase(7);
}
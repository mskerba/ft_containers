#include "map.hpp"
#include <unistd.h>
#include <map>
#include <type_traits>
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

int main()
{
    ft::map<int, std::string> ft_m3;

    for (size_t i = 0; i < 1e6; i++)
        ft_m3.insert(ft::make_pair(i, "string1"));


        std::random_device randDev;
        std::mt19937 generator(randDev());
        std::uniform_int_distribution<int> distr(0, 1e8);

    for (size_t i = 0; i < 1e6; ++i)
    {
        int n = distr(generator);
        int ret2 = ft_m3.erase(n);
    }

    if (!ft_m3.empty())
        ft_m3.erase(ft_m3.begin(), ft_m3.end());
    return 0;
}

int main1()
{
    ft::map<int, std::string> ft_m2;
    for (int i = 0; i < 10; ++i)
        ft_m2.insert(ft::make_pair(i, "string2"));
    // ft_m2.insert(ft::make_pair(1, "string2"));
    // ft_m2.insert(ft::make_pair(3, "string2"));
    // ft_m2.insert(ft::make_pair(4, "string2"));
    // ft_m2.insert(ft::make_pair(2, "string2"));
    // ft_m2.insert(ft::make_pair(0, "string2"));
    ft_m2.root.printTree(ft_m2.root.__root, "", 1);
    std::cout << "----------\n";
    
    // for (int i = 0; i < 10; ++i)
    // {
        ft_m2.erase(3);
    // ft_m2.root.printTree(ft_m2.root.__root, "", 1);
    // std::cout << "\n\n----------\n\n";
    // }
    // std::cout << std::endl;
    // ft_m2.erase(0);
    // std::cout << std::endl;
    // ft_m2.erase(2);
    // std::cout << std::endl;
    // ft_m2.erase(3);
    // ft_m2.erase(7);
    ft_m2.root.printTree(ft_m2.root.__root, "", 1);
return 0;
}
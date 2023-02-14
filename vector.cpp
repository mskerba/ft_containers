#include <iostream>
#include <type_traits>
#include <vector>
#include <unistd.h>
#include "vector.tmp"
#include "vector.hpp"
#include "ft_containers.hpp"

int main()
{
    std::vector<A> v;
    ft::vector<A> vec;
    std::cout << "********\n";
    v.assign(0, 0);
    // vec.assign((size_t)0, 0);
    std::cout << "********\n\n\n\n\n\n";
    v.assign(64, 1);
    // vec.assign((size_t)64, 1);
    std::cout << "********\n\n\n\n\n\n";
    v.assign(32, 2);
    // vec.assign((size_t)32, 2);
    std::cout << "********\n\n\n\n\n\n";
    v.assign(49, '8');
    // vec.assign((size_t)49, '8');
    std::cout << "********\n";
    return 0;
}
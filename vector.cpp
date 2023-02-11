#include <iostream>
#include <type_traits>
#include <vector>
#include <unistd.h>
#include "vector.tmp"
#include "vector.hpp"
#include "ft_containers.hpp"

int main()
{
    bool a;
    {
        ft::vector<A> v((size_t)20, 1);
        v.push_back(1);

        std::cout <<v.capacity() << "***************" << v.size() << std::endl;
        v.insert(v.begin() + 10, 30, 2);
        std::cout <<v.capacity() << "***************" << v.size() << std::endl;
    }

    return 0;
}


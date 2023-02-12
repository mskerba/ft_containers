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
        std::vector<int> v(20, 4);

        std::cout << v.capacity() << " " << v.size() << std::endl;
        v.insert(v.begin(), 21, 15);
        std::cout << v.capacity() << " " << v.size();
    }
    return 0;
}


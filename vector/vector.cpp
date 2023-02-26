#include <iostream>
#include <type_traits>
#include <vector>
#include "vector.hpp"
#include "../map/map.hpp"
#include <stack>
#include <map>
#include <unistd.h>

int main()
{

    std::map<int, int> m;
    m.insert(std::pair<int, int>(1, 3 ));
    m.insert(std::make_pair(2,  3));
    m.insert(std::pair<int, int>(3, 3 ));
    ft::map<int, int> ftm(m.begin(), m.end());

}
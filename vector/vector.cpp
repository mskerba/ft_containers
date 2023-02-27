#include <iostream>
#include <type_traits>
#include <vector>
#include "vector.hpp"
#include "../map/map.hpp"
#include "../utility/Red-Black-Tree.hpp"
#include "../utility/pair.hpp"
#include <stack>
#include <map>
#include <unistd.h>

int main()
{

    ft::map<int, int> m;
    m.root.Insert(ft::pair<int, int>(1, 3 ));
    m.root.Insert(ft::make_pair(2,  3));
    m.root.Insert(ft::pair<int, int>(3, 3 ));
    ft::map<int, int> ftm(m);

}
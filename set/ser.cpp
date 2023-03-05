#include <iostream>
#include "set.hpp"


int main()
{
    
        ft::set<int> m;
        for (int i = 0; i < 19; i++)
            m.insert(i);
        ft::set<int>::iterator it;
        for (it = m.begin(); it != m.end(); it = m.begin())
            m.erase(it);
        std::cout << m.size() << std::endl;
}
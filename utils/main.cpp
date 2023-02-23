#include "Red-Black-Tree.hpp"
#include <iostream>

int main()
{
    RBT<int, int> root;
    RBT<int, int> s(1, 2);
    root.rbt_insert(&root, &s);
    
    RBT<int, int> tmp = root;
    while()
    {
        tmp.print();
        tmp = tmp
    }
}
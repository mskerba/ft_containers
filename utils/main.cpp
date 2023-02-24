#include "Red-Black-Tree.hpp"
#include <iostream>

void print(RBT<int, int>::Node *e)
{
    if (!e) return ;
    print(e->__left);
    std::cout << e->__key << " " <<  e->__val << std::endl;
    print(e->__right);
}

int main()
{
    RBT<int , int > e;
    RBT<int , int>::Node s(4, 5);

    RBT<int , int>::Node a(5, 5);
    e.insert(&s);
    e.insert(&a);

    print(e.__root);
    e.left_Rotate(e.__root);
    print(e.__root);

}
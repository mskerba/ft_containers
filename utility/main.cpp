#include "Red-Black-Tree.hpp"
#include "pair.hpp"
#include <iostream>





// void print(RBT<int, int>::Node *e)
// {
//     if (!e) return ;
//     print(e->__left);
//     std::cout << e->__key << " " <<  e->__val << std::endl;
//     print(e->__right);
// }

// int main()
// {
//     RBT<int , int > e;
//     RBT<int , int>::Node s(4, 5);

//     RBT<int , int>::Node a(5, 5);
//     e.Insert(&s);
//     // e.Insert(&a);

//     // print(e.__root);
//     // e.left_Rotate(e.__root);
//     // print(e.__root);

// }





int main() {
    RBT<ft::pair<int, int> >::Node* s = new RBT<ft::pair<int, int> >::Node(make_pair(0, 9));
    RBT<ft::pair<int, int> > r;
    // r.Insert(s);
    // s = new RBT<ft::pair<int, int> >::Node(make_pair(5, 9));
    // r.Insert(s);
    // s = new RBT<ft::pair<int, int> >::Node(make_pair(4, 9));
    // r.Insert(s);
    // s = new RBT<ft::pair<int, int> >::Node(make_pair(1, 9));
    // r.Insert(s);
    // s = new RBT<ft::pair<int, int> >::Node(make_pair(4, 9));
    // r.Insert(s);
    // s = new RBT<ft::pair<int, int> >::Node(make_pair(7, 9));
    // r.Insert(s);
    // s = new RBT<ft::pair<int, int> >::Node(make_pair(9, 9));
    // r.Insert(s);
    // s = new RBT<ft::pair<int, int> >::Node(make_pair(2, 9));
    r.Insert(s);
    r.printTree(r.__root, "", true);
    return 0;
}

#include "Red-Black-Tree.hpp"
#include <iostream>


// # include <__config>
// # include <__tree>
// # include <__node_handle>
// # include <iterator>
// # include <memory>
// # include <utility>
// # include <functional>
// # include <initializer_list>
// # include <type_traits>
// # include <__cxx_version>




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
    RBT<int>::Node* s = new RBT<int>::Node(5);
    RBT<int> r;
    r.Insert(s);
    s = new RBT<int>::Node(3);
    r.Insert(s);
    s = new RBT<int>::Node(8);
    r.Insert(s);
    s = new RBT<int>::Node(1);
    r.Insert(s);
    s = new RBT<int>::Node(4);
    r.Insert(s);
    s = new RBT<int>::Node(7);
    r.Insert(s);
    s = new RBT<int>::Node(9);
    r.Insert(s);
    s = new RBT<int>::Node(2);
    r.Insert(s);
    r.printTree(r.__root, "", true);
    return 0;
}

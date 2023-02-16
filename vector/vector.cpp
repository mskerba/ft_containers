#include <iostream>
#include <type_traits>
#include <vector>
#include <stack>
#include <unistd.h>

int main()
{
    ft::stack<int> v;
    ft::stack<int> b;
     std::cout << (v == b)  << std::endl;

}
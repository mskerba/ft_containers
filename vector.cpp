#include <iostream>
#include <type_traits>
#include <vector>
#include <stack>
#include <unistd.h>
#include "vector.tmp"
#include "vector.hpp"
#include "stack.hpp"

int main()
{
    ft::stack<int> v;
    ft::stack<int> b;
     std::cout << (v == b)  << std::endl;

}
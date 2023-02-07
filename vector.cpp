#include <iostream>
#include <type_traits>
#include <vector>
#include <unistd.h>
#include "vector.tmp"
#include "vector.hpp"
#include "ft_containers.hpp"

// class   A
// {
//     public:
//         static  int i;
//         int id;
//         A() {
//             id = i++;
//             std::cout << "default constructor -> " << id<< std::endl;
//         }
//         ~A() {
//             std::cout << "destructor -> " << id << std::endl; 
//             }
//         A(const A &x) {
//             std::cout << "copy constructor -> " << x.id << std::endl;
//             id = x.id;
//             }
//         A &operator=(const A &x) {
//             std::cout << "copy assignement operator -> " << x.id << std::endl;
//             id = x.id;
//             return *this;
//             }
// };

// int A::i = 0;

int main23()
{
    // A arr[] = {A(), A(), A(), A(), A()};

    // A   *p = arr;

    // std::cout << "_____________" << std::endl;
    // ft::vector<A> vec(input_iterator<A>(p), input_iterator<A>(p + 5));
    // std::cout << "_____________" << std::endl;

    return 0;




}

int main()
{

    std::cout << "********************" << std::endl;

    {
        std::cout << "\n\nresize function\n" << std::endl;

    std::cout << "********************" << std::endl;
        {
            ft::vector<A>  vec((size_t)7, 0);
    
            std::cout << "-------------------------****" << std::endl;
            vec.resize(2, A());
            std::cout << "****-------------------------" << std::endl;
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
        
            ft::vector<A>  vec((size_t)2, 0);

            std::cout << "-------------------------****" << std::endl;
            vec.resize(7, A());
            std::cout << "****-------------------------" << std::endl;

            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
                
            ft::vector<A>  vec((size_t)2, 0);
            std::cout << "-------------------------****" << std::endl;
            vec.resize(2, A());
            std::cout << "****-------------------------" << std::endl;
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
    }
    return 0;
}

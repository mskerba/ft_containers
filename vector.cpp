#include <iostream>
#include <type_traits>
#include <vector>
#include <unistd.h>
#include "vector.tmp"
#include "vector.hpp"
#include "ft_containers.hpp"


int main()
{
      {
        std::cout << "\n\nerase function\n" << std::endl;
        {
            ft::vector<A> myvector((size_t)6, 0);
        
            myvector.erase (myvector.begin());
            myvector.erase (myvector.begin() + 2);
            // myvector.erase (myvector.begin() + 5);
            // myvector.erase (myvector.begin() - 1);
        }
        // {
        //     ft::vector<A> myvector((size_t)6,0);
    
        //     std::cout << "::::::::::::::::::::::" << std::endl;
        
        //     myvector.erase (myvector.begin() + 4, myvector.begin() + 5);
        
        //     std::cout << "::::::::::::::::::::::" << std::endl;
        // }
    }
 /*  {
        std::cout << "\n\nINSERT function\n" << std::endl;
        {
            ft::vector<A> vec (4);
            vec.reserve(6);

            A a;
                std::cout << "\n\n*****************************\n" << std::endl;
            vec.insert(vec.begin() + 3, a);
                std::cout << "\n\n*****************************\n" << std::endl;
                std::cout << vec.capacity() << std::endl;
        }
        {
            ft::vector<A> vec (4);
            vec.reserve(6);

            A a;
                std::cout << "\n\n*****************************\n" << std::endl;
            vec.insert(vec.begin() + 4, a);
                std::cout << "\n\n*****************************\n" << std::endl;
                std::cout << vec.capacity() << std::endl;
        }
        {
            ft::vector<A> vec (4);
            vec.reserve(6);

            A a;
                std::cout << "\n\n*****************************\n" << std::endl;
            vec.insert(vec.begin(), a);
                std::cout << "\n\n*****************************\n" << std::endl;
                std::cout << vec.capacity() << std::endl;
        }
    }
    {
        std::cout << "\n\ninsert n function\n" << std::endl;
        {
            std::cout << "\nsize + n > capacity\n" << std::endl;
            ft::vector<A>  vec(4);
            A   a;

            vec.insert(vec.end(), 4, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin(), 4, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin() + 2, 6, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
        {
            std::cout << "\nsize + n <= capacity\n" << std::endl;
            ft::vector<A>  vec(10);
            vec.reserve(300);
            A   a;

            vec.insert(vec.begin(), 4, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.begin() + 2, 7, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.end() - 3, 9, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
            vec.insert(vec.end(), 2, a);
            std::cout << "capacity -> " << vec.capacity() << std::endl;
            std::cout << "size     -> " << vec.size()  << std::endl;
        }
    }
*/}

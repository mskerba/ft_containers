#include "vector.tmp"
#include "vector.hpp"
#include "ft_containers.hpp"
#include <vector>




int main()
{
    std::cout << sizeof(std::vector<char>) << "    ";
    std::cout <<  sizeof(ft::vector<char>);
    return 0;
    
    
    
    
    
    
    
    // ft::vector<int> vec((size_t)10, 5);
    // ft::vector<int>  son(vec);
    // std::vector<int> std_vec(10, 5);
    // std::vector<int> std_con(std_vec);

    // // vec.print();
    // std::cout << "//////////////\n";
    // // con.print();
    A arr[] = {1, 2, 951, 4, 5};
    // try
    // {
        // ft::vector<A> myVec(std::begin(arr), std::end(arr));
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\nstd vector\n\n";
    {
        std::vector<A> myVec(std::begin(arr), std::end(arr));
        std::cout << "-------------------------\n";
        std::vector<A> vec(3,2);
        std::cout << "------------------------\n";
        vec = myVec;
    std::cout<<"\n\ndestroy vector\n\n";
    }
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\nft vector\n\n";
    {
        ft::vector<A> myVec(std::begin(arr), std::end(arr));
        std::cout << "-------------------------\n";
        ft::vector<A> vec((size_t)3,2);
        std::cout << "------------------------\n";
        vec = myVec;
    std::cout<<"\n\ndestroy vector\n\n";
    }
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\naray destroy\n\n";
    
    //     // myVec.print();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // catch(...)
    // {
    //     std::cerr << "fdsjhfd\n";
    // }
    
}
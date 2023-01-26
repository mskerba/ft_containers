#include "vector.hpp"
#include "ft_containers.hpp"
#include <vector>



class   A
{
    public:
        static  int i;
        int id;
        A() {
            id = i++;
            std::cout << "default constructor -> " << id<< std::endl;
        }
        ~A() {
            std::cout << "destructor -> " << id << std::endl; 
            }
        A(const A &x) {
            std::cout << "copy constructor -> " << x.id << std::endl;
            id = x.id;
            }
        A &operator=(const A &x) {
            std::cout << "copy assignement operator -> " << x.id << std::endl;
            id = x.id;
            return *this;
            }
};



int main()
{
    ft::vector<int> vec((size_t)10, 5);
    // ft::vector<int>  son(vec);
    std::vector<int> std_vec(10, 5);
    std::vector<int> std_con(std_vec);

    // vec.print();
    std::cout << "//////////////\n";
    // con.print();
    int arr[] = {1, 2, 951, 4, 5};
    try
    {
        ft::vector<A> myVec(std::begin(arr), std::end(arr));
        myVec.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "fdsjhfd\n";
    }
    
}
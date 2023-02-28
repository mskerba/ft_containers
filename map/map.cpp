#include "map.hpp"
#include <unistd.h>
#include <map>
// #include <pair>

int main()
{
        {
            std::map<int, std::string> m1;
            std::map<int, std::string> m2;
            ft::map<int, std::string> ft_m1;
            ft::map<int, std::string> ft_m2;
            for (int i = 0; i < 1e6; ++i)
            {
                m1.insert(std::make_pair(i, "string1"));
                m2.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, "string1"));
                ft_m2.insert(ft::make_pair(i, "string2"));
            }

            m1 = m2;
            /*-----------------------------------------------------*/
            /*------------------ ft::map ---------------------*/
            std::cout << "db\n";
            ft_m1 = ft_m2;
            /*----------------------------------------------------*/
        }
}
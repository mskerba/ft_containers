#include <iostream>
#include <type_traits>
#include <vector>
#include "vector.hpp"
#include "../map/map.hpp"
#include "../utility/Red-Black-Tree.hpp"
#include "../utility/pair.hpp"
#include <stack>
#include <map>
#include <unistd.h>

#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <signal.h>
#include <sys/time.h>
#include <random>

#include <iostream>
#include <map>


int main()
{
  std::map<int, std::string> m3;
  ft::map<int, std::string> ft_m3;
  std::vector<int> vec;
  std::vector<int> ft_vec;
  std::random_device randDev;
  std::mt19937 generator(randDev());
  std::uniform_int_distribution<int> distr(0, 1e8);

  std::cout << "-----------insert--------------\n";
  for (size_t i = 0; i < 1e6; i++)
  {
      m3.insert(std::make_pair(i, "string1"));
      ft_m3.insert(ft::make_pair(i, "string1"));
  }
  std::cout << "-----------erase--------------\n";
  for (size_t i = 0; i < 1e6; ++i)
  {
      int n = distr(generator);
      int ret1 = m3.erase(n);
      std::cout << n <<std::endl;
      int ret2 = ft_m3.erase(n);
      std::cout << n <<std::endl;

      if (ret1 != ret2)
      {
          std::cout << "hadchi 3yan\n";
          break;
      }
  }
}












int ma1in ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;
  ft::map<char,int> s;
  ft::map<char,int>::iterator its;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;
  s['a']=50;
  s['b']=100;
  s['c']=150;
  s['d']=200;

  it = mymap.find('d');
  its = s.find('d');
  if (it != mymap.end())
    mymap.erase (it);
  if (its != s.end())
    s.erase (its);

    it = mymap.find('a');
    its = s.find('a');
    std::cout << "    | " << (it)->first << " |. " <<std::endl;
    std::cout << "    | " << (its)->first << " |. " <<std::endl;
  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  return 0;
}
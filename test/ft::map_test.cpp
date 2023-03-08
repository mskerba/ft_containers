#include <map>
#include "../ft_containers/map/map.hpp"
#include <iostream>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}
struct classcomp {
bool operator() (const char& lhs, const char& rhs) const
{return lhs<rhs;}
};
void main()
{
    // constructing maps

    {
    ft::map<char,int> first;
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;
    ft::map<char,int> second (first.begin(),first.end());
    ft::map<char,int> third (second);
    ft::map<char,int,classcomp> fourth;                 // class as Compare
    bool(*fn_pt)(char,char) = fncomp;
    ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    }


    // map::at
    {
    ft::map<std::string,int> mymap = {
                    { "alpha", 0 },
                    { "beta", 0 },
                    { "gamma", 0 } };
    mymap.at("alpha") = 10;
    mymap.at("beta") = 20;
    mymap.at("gamma") = 30;
    for (auto& x: mymap) {
        std::cout << x.first << ": " << x.second << '\n';
    }
    }


    // map::begin/end
    {
    ft::map<char,int> mymap;
    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;
    // show content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }


    // map::empty
    {
    ft::map<char,int> mymap;
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    while (!mymap.empty())
    {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
    }
    }


    // map::begin/end
    {
    ft::map<char,int> mymap;
    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;
    // show content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }


    // map::equal_range
    {
    ft::map<char,int> mymap;
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');
    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';
    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }


    // erasing from map
    {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;
    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;
    it=mymap.find('b');
    mymap.erase (it);                   // erasing by iterator
    mymap.erase ('c');                  // erasing by key
    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );    // erasing by range
    // show content:
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }


    // map::find
    {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;
    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;
    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);
    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
    }


    // map::get_allocator
    {
    int psize;
    ft::map<char,int> mymap;
    std::pair<const char,int>* p;
    // allocate an array of 5 elements using mymap's allocator:
    p=mymap.get_allocator().allocate(5);
    // assign some values to array
    psize = sizeof(ft::map<char,int>::value_type)*5;
    std::cout << "The allocated array has a size of " << psize << " bytes.\n";
    mymap.get_allocator().deallocate(p,5);
    }


    // map::insert (C++98)
    {
    ft::map<char,int> mymap;
    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );
    std::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( std::pair<char,int>('z',500) );
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }
    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));
    // showing contents:
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }


    // map::key_comp
    {
    ft::map<char,int> mymap;
    ft::map<char,int>::key_compare mycomp = mymap.key_comp();
    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;
    std::cout << "mymap contains:\n";
    char highest = mymap.rbegin()->first;     // key value of last element
    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) );
    std::cout << '\n';
    }


    // map::lower_bound/upper_bound
    {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;
    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)
    mymap.erase(itlow,itup);        // erases [itlow,itup)
    // print content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }


    // map::max_size
    {
    int i;
    ft::map<int,int> mymap;
    if (mymap.max_size()>1000)
    {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";
    }


    // accessing mapped values
    {
    ft::map<char,std::string> mymap;
    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];
    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';
    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }


    // assignment operator with maps
    {
    ft::map<char,int> first;
    ft::map<char,int> second;
    first['x']=8;
    first['y']=16;
    first['z']=32;
    second=first;                // second now contains 3 ints
    first=ft::map<char,int>();  // and first is now empty
    std::cout << "Size of first: " << first.size() << '\n';
    std::cout << "Size of second: " << second.size() << '\n';
    }


    // map::rbegin/rend
    {
    ft::map<char,int> mymap;
    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;
    // show content:
    ft::map<char,int>::reverse_iterator rit;
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';
    }


    // map::rbegin/rend
    {
    ft::map<char,int> mymap;
    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;
    // show content:
    ft::map<char,int>::reverse_iterator rit;
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';
    }


    // map::size
    {
    ft::map<char,int> mymap;
    mymap['a']=101;
    mymap['b']=202;
    mymap['c']=302;
    std::cout << "mymap.size() is " << mymap.size() << '\n';
    }


    // swap maps
    {
    ft::map<char,int> foo,bar;
    foo['x']=100;
    foo['y']=200;
    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    foo.swap(bar);
    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }


    // map::lower_bound/upper_bound
    {
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;
    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;
    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)
    mymap.erase(itlow,itup);        // erases [itlow,itup)
    // print content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }


    template <class Key, class T, class Compare, class Alloc>
    class map<Key,T,Compare,Alloc>::value_compare
    {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
    friend class map;
    protected:
    Compare comp;
    value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
    public:
    typedef bool result_type;
    typedef value_type first_argument_type;
    typedef value_type second_argument_type;
    bool operator() (const value_type& x, const value_type& y) const
    {
        return comp(x.first, y.first);
    }
    }
    // map::value_comp
    {
    ft::map<char,int> mymap;
    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;
    std::cout << "mymap contains:\n";
    std::pair<char,int> highest = *mymap.rbegin();          // last element
    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mymap.value_comp()(*it++, highest) );
    }




    // swap maps
    {
    ft::map<char,int> foo,bar;
    foo['x']=100;
    foo['y']=200;
    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    foo.swap(bar);
    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }
}

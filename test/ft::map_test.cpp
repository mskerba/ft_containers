#include <map>
#include "../map/map.hpp"
#include <iostream>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}
struct classcomp {
bool operator() (const char& lhs, const char& rhs) const
{return lhs<rhs;}
};
int  main()
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
    return 0;
}

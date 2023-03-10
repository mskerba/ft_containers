#include <vector>
#include <iostream>

int main()
{
      // vector assign
  {
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;
    first.assign (7,100);             // 7 ints with a value of 100
    std::vector<int>::iterator it;
    it=first.begin()+1;
    second.assign (it,first.end()-1); // the 5 central values of first
    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.
    std::cout << "Size of first: " << int (first.size()) << '\n';
    std::cout << "Size of second: " << int (second.size()) << '\n';
    std::cout << "Size of third: " << int (third.size()) << '\n';
  }


  // vector::at
  {
    std::vector<int> myvector (10);   // 10 zero-initialized ints
    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
      myvector.at(i)=i;
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
      std::cout << ' ' << myvector.at(i);
    std::cout << '\n';
  }


  // vector::back
  {
    std::vector<int> myvector;
    myvector.push_back(10);
    while (myvector.back() != 0)
    {
      myvector.push_back ( myvector.back() -1 );
    }
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size() ; i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
  }


  // vector::begin/end
  {
    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }


  // comparing size, capacity and max_size
  {
    std::vector<int> myvector;
    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);
    std::cout << "size: " << (int) myvector.size() << '\n';
    std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    std::cout << "max_size: " << (int) myvector.max_size() << '\n';
  }


  // vector::data
  {
    std::vector<int> myvector (5);
    int* p = myvector.data();
    *p = 10;
    ++p;
    *p = 20;
    p[2] = 100;
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
  }


  // vector::empty
  {
    std::vector<int> myvector;
    int sum (0);
    for (int i=1;i<=10;i++) myvector.push_back(i);
    while (!myvector.empty())
    {
      sum += myvector.back();
      myvector.pop_back();
    }
    std::cout << "total: " << sum << '\n';
  }


  // vector::begin/end
  {
    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }


  // erasing from vector
  {
    std::vector<int> myvector;
    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) myvector.push_back(i);
    // erase the 6th element
    myvector.erase (myvector.begin()+5);
    // erase the first 3 elements:
    myvector.erase (myvector.begin(),myvector.begin()+3);
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
  }


  // vector::front
  {
    std::vector<int> myvector;
    myvector.push_back(78);
    myvector.push_back(16);
    // now front equals 78, and back 16
    myvector.front() -= myvector.back();
    std::cout << "myvector.front() is now " << myvector.front() << '\n';
  }


  // vector::get_allocator
  {
    std::vector<int> myvector;
    int * p;
    unsigned int i;
    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);
    // construct values in-place on the array:
    for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';
    // destroy and deallocate:
    for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p,5);
  }


  // comparing size, capacity and max_size
  {
    std::vector<int> myvector;
    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);
    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";
  }


  // vector::operator[]
  {
    std::vector<int> myvector (10);   // 10 zero-initialized elements
    std::vector<int>::size_type sz = myvector.size();
    // assign some values:
    for (unsigned i=0; i<sz; i++) myvector[i]=i;
    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
      int temp;
      temp = myvector[sz-1-i];
      myvector[sz-1-i]=myvector[i];
      myvector[i]=temp;
    }
    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
  }


  // vector assignment
  {
    std::vector<int> foo (3,0);
    std::vector<int> bar (5,0);
    bar = foo;
    foo = std::vector<int>();
    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
  }


  // vector::pop_back
  {
    std::vector<int> myvector;
    int sum (0);
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);
    while (!myvector.empty())
    {
      sum+=myvector.back();
      myvector.pop_back();
    }
    std::cout << "The elements of myvector add up to " << sum << '\n';
  }

// vector::push_back
    {
      std::vector<int> myvector;
      int myint = 100;
      while(--myint)
          myvector.push_back (myint);
      std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    }


  // vector::rbegin/rend
  {
    std::vector<int> myvector (5);  // 5 default-constructed ints
    int i=0;
    std::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
      *rit = ++i;
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }


  // vector::rbegin/rend
  {
    std::vector<int> myvector (5);  // 5 default-constructed ints
    std::vector<int>::reverse_iterator rit = myvector.rbegin();
    int i=0;
    for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
      *rit = ++i;
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }


  // vector::reserve
  {
    std::vector<int>::size_type sz;
    std::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
      foo.push_back(i);
      if (sz!=foo.capacity()) {
        sz = foo.capacity();
        std::cout << "capacity changed: " << sz << '\n';
      }
    }
    std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
      bar.push_back(i);
      if (sz!=bar.capacity()) {
        sz = bar.capacity();
        std::cout << "capacity changed: " << sz << '\n';
      }
    }
  }


  // resizing vector
  {
    std::vector<int> myvector;
    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);
    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);
    std::cout << "myvector contains:";
    for (size_t i=0;i < myvector.size();i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
  }


  // vector::size
  {
    std::vector<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';
    for (int i=0; i<10; i++) myints.push_back(i);
    std::cout << "1. size: " << myints.size() << '\n';
    myints.insert (myints.end(),10,100);
    std::cout << "2. size: " << myints.size() << '\n';
    myints.pop_back();
    std::cout << "3. size: " << myints.size() << '\n';
  }


  // swap vectors
  {
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200
    foo.swap(bar);
    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
      std::cout << ' ' << foo[i];
    std::cout << '\n';
    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
      std::cout << ' ' << bar[i];
    std::cout << '\n';
  }




  // swap vectors
  {
    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200
    foo.swap(bar);
    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
      std::cout << ' ' << foo[i];
    std::cout << '\n';
    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
      std::cout << ' ' << bar[i];
    std::cout << '\n';
  }
  return 0;
}
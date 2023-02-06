# ifndef __ITERATOR_HPP
# define __ITERATOR_HPP
// #include <iostream>
// #include <memory>

// # include "vector.hpp"

template<typename T>
class ft::vector<T>::iterator
{
    private:
        pointer ptr;
    public:
        iterator ();
        iterator (pointer p);
        iterator (const iterator& x);
        iterator& operator= (const iterator& x);
        bool operator== (const iterator& x) const;
        bool operator!= (const iterator& x) const;
        reference operator* () const;
        pointer operator-> () const;
        iterator& operator++ ();
        iterator& operator-- ();
        iterator& operator++ (int);
        iterator& operator-- (int);
        friend iterator operator+ (difference_type n, const iterator& it);
        iterator operator- (const iterator& it);
        iterator operator+ (difference_type n);
        iterator operator- (difference_type n);
        bool operator< (const iterator& x) const;
        bool operator> (const iterator& x) const;
        bool operator>= (const iterator& x) const;
        bool operator<= (const iterator& x) const;
        iterator& operator+= (difference_type n) const;
        iterator& operator-= (difference_type n) const;
        T& operator[] (difference_type n) const;
};

#endif

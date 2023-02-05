# ifndef __ITERATOR_HPP
# define __ITERATOR_HPP
# include "vector.hpp"

template<class T>
class ft::vector<T>::iterator
{
    private:
        pointer ptr;
    public:
        iterator ();
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
        iterator operator+ (const iterator& x);
        iterator operator- (const iterator& x);
        iterator operator+ (const int& n);
        iterator operator- (const int& n);
        bool operator< (const iterator& x) const;
        bool operator> (const iterator& x) const;
        bool operator>= (const iterator& x) const;
        bool operator<= (const iterator& x) const;
        iterator& operator+= (const iterator& x) const;
        iterator& operator-= (const iterator& x) const;
        T& operator[] (const int n) const;
};

#endif

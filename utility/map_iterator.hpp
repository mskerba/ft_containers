# ifndef __MAP_ITERATOR_HPP__
# define __MAP_ITERATOR_HPP__
# include <iostream>
# include <functional>
# include "Red-Black-Tree.hpp"

template <typename K, typename V>
class map_iterator
{
    public:
        typedef   K                     node;
        typedef   V                     value_type;
        typedef   value_type*           pointer;
        typedef   value_type&           reference;
    
    public:
    map_iterator():__ptr(0){}
    map_iterator(node *p) : __ptr(p) {}

    // Dereference operators
    reference operator*() const { return *__ptr->__val; }
    pointer operator->() const { return &(operator*()); }

    // Increment operators
    map_iterator& operator++()
    {
        if (__ptr->__right)
            __ptr = Min(__ptr->__right);
        else
            while (__ptr->__parent && __ptr == __ptr->__parent->__left)
                __ptr = __ptr->__parent;
        return (*this);
    }
    
    map_iterator& operator--()
    {
        if(__ptr->__left)
            __ptr = Max(__ptr->__right);
        else
            while (__ptr->__parent && __ptr == __ptr->__parent->__right)
                __ptr = __ptr->__parent;
        return (*this);
    }

    map_iterator operator++(int) {
        map_iterator tmp(*this);
        (*this)++;
        return tmp;
    }

    map_iterator operator--(int) {
        map_iterator tmp(*this);
        (*this)--;
        return tmp;
    }

    // Comparison operators
    bool operator==(const map_iterator& rhs) const { return __ptr == rhs.__ptr; }
    bool operator!=(const map_iterator& rhs) const { return !(*this == rhs); }

    private:
        node    *__ptr;
        node* min(node *z)
        {
            while(z->__left)
                z = z->__left;
            return (z);
        }
        node* max(node *z)
        {
            while(z->__right)
                z = z->__right;
            return (z);
        }
};



#endif

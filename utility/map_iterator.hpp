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
    map_iterator(node *p, node* root) : __ptr(p), __root(root) {}



    template < class cK, class cV>
    friend class map_iterator;

    template < class cK, class cV>
    map_iterator (const map_iterator<cK, cV>& x) : __ptr(x.__ptr){}

    template < class cK, class cV>
    map_iterator<cK, cV>& operator= (const map_iterator& x)
    {
        this->__ptr = x.__ptr;
        return (*this);
    }

    // Dereference operators
    reference operator*() const { return *(__ptr->__val); }
    pointer operator->() const { return &(operator*()); }

    // Increment operators
    map_iterator& operator++()
    {
        if (!__ptr)
            return (*this);
        if (__ptr->__right)
            __ptr = Min(__ptr->__right);
        else if (__ptr->__parent && __ptr == __ptr->__parent->__right)
        {
            while (__ptr->__parent && __ptr == __ptr->__parent->__right)
                __ptr = __ptr->__parent;
            __ptr = __ptr->__parent;
        }
        else
            __ptr = __ptr->__parent;
        return (*this);
    }
    
    map_iterator& operator--()
    {
        if (!__ptr)
            __ptr = Max(__root);
        else if (__ptr->__left)
            __ptr = Max(__ptr->__left);
        else if (__ptr->__parent && __ptr == __ptr->__parent->__left)
        {
            while (__ptr->__parent && __ptr == __ptr->__parent->__left)
                __ptr = __ptr->__parent;
            __ptr = __ptr->__parent;
        }
        else
            __ptr = __ptr->__parent;;
        return (*this);
    }

    map_iterator operator++(int)
    {
        map_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    map_iterator operator--(int)
    {
        map_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    // Comparison operators
    bool operator==(const map_iterator& rhs) const { return __ptr == rhs.__ptr; }
    bool operator!=(const map_iterator& rhs) const { return !(*this == rhs); }

    private:
        node    *__ptr;
        node    *__root;
        node*   Min(node *z)
        {
            while(z->__left)
                z = z->__left;
            return (z);
        }
        node*   Max(node *z)
        {
            while(z->__right)
                z = z->__right;
            return (z);
        }
};



#endif

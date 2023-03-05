# ifndef __SET_ITERATOR_HPP__
# define __SET_ITERATOR_HPP__
# include <iostream>
# include <functional>
# include "RBT_set.hpp"

template <typename K, typename V>
class set_iterator
{
    public:
        typedef   std::bidirectional_iterator_tag              iterator_category;
        typedef   K                                            node;
        typedef   V                                            value_type;
        typedef   value_type*                                  pointer;
        typedef   value_type&                                  reference;
        typedef   ptrdiff_t                                    difference_type;
        typedef   size_t                                       size_type;
    
    public:
    set_iterator():__ptr() , __root(){}
    set_iterator(node *p, node* root) : __ptr(p), __root(root) {}


    template < typename cK, typename cV>
    friend class set_iterator;

    template < typename cK, typename cV>
    set_iterator (const set_iterator<cK, cV>& x) : __ptr(x.__ptr), __root(x.__root){}

    template < typename cK, typename cV>
    set_iterator<cK, cV>& operator= (const set_iterator& x)
    {
        this->__ptr = x.__ptr;
        this->__root = x.__root;
        return (*this);
    }

    // Dereference operators
    reference operator*() const { return *(__ptr->__val); }
    pointer operator->() const { return &(operator*()); }

    // Increment operators
    set_iterator& operator++()
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
    
    set_iterator& operator--()
    {
        if (!__ptr)
            __ptr = __root;
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

    set_iterator operator++(int)
    {
        set_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    set_iterator operator--(int)
    {
        set_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    // Comparison operators
    template < typename _K, typename _P, typename _V>
        friend bool operator==(const set_iterator<_K, _V>& lhs, const set_iterator<_P, _V>& rhs) { return (lhs.__ptr == rhs.__ptr); }

    template < typename _K, typename _P, typename _V>
        friend bool operator!=(const set_iterator<_K, _V>& lhs, const set_iterator<_P, _V>& rhs) { return !(lhs == rhs); }

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
            while(z && z->__right)
                z = z->__right;
            return (z);
        }
};



#endif
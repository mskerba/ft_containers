# ifndef __biterator_HPP__
# define __biterator_HPP__
# include <iostream>
# include <functional>
// # include "Red-Black-Tree.hpp"


template < class Key, class T, class Compare>
class bidirectional
{
    public:
        // typedef   Category                                      iterator_category;
        typedef   Key                                           key_type;
        typedef   Compare                                       key_compare;
        typedef   T                                             mapped_type;
        typedef   ft::pair<const key_type,mapped_type>          value_type;
        typedef   ptrdiff_t                                     difference_type;
        typedef   value_type*                                   pointer;
        typedef   value_type&                                   reference;

    public:
        bidirectional();
        bidirectional(RBT<key_type, mapped_type, key_compare>    p);

        template < class cKey, class cT, class cCompare>
        friend class bidirectional;

        template < class cKey, class cT, class cCompare>
        bidirectional (const bidirectional<cKey, cT, cCompare>& x) : __ptr(x.__ptr){}

        template < class cKey, class cT, class cCompare>
        bidirectional<cKey, cT, cCompare>& operator= (const bidirectional<cKey, cT, cCompare>& x)
        {
            this->__ptr = x.__ptr;
            return (*this);
        }

        bool operator== (const bidirectional& x) const;
        bool operator!= (const bidirectional& x) const;

        reference operator* () const;
        pointer operator-> () const;
        bidirectional& operator++ ();
        bidirectional& operator-- ();
        bidirectional operator++ (int);
        bidirectional operator-- (int);
    private:
        RBT<key_type, mapped_type, key_compare>      __ptr;
};

/***********************************************/
/*                default constructor          */
/***********************************************/

template < class Key, class T, class Compare>
bidirectional<Key, T, Compare>::bidirectional (){}

/***********************************************/
/*            parametrize constructor          */
/***********************************************/

template < typename Key, typename T, typename Compare>
bidirectional<Key, T, Compare>::bidirectional(RBT<key_type, mapped_type, key_compare>    p): __ptr(p){}

/***********************************************/
/*                  operator==                 */
/***********************************************/

template < class Key, class T, class Compare>
bool bidirectional<Key, T, Compare>::operator== (const bidirectional& x) const
{
    return (this->__ptr == x.__ptr);
}

/***********************************************/
/*                  operator!=                 */
/***********************************************/

template < class Key, class T, class Compare>
bool bidirectional<Key, T, Compare>::operator!= (const bidirectional& x) const
{
    return !(*this == x);
}

/***********************************************/
/*                  operator*                 */
/***********************************************/

template < class Key, class T, class Compare>
typename bidirectional<Key, T, Compare>::reference bidirectional<Key, T, Compare>::operator* () const
{
    return (*__ptr);
}

/***********************************************/
/*                  operator->                 */
/***********************************************/

template < class Key, class T, class Compare>
typename bidirectional<Key, T, Compare>::pointer bidirectional<Key, T, Compare>::operator-> () const
{
    return (__ptr);
}


/***********************************************/
/*                  operator++                 */
/***********************************************/

template < class Key, class T, class Compare>
bidirectional<Key, T, Compare>& bidirectional<Key, T, Compare>::operator++ ()
{
    if(__ptr.__root->__right)
        __ptr.__root = __ptr.Minimum(__ptr.__root->__right);
    else
        while (__ptr.__root->__parent && __ptr.__root == __ptr.__root->__parent->__left)
            __ptr = __ptr.__root->__parent;
    return (*this);
}

/***********************************************/
/*                  operator--                 */
/***********************************************/

template < class Key, class T, class Compare>
bidirectional<Key, T, Compare>& bidirectional<Key, T, Compare>::operator-- ()
{
    if(__ptr.__root->__left)
        __ptr.__root = __ptr.Maximum(__ptr.__root->__right);
    else
        while (__ptr.__root->__parent && __ptr.__root == __ptr.__root->__parent->__right)
            __ptr = __ptr.__root->__parent;
    return (*this);
}

/***********************************************/
/*                  ++operator                 */
/***********************************************/

template < class Key, class T, class Compare>
bidirectional<Key, T, Compare> bidirectional<Key, T, Compare>::operator++ (int)
{
    bidirectional tmp = (*this);
    (*this)++;
    return (tmp);
}

/***********************************************/
/*                  --operator                 */
/***********************************************/

template < class Key, class T, class Compare>
bidirectional<Key, T, Compare> bidirectional<Key, T, Compare>::operator-- (int)
{
    bidirectional tmp = (*this);
    (*this)--;
    return (tmp);
}


#endif

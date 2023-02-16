# ifndef __ITERATOR__HPP
# define __ITERATOR__HPP
# include <iostream>

template <typename T, typename Category = std::random_access_iterator_tag >
class Iterator
{
    public:
        typedef   Category                         iterator_category;
        typedef   T                                value_type;
        typedef   ptrdiff_t                        difference_type;
        typedef   T*                               pointer;
        typedef   T&                               reference;
    
    public:
        Iterator ();
        Iterator (pointer p);

        template<typename cT, typename _Category>
        friend class Iterator;

        template<typename cT>
        Iterator (const Iterator<cT>& x) : __ptr(x.__ptr){}

        template<typename cT>
        Iterator<cT>& operator= (const T& x)
        {
            this->__ptr = x.__ptr;
            return (*this);
        }

        bool operator== (const Iterator& x) const;
        bool operator!= (const Iterator& x) const;
        reference operator* () const;
        pointer operator-> () const;
        Iterator& operator++ ();
        Iterator& operator-- ();
        Iterator operator++ (int);
        Iterator operator-- (int);
        difference_type operator- (const Iterator& it);
        Iterator operator+ (difference_type n) const;
        Iterator operator- (difference_type n) const;
        bool operator< (const Iterator& x) const;
        bool operator> (const Iterator& x) const;
        bool operator>= (const Iterator& x) const;
        bool operator<= (const Iterator& x) const;
        Iterator& operator+= (difference_type n);
        Iterator& operator-= (difference_type n);
        reference operator[] (difference_type n) const;

    private:
        pointer __ptr;
};

/***********************************************/
/*                  operator+                  */
/***********************************************/

template<typename T>
Iterator<T> operator+ (typename Iterator<T>::difference_type n, const Iterator<T>& it)
{
    Iterator<T> it1(it);
    return (it1 + n);
}

/***********************************************/
/*                default constructor          */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category>::Iterator (){}

/***********************************************/
/*            parametrize constructor          */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category>::Iterator (Iterator<T, Category>::pointer p): __ptr(p){}

/***********************************************/
/*               copy constructor              */
/***********************************************/

// template<typename T, typename Category>
// Iterator<T, Category>::Iterator (const Iterator<T, Category>& x):__ptr(x.__ptr){}

/***********************************************/
/*                 operator=                   */
/***********************************************/

// template<typename T, typename Category>
// Iterator<T, Category>& Iterator<T, Category>::operator= (const Iterator<T, Category>& x)
// {
//     this->__ptr = x.__ptr;
//     return (*this);
// }

/***********************************************/
/*                 operator==                  */
/***********************************************/

template<typename T, typename Category>
bool    Iterator<T, Category>::operator== (const Iterator<T, Category>& x) const
{
    if (this->__ptr == x.__ptr) return (true);
    return (false);
}

/***********************************************/
/*                 operator!=                  */
/***********************************************/

template<typename T, typename Category>
bool    Iterator<T, Category>::operator!= (const Iterator<T, Category>& x) const
{
    if (this->__ptr != x.__ptr) return (true);
    return (false);
}

/***********************************************/
/*                 operator>=                  */
/***********************************************/

template<typename T, typename Category>
bool    Iterator<T, Category>::operator>= (const Iterator<T, Category>& x) const
{
    if (this->__ptr >= x.__ptr) return (true);
    return (false);
}

/***********************************************/
/*                 operator<=                  */
/***********************************************/

template<typename T, typename Category>
bool    Iterator<T, Category>::operator<= (const Iterator<T, Category>& x) const
{
    if (this->__ptr <= x.__ptr) return (true);
    return (false);
}

/***********************************************/
/*                  operator<                  */
/***********************************************/

template<typename T, typename Category>
bool    Iterator<T, Category>::operator< (const Iterator<T, Category>& x) const
{
    if (this->__ptr < x.__ptr) return (true);
    return (false);
}

/***********************************************/
/*                  operator>                  */
/***********************************************/

template<typename T, typename Category>
bool    Iterator<T, Category>::operator> (const Iterator<T, Category>& x) const
{
    if (this->__ptr > x.__ptr) return (true);
    return (false);
}

/***********************************************/
/*                  operator*                  */
/***********************************************/

template<typename T, typename Category>
typename Iterator<T, Category>::reference Iterator<T, Category>::operator* () const
{
    return (*__ptr);
}

/***********************************************/
/*                 operator->                  */
/***********************************************/

template<typename T, typename Category>
typename Iterator<T, Category>::pointer Iterator<T, Category>::operator-> () const
{
    return (__ptr);
}

/***********************************************/
/*                 operator++                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator++ ()
{
    ++__ptr;
    return (*this);
}

/***********************************************/
/*                 operator--                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator-- ()
{
    --__ptr;
    return (*this);
}

/***********************************************/
/*                 ++operator                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator++ (int)
{
    Iterator tmp =(*this);

    ++(__ptr);
    return (tmp);
}

/***********************************************/
/*                 --operator                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator-- (int)
{
    Iterator tmp = (*this);

    --(__ptr);
    return (tmp);
}

/***********************************************/
/*                 operator+=                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator+= (typename Iterator<T, Category>::difference_type n)
{
    __ptr += n;
    return (*this);
}

/***********************************************/
/*                 operator-=                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator-= (typename Iterator<T, Category>::difference_type n)
{
    __ptr -= n;
    return (*this);
}

/***********************************************/
/*                 operator[]                  */
/***********************************************/

template<typename T, typename Category>
T& Iterator<T, Category>::operator[] (typename Iterator<T, Category>::difference_type n) const
{
    return (this->__ptr[n]);
}

/***********************************************/
/*                  operator-                  */
/***********************************************/

template<typename T, typename Category>
typename Iterator<T, Category>::difference_type Iterator<T, Category>::operator- (const Iterator<T, Category>& it)
{
    return this->__ptr - it.__ptr;
}

/***********************************************/
/*                  operator+                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator+ (typename Iterator<T, Category>::difference_type n) const
{
    return (Iterator(__ptr + n));
}

/***********************************************/
/*                  operator-                  */
/***********************************************/

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator- (typename Iterator<T, Category>::difference_type n) const
{
    return (Iterator(__ptr - n));
}

#endif
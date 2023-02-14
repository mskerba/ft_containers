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
        Iterator (const Iterator& x);
        Iterator& operator= (const Iterator& x);
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

template<typename T>
Iterator<T> operator+ (typename Iterator<T>::difference_type n, const Iterator<T>& it)
{
    Iterator<T> it1(it);
    return (it1 + n);
}

template<typename T, typename Category>
Iterator<T, Category>::Iterator (){}

template<typename T, typename Category>
Iterator<T, Category>::Iterator (Iterator<T, Category>::pointer p): __ptr(p){}

template<typename T, typename Category>
Iterator<T, Category>::Iterator (const Iterator<T, Category>& x):__ptr(x.__ptr){}

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator= (const Iterator<T, Category>& x)
{
    this->__ptr = x.__ptr;
    return (*this);
}

template<typename T, typename Category>
bool    Iterator<T, Category>::operator== (const Iterator<T, Category>& x) const
{
    if (this->__ptr == x.__ptr) return (true);
    return (false);
}

template<typename T, typename Category>
bool    Iterator<T, Category>::operator!= (const Iterator<T, Category>& x) const
{
    if (this->__ptr != x.__ptr) return (true);
    return (false);
}

template<typename T, typename Category>
bool    Iterator<T, Category>::operator>= (const Iterator<T, Category>& x) const
{
    if (this->__ptr >= x.__ptr) return (true);
    return (false);
}

template<typename T, typename Category>
bool    Iterator<T, Category>::operator<= (const Iterator<T, Category>& x) const
{
    if (this->__ptr <= x.__ptr) return (true);
    return (false);
}

template<typename T, typename Category>
bool    Iterator<T, Category>::operator< (const Iterator<T, Category>& x) const
{
    if (this->__ptr < x.__ptr) return (true);
    return (false);
}

template<typename T, typename Category>
bool    Iterator<T, Category>::operator> (const Iterator<T, Category>& x) const
{
    if (this->__ptr > x.__ptr) return (true);
    return (false);
}

template<typename T, typename Category>
typename Iterator<T, Category>::reference Iterator<T, Category>::operator* () const
{
    return (*__ptr);
}

template<typename T, typename Category>
typename Iterator<T, Category>::pointer Iterator<T, Category>::operator-> () const
{
    return (__ptr);
}

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator++ ()
{
    ++__ptr;
    return (*this);
}

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator-- ()
{
    --__ptr;
    return (*this);
}

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator++ (int)
{
    Iterator tmp =(*this);

    ++(__ptr);
    return (tmp);
}

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator-- (int)
{
    Iterator tmp = (*this);

    --(__ptr);
    return (tmp);
}

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator+= (typename Iterator<T, Category>::difference_type n)
{
    __ptr += n;
    return (*this);
}

template<typename T, typename Category>
Iterator<T, Category>& Iterator<T, Category>::operator-= (typename Iterator<T, Category>::difference_type n)
{
    __ptr -= n;
    return (*this);
}

template<typename T, typename Category>
T& Iterator<T, Category>::operator[] (typename Iterator<T, Category>::difference_type n) const
{
    return (this->__ptr[n]);
}

template<typename T, typename Category>
typename Iterator<T, Category>::difference_type Iterator<T, Category>::operator- (const Iterator<T, Category>& it)
{
    return this->__ptr - it.__ptr;
}

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator+ (typename Iterator<T, Category>::difference_type n) const
{
    return (Iterator(__ptr + n));
}

template<typename T, typename Category>
Iterator<T, Category> Iterator<T, Category>::operator- (typename Iterator<T, Category>::difference_type n) const
{
    return (Iterator(__ptr - n));
}

#endif
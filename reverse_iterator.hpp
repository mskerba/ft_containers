# ifndef __REVERSE_ITERATOR__HPP
# define __REVERSE_ITERATOR__HPP
#include "iterator_traits.hpp"


namespace ft
{
    template <typename Iterator> 
    class  reverse_iterator;
}

template <class Iterator>
class iterator_traits;

template <typename Iterator> 
class  reverse_iterator
{
    public:
        typedef Iterator                                                        iterator_type;
        typedef typename   iterator_traits<Iterator>::iterator_category	        iterator_category;
        typedef typename   iterator_traits<Iterator>::value_type	            value_type;
        typedef typename   iterator_traits<Iterator>::difference_type	        difference_type;
        typedef typename   iterator_traits<Iterator>::pointer	                pointer;
        typedef typename   iterator_traits<Iterator>::reference	                reference;

    public:
        reverse_iterator();
        explicit reverse_iterator (iterator_type it);
        reverse_iterator (const reverse_iterator& rev_it);
        iterator_type base() const;
        reference operator*() const;
        reverse_iterator operator+ (difference_type n) const;
        reverse_iterator operator- (difference_type n) const;
        difference_type operator- (const reverse_iterator& it);
        reverse_iterator& operator-= (difference_type n);
        reverse_iterator& operator+= (difference_type n);
        reverse_iterator& operator++();
        reverse_iterator  operator++(int);
        reverse_iterator& operator--();
        reverse_iterator  operator--(int);
        pointer operator->() const;
        reference operator[] (difference_type n) const;
        bool operator== (const reverse_iterator& rhs);
        bool operator!= (const reverse_iterator& rhs);
        bool operator<  (const reverse_iterator& rhs);
        bool operator<= (const reverse_iterator& rhs);
        bool operator>  (const reverse_iterator& rhs);
        bool operator>= (const reverse_iterator& rhs);

    private:
        Iterator __it;
};


template<typename Iterator>
reverse_iterator<Iterator>::reverse_iterator () :__it(){}

template<typename Iterator>
reverse_iterator<Iterator>::reverse_iterator (typename reverse_iterator<Iterator>::iterator_type it): __it(it){}

template<typename Iterator>
reverse_iterator<Iterator>::reverse_iterator (const reverse_iterator<Iterator>& rev_it):__it(rev_it.__it){}

template<typename Iterator>
typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const
{
    return (__it);
}

template<typename Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const
{
    return (*__it);
}

template<typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+ (typename reverse_iterator<Iterator>::difference_type n) const
{
    return (reverse_iterator(__it - n));
}

template<typename Iterator>
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator- (typename reverse_iterator<Iterator>::difference_type n) const
{
    return (reverse_iterator(__it + n));
}

template<typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+= (typename reverse_iterator<Iterator>::difference_type n)
{
    __it -= n;
    return (*this);
}

template<typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-= (typename reverse_iterator<Iterator>::difference_type n)
{
    __it += n;
    return (*this);
}

template<typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++()
{
    --__it;
    return (*this);
}

template<typename Iterator>
reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator++(int)
{
    reverse_iterator tmp(__it);
    __it--;
    return (tmp);
}

template<typename Iterator>
reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--()
{
    ++__it;
    return (*this);
}

template<typename Iterator>
reverse_iterator<Iterator>  reverse_iterator<Iterator>::operator--(int)
{
    reverse_iterator tmp(__it);
    __it++;
    return (tmp);
}

template<typename Iterator>
typename reverse_iterator<Iterator>::difference_type reverse_iterator<Iterator>::operator- (const reverse_iterator<Iterator>& rit)
{
    reverse_iterator tmp(rit.__it);
    return (tmp.__it - this->__it);
}


template<typename Iterator>
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const
{
    return (__it);
}

template<typename Iterator>
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[] (reverse_iterator<Iterator>::difference_type n) const
{
    return (__it[n]);
}

template <class Iterator>
bool reverse_iterator<Iterator>::operator== (const reverse_iterator<Iterator>& rhs)
{
    return (this->__it == rhs.__it);
}

template <class Iterator>
bool reverse_iterator<Iterator>::operator!= (const reverse_iterator<Iterator>& rhs)
{
    return (this->__it != rhs.__it);
}

template <class Iterator>
bool reverse_iterator<Iterator>::operator<  (const reverse_iterator<Iterator>& rhs)
{
    return (this->__it > rhs.__it);
}

template <class Iterator>
bool reverse_iterator<Iterator>::operator<= (const reverse_iterator<Iterator>& rhs)
{
    return (this->__it >= rhs.__it);
}

template <class Iterator>
bool reverse_iterator<Iterator>::operator>  (const reverse_iterator<Iterator>& rhs)
{
    return (this->__it < rhs.__it);
}

template <class Iterator>
bool reverse_iterator<Iterator>::operator>= (const reverse_iterator<Iterator>& rhs)
{
    return (this->__it <= rhs.__it);
}

template <class Iterator>
reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
    reverse_iterator<Iterator> tmp(rev_it.__it - n);
    return (tmp);
}

template <class Iterator>
reverse_iterator<Iterator> operator- (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
    reverse_iterator<Iterator> tmp(rev_it.__it + n);
    return (tmp);
}
#endif
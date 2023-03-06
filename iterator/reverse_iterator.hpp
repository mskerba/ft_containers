# ifndef __REVERSE_ITERATOR__HPP
# define __REVERSE_ITERATOR__HPP
#include "iterator_traits.hpp"


namespace ft
{
    template <typename Iterator> 
    class  reverse_iterator;
}

// template <class Iterator>
// class ft::iterator_traits;

template <typename Iterator> 
class  ft::reverse_iterator
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
        // reverse_iterator (const reverse_iterator& rev_it);

        template<typename cit>
        reverse_iterator (const reverse_iterator<cit>& rev_it) : __it(rev_it.base()){}

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
        template<typename Iterator1, typename Iterator2>
            friend bool operator== (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) { return (lhs.__it  == rhs.__it);}
        template<typename Iterator1, typename Iterator2>
            friend bool operator!= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) { return (lhs.__it  != rhs.__it);}
        template<typename Iterator1, typename Iterator2>
            friend bool operator<  (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) { return (lhs.__it  > rhs.__it);}
        template<typename Iterator1, typename Iterator2>
            friend bool operator<= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {return !(rhs < lhs);}
        template<typename Iterator1, typename Iterator2>
            friend bool operator>  (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {return (rhs < lhs);}
        template<typename Iterator1, typename Iterator2>
            friend bool operator>= (const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs) {return !(lhs < rhs);}

    private:
        Iterator __it;
};


template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator () :__it(){}

template<typename Iterator>
ft::reverse_iterator<Iterator>::reverse_iterator (typename ft::reverse_iterator<Iterator>::iterator_type it): __it(it){}

// template<typename Iterator>
// ft::reverse_iterator<Iterator>::reverse_iterator (const reverse_iterator<Iterator>& rev_it):__it(rev_it.__it){}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::iterator_type ft::reverse_iterator<Iterator>::base() const
{
    return (__it);
}

// template<typename Iterator>
// typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator*() const
// {
//     return (*(__it - 1));
// }

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator*() const
{
    Iterator tmp (__it);
    --tmp;
    return (*(tmp)); // ? return (*(__it - 1))
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator+ (typename ft::reverse_iterator<Iterator>::difference_type n) const
{
    return (reverse_iterator(__it - n));
}

template<typename Iterator>
ft::reverse_iterator<Iterator> ft::reverse_iterator<Iterator>::operator- (typename ft::reverse_iterator<Iterator>::difference_type n) const
{
    return (reverse_iterator(__it + n));
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator+= (typename ft::reverse_iterator<Iterator>::difference_type n)
{
    __it -= n;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator-= (typename ft::reverse_iterator<Iterator>::difference_type n)
{
    __it += n;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator++()
{
    --(__it);
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>  ft::reverse_iterator<Iterator>::operator++(int)
{
    reverse_iterator tmp(__it);
    __it--;
    return (tmp);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>& ft::reverse_iterator<Iterator>::operator--()
{
    ++__it;
    return (*this);
}

template<typename Iterator>
ft::reverse_iterator<Iterator>  ft::reverse_iterator<Iterator>::operator--(int)
{
    reverse_iterator tmp(__it);
    __it++;
    return (tmp);
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::difference_type ft::reverse_iterator<Iterator>::operator- (const reverse_iterator<Iterator>& rit)
{
    reverse_iterator tmp(rit.__it);
    return (tmp.__it - this->__it);
}


template<typename Iterator>
typename ft::reverse_iterator<Iterator>::pointer ft::reverse_iterator<Iterator>::operator->() const
{
    return &(this->operator*());
    // return (*__it);
}

template<typename Iterator>
typename ft::reverse_iterator<Iterator>::reference ft::reverse_iterator<Iterator>::operator[] (ft::reverse_iterator<Iterator>::difference_type n) const
{
    return (__it[-n - 1]);
}

template <class Iterator>
ft::reverse_iterator<Iterator> operator+ (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it)
{
    return (rev_it + n);
}

template <class Iterator>
ft::reverse_iterator<Iterator> operator- (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it)
{
    return (rev_it - n);
}


#endif
# ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__
# include <iostream>
# include <iterator>

template <typename Iterator>
class iterator_traits
{
    public:
        typedef  typename   Iterator::difference_type          difference_type;
        typedef  typename   Iterator::value_type               value_type;
        typedef  typename   Iterator::pointer                  pointer;
        typedef  typename   Iterator::reference                reference;
        typedef  typename   Iterator::iterator_category        iterator_category;
};

// template <class T>    
// class iterator_traits<T*>
// {
//     public:
//         typedef  typename   Iterator::difference_type          difference_type;
//         typedef  typename   Iterator::value_type               value_type;
//         typedef  typename   Iterator::pointer                  pointer;
//         typedef  typename   Iterator::reference                reference;
//         typedef  typename   Iterator::iterator_category        iterator_category;
// };

// template <class T>
// class iterator_traits<const T*>
// { 
//     public:
//         typedef  typename   Iterator::difference_type          difference_type;
//         typedef  typename   Iterator::value_type               value_type;
//         typedef  typename   Iterator::pointer                  pointer;
//         typedef  typename   Iterator::reference                reference;
//         typedef  typename   Iterator::iterator_category        iterator_category;
// };

#endif

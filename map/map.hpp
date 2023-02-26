# ifndef __MAP_HPP__
# define __MAP_HPP__
# include <iostream>
# include "../utility/Red-Black-Tree.hpp"
# include "../utility/pair.hpp"
# include <functional>



namespace ft{
    template < class Key, class T, class Compar, class Alloc>
    class map;
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class ft::map
{
    public:
        typedef        Key                                                            keytype;
        typedef        T                                                              mapped_type;
        typedef        ft::pair<const key_type,mapped_type>                           value_type;
        typedef        Compare                                                        key_compare;
        typedef        Alloc                                                          allocator_type;
	    typedef        typename allocator_type::reference                             reference;
	    typedef        typename allocator_type::const_reference                       const_reference;
	    typedef	       typename allocator_type::pointer                               pointer;
	    typedef        typename allocator_type::const_pointer	                      const_pointer;
        // ? typedef                   iterator;`
        // ? typedef                   const_iterator;
        // ? typedef                   reverse_iterator;
        // ? typedef                   const_reverse_iterator;
        typedef        ptrdiff_t                                                      difference_type;
        typedef        size_t                                                         size_type;

    public:
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        map (const map& x);

    private: // *data member
        pointer              __container;
        RBT<value_type>     *__root; 
        size_type            __size;

};


/***********************************************/
/*                default constructor          */
/***********************************************/

template < class Key, class T, class Compar, class Alloc>
ft::map<Key, T, Compar, Alloc>::map (const key_compare& comp, const allocator_type& alloc)
{

}

#endif

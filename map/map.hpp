# ifndef __MAP_HPP__
# define __MAP_HPP__
# include <iostream>
# include "../utility/Red-Black-Tree.hpp"
# include "../utility/pair.hpp"
# include "../utility/bidirectional_iterator.hpp"
# include <functional>



namespace ft{
    template < class Key, class T, class Compare, class Alloc>
    class map;
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class ft::map
{
    public:
        typedef        Key                                                            key_type;
        typedef        T                                                              mapped_type;
        typedef        ft::pair<const key_type,mapped_type>                           value_type;
        typedef        Compare                                                        key_compare;
        typedef        Alloc                                                          allocator_type;
	    typedef        typename allocator_type::reference                             reference;
	    typedef        typename allocator_type::const_reference                       const_reference;
	    typedef	       typename allocator_type::pointer                               pointer;
	    typedef        typename allocator_type::const_pointer	                      const_pointer;
        typedef        bidirectional<key_type, mapped_type, key_compare>              iterator;
        typedef        bidirectional<key_type, mapped_type, key_compare>              const_iterator;
        // ? typedef                   reverse_iterator;
        // ? typedef                   const_reverse_iterator;
        typedef        ptrdiff_t                                                      difference_type;
        typedef        size_t                                                         size_type;

    public:

        // ? default constructor
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

        // ?  range constructor
        template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
        
        // ?  copy constructor
        map (const map& x);

        // ?  destructor
        ~map();

        // ?  operator=
         map& operator= (const map& x);

        // ?  size
        size_type size() const;

        // ?  clear
        void clear();

        // ?  begin
        iterator begin();

        // ?  const begin
        const_iterator begin() const;

    // private: // *data member
        RBT<value_type, key_compare, allocator_type>     root; 
        size_type            __size;


    private: // *func member
        void delete_node(RBT<value_type, key_compare, allocator_type> n,const  allocator_type& _alloc)
        {
            if (!n) return;
            delete_node(n.__root->__left, _alloc);
            delete_node(n.__root->__right, _alloc);
            _alloc.destroy(&n);
            _alloc.deallocate(n, 1);
        }
};

/***********************************************/
/*                default constructor          */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map (const key_compare& comp, const allocator_type& alloc):__size(0){}

/***********************************************/
/*               range constructor             */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
template <class InputIterator>
    ft::map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
    {
        // if (size() < 0)
        //     throw  std::length_error("map");

        for (__size = 0; first != last; __size++)
            root.Insert(*(first++));
    }

/***********************************************/
/*                copy constructor             */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map (const map& x) :__size(x.size())
{
    this->root = x.root;
}

/***********************************************/
/*                destructor                   */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map()
{
    __size = 0;
    clear();
}

/***********************************************/
/*                operator=                    */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>& ft::map<Key, T, Compare, Alloc>::operator=(const map& x)
{
    this->root = x.root;
    __size = x.size();
    return (*this);
}

/***********************************************/
/*                   size                      */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::size() const
{
    return (this->__size);
}

/***********************************************/
/*                   clear                     */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::clear()
{
    root.clear_node(root.__root);
    __size = 0;
}

/***********************************************/
/*                   begin                     */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::begin()
{
    return ()
}

/***********************************************/
/*                 const begin                 */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::begin() const
{

}
#endif

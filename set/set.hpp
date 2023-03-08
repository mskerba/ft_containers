# ifndef ___SET__HPP__
# define ___SET__HPP__
# include <iostream>
# include <functional>
# include "../iterator/reverse_iterator.hpp"
# include "../utility/RBT_set.hpp"
# include "../utility/pair.hpp"

namespace ft{
    template < class Key, class Compare, class Alloc>
        class set;
    template <class Key, class Compare, class Alloc>
        void swap (ft::set<Key,Compare,Alloc>& x, ft::set<Key,Compare,Alloc>& y) { y.swap(x); }
}

template < class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
class ft::set
{
    public:
        typedef        Key                                                                                          key_type;
        typedef        key_type                                                                                     value_type;
        typedef        Compare                                                                                      key_compare;
        typedef        Compare                                                                                      value_compare;
        typedef        Alloc                                                                                        allocator_type;
	    typedef        typename allocator_type::reference                                                           reference;
	    typedef        typename allocator_type::const_reference                                                     const_reference;
	    typedef	       typename allocator_type::pointer                                                             pointer;
	    typedef        typename allocator_type::const_pointer	                                                    const_pointer;
        typedef        typename RBT_S<key_type, key_compare, allocator_type>::iterator                              iterator;
        typedef        typename RBT_S<key_type, key_compare, allocator_type>::const_iterator                        const_iterator;
        typedef        ft::reverse_iterator<iterator>                                                               reverse_iterator;
        typedef        ft::reverse_iterator<const_iterator>                                                         const_reverse_iterator;
        typedef        ptrdiff_t                                                                                    difference_type;
        typedef        size_t                                                                                       size_type;

    public:

        //  ? default constructor
        explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	
        //  ? range constructor
        template <class InputIterator>
            set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

        // ?  copy constructor
        set (const set& x);

        // ?  destructor
        ~set();

        // ?  operator=
         set& operator= (const set& x);

        // ? empty
        bool empty() const;

        // ?  size
        size_type size() const;

        // ? max_size
        size_type max_size() const;

        // ?  begin
        iterator begin();

        // ?  const begin
        const_iterator begin() const;

        // ?  end
        iterator end();

        // ?  const end
        const_iterator end() const;

        // ?  rbegin
        reverse_iterator rbegin();

        // ?  const rbegin
        const_reverse_iterator rbegin() const;

        // ?  rend
        reverse_iterator rend();

        // ?  const rend
        const_reverse_iterator rend() const;

        // ?  clear
        void clear();

        // ? insert
        ft::pair<iterator,bool> insert (const value_type& val);

        iterator insert (iterator position, const value_type& val);

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last);
        
        // ? insert
        void erase (iterator position);

        size_type erase (const value_type& val);

        void erase (iterator first, iterator last);

        // ? swap
        void swap (set& x);
        
        // ? key_comp
        key_compare key_comp() const;

        // ? value_comp
        value_compare value_comp() const;

        // ? get_allocator
        allocator_type get_allocator() const;
      
        // ? find
        iterator find (const value_type& val) const;


        // ? count
        size_type count (const key_type& k) const;

        // ? lower_bound
        iterator lower_bound (const key_type& k) const;

        // ? upper_bound
        iterator upper_bound (const key_type& k) const;

        // ? equal_range
        pair<iterator,iterator>   equal_range (const key_type& k) const;

    
        template <class _Key, class _Compare, class _Alloc>
            friend bool operator== ( const set<_Key,_Compare,_Alloc>& lhs, const set<_Key,_Compare,_Alloc>& rhs )
        {
            if (lhs.size() != rhs.size())
                return (false);
            typename ft::set<_Key,_Compare,_Alloc>::const_iterator it = lhs.begin(), it1 = rhs.begin();
            while ( it1 != rhs.end())
                if (*(it++) != *(it1++))
                    return (false);
            return (true);
        }

        template <class _Key, class _Compare, class _Alloc>
            friend bool operator!= ( const set<_Key,_Compare,_Alloc>& lhs, const set<_Key,_Compare,_Alloc>& rhs )  {return !(lhs == rhs);}

        template <class _Key, class _Compare, class _Alloc>
            friend bool operator<  ( const set<_Key,_Compare,_Alloc>& lhs, const set<_Key,_Compare,_Alloc>& rhs )
            {
                typename ft::set<_Key,_Compare,_Alloc>::const_iterator it = lhs.begin(), it1 = rhs.begin();
                while (it1 != rhs.end() && it != lhs.end())
                {
                    if (*it > *it1)
                        return (false);
                    if (*it < *it1)
                        return (true);
                    it++;
                    it1++;
                }
                if (lhs.size() < rhs.size())
                    return (true);
                return (false);
            }

        template <class _Key, class _Compare, class _Alloc>
            friend bool operator<= ( const set<_Key,_Compare,_Alloc>& lhs, const set<_Key,_Compare,_Alloc>& rhs ) {return !(rhs < lhs);}

        template <class _Key, class _Compare, class _Alloc>
            friend bool operator>  ( const set<_Key,_Compare,_Alloc>& lhs, const set<_Key,_Compare,_Alloc>& rhs ) { return (rhs < lhs);}

        template <class _Key, class _Compare, class _Alloc>
            friend bool operator>= ( const set<_Key,_Compare,_Alloc>& lhs, const set<_Key,_Compare,_Alloc>& rhs ) {return !(lhs < rhs);}

    // private: // *data member
        RBT_S<key_type, key_compare, allocator_type>     root;
        size_type            __size;
};


/***********************************************/
/*                default constructor          */
/***********************************************/

template < class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>::set (const key_compare& comp, const allocator_type& alloc):__size(0)
{
    (void)comp;
    (void)alloc;
}

/***********************************************/
/*               range constructor             */
/***********************************************/

template < class Key, class Compare, class Alloc>
template <class InputIterator>
    ft::set<Key, Compare, Alloc>::set (InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
    {
        (void)comp;
        (void)alloc;

        for (__size = 0; first != last; __size++)
            root.Insert(*(first++));
    }

/***********************************************/
/*                copy constructor             */
/***********************************************/

template < class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>::set (const set& x) :__size(x.size())
{
    this->root = x.root;
}

/***********************************************/
/*                destructor                   */
/***********************************************/

template < class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>::~set()
{
    clear();
}

/***********************************************/
/*                operator=                    */
/***********************************************/

template < class Key, class Compare, class Alloc>
ft::set<Key, Compare, Alloc>& ft::set<Key, Compare, Alloc>::operator=(const set& x)
{
    if (size())
        this->root = x.root;
    else
        this->root.in(x.root);
    __size = x.size();
    return (*this);
}

/***********************************************/
/*                   size                      */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::size() const
{
    return (this->__size);
}

/***********************************************/
/*                   clear                     */
/***********************************************/

template < class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::clear()
{
    if (size())
        root.clear_node(root.__root);
    root.__root = 0;
    __size = 0;
}
/***********************************************/
/*                 max_size                    */
/***********************************************/

template < class Key, class Compare, class Alloc>
size_t ft::set<Key, Compare, Alloc>::max_size() const
{
    int sizeT = sizeof(value_type);
    if (sizeT == 1)
        sizeT = 2;
    return (std::numeric_limits<std::size_t>::max() / sizeT);
    // return (MAX_SIZE_T / sizeT);
}

/***********************************************/
/*                   begin                     */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::begin()
{
    iterator tmp(this->root.Minimum(root.__root), root.__max);
    return (tmp);
}

/***********************************************/
/*                 const begin                 */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator ft::set<Key, Compare, Alloc>::begin() const
{
    return (const_iterator(root.Minimum(root.__root),root.__max));
}

/***********************************************/
/*                   end                     */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::end()
{
    return (iterator(nullptr, root.__max));
}

/***********************************************/
/*                 const end                   */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator ft::set<Key, Compare, Alloc>::end() const
{
    return (const_iterator(nullptr, root.__max));
}

/***********************************************/
/*                   rbegin                    */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::reverse_iterator ft::set<Key, Compare, Alloc>::rbegin()
{
    return reverse_iterator(end());
}

/***********************************************/
/*                 const rbegin                */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_reverse_iterator ft::set<Key, Compare, Alloc>::rbegin() const
{;
    return (const_reverse_iterator(end()));
}

/***********************************************/
/*                   rend                     */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::reverse_iterator ft::set<Key, Compare, Alloc>::rend()
{
    return (reverse_iterator(begin()));
}

/***********************************************/
/*                 const rend                 */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_reverse_iterator ft::set<Key, Compare, Alloc>::rend() const
{
    return (const_reverse_iterator(begin()));
}

/***********************************************/
/*                   empty                     */
/***********************************************/

template < class Key, class Compare, class Alloc>
bool ft::set<Key, Compare, Alloc>::empty() const
{
    if (this->root.__root)
        return (false);
    return (true);
}

/***********************************************/
/*                    insert                   */
/***********************************************/

template < class Key, class Compare, class Alloc>
ft::pair<typename ft::set<Key, Compare, Alloc>::iterator,bool> ft::set<Key, Compare, Alloc>::insert (const value_type& val)
{
    bool is = (root.Search(root.__root, val)) ? true : false;
    if (!is)   
    {
        this->__size++;
        this->root.Insert(val);
    }
    iterator it(root.Search(root.__root, val), root.__max);
    return (ft::make_pair(it, !is));
}

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::insert (iterator position, const value_type& val)
{
    (void) position;
    bool is = (root.Search(root.__root, val)) ? true : false;
    if (!is)   
    {
        this->__size++;
        this->root.Insert(val);
    }
    iterator it(root.Search(root.__root, val), root.__max);
    return (it);
}

template < class Key, class Compare, class Alloc>
template <class InputIterator>
void ft::set<Key, Compare, Alloc>::insert (InputIterator first, InputIterator last)
{
    while (first != last) this->insert(*(first++));
}

/***********************************************/
/*                    erase                    */
/***********************************************/

template < class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::erase (typename ft::set<Key, Compare, Alloc>::iterator position)
{
    if(size() == 1)
    {
        this->clear();
        return ;
    }
    value_type n = (*position);
    root.Delete(n);
    __size--;
}

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::erase (const typename ft::set<Key, Compare, Alloc>::key_type& k)
{
    RBT_S<Key, Compare, Alloc> z;
    z.__root = root.Search(root.__root, k);
    if (!z.__root)
        return (0);
    this->erase(iterator(z.__root, root.__max));
    return (1);
}

template < class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::erase (typename ft::set<Key, Compare, Alloc>::iterator first, typename ft::set<Key, Compare, Alloc>::iterator last)
{
    while (first != last)
        erase(first++);
}

/***********************************************/
/*                    swap                     */
/***********************************************/

template < class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::swap (ft::set<Key, Compare, Alloc>& x)
{
    std::swap(this->root.__root, x.root.__root);
    std::swap(__size, x.__size);
}

/***********************************************/
/*                  key_comp                  */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::key_compare ft::set<Key, Compare, Alloc>::key_comp() const
{
    return (key_compare());
}

/***********************************************/
/*                  value_comp                 */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::value_compare ft::set<Key, Compare, Alloc>::value_comp() const
{
    return (value_compare(key_comp()));
}

/***********************************************/
/*                get_allocator                */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::allocator_type ft::set<Key, Compare, Alloc>::get_allocator() const
{
    return (this->root.__alloc);
}

/***********************************************/
/*                     find                    */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator ft::set<Key, Compare, Alloc>::find (const ft::set<Key, Compare, Alloc>::value_type& val) const
{
    return (iterator(root.Search(root.__root, val), root.__max));
}

/***********************************************/
/*                    count                    */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::count (const ft::set<Key, Compare, Alloc>::key_type& k) const
{
    if (find(k)!= end())
        return (1);
    return (0);
}

/***********************************************/
/*               lower_bound                   */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator  ft::set<Key, Compare, Alloc>::lower_bound (const typename ft::set<Key, Compare, Alloc>::value_type& k) const 
{
    iterator it (root.find(root.__root, k), root.__max);
    if (it != begin() && *(it) < k)
       while (it != end() && *(it) < k) it++;
    else if (it != begin()  && *(it) > k)
    {
        while (it != begin() && *(it) > k) --it;
        it++;
    }
    return it;
}

/***********************************************/
/*                upper_bound                  */
/***********************************************/

template < class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator  ft::set<Key, Compare, Alloc>::upper_bound (const typename ft::set<Key, Compare, Alloc>::key_type& k) const
{
    iterator it  = lower_bound(k);
    if (it != end() && *(it) == k)
        return (++it);
    return (it);
}

/***********************************************/
/*                equal_range                  */
/***********************************************/

template < class Key, class Compare, class Alloc>
ft::pair<typename ft::set<Key, Compare, Alloc>::iterator,typename ft::set<Key, Compare, Alloc>::iterator> ft::set<Key, Compare, Alloc>::equal_range (const typename ft::set<Key, Compare, Alloc>::key_type& k) const
{
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
}





#endif

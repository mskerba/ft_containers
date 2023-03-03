# ifndef __MAP_HPP__
# define __MAP_HPP__
# include <iostream>
# include "../utility/Red-Black-Tree.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../utility/pair.hpp"
# include <functional>
# include <memory>



namespace ft{
    template < class Key, class T, class Compare, class Alloc>
        class map;
    template <class Key, class T, class Compare, class Alloc>
        void swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y) { y.swap(x); }
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class ft::map
{
    public:
        typedef        Key                                                                                          key_type;
        typedef        T                                                                                            mapped_type;
        typedef        ft::pair<const key_type,mapped_type>                                                         value_type;
        typedef        Compare                                                                                      key_compare;
        typedef        Alloc                                                                                        allocator_type;
	    typedef        typename allocator_type::reference                                                           reference;
	    typedef        typename allocator_type::const_reference                                                     const_reference;
	    typedef	       typename allocator_type::pointer                                                             pointer;
	    typedef        typename allocator_type::const_pointer	                                                    const_pointer;
        typedef        typename RBT<key_type, mapped_type, key_compare, allocator_type>::iterator                   iterator;
        typedef        typename RBT<key_type, mapped_type, key_compare, allocator_type>::const_iterator             const_iterator;
        typedef        ft::reverse_iterator<iterator>                                                               reverse_iterator;
        typedef        ft::reverse_iterator<const_iterator>                                                         const_reverse_iterator;
        typedef        ptrdiff_t                                                                                    difference_type;
        typedef        size_t                                                                                       size_type;

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

        // ?  constr end
        const_reverse_iterator rend() const;

        // ? max_size
        size_type max_size() const;

        // ? empty
        bool empty() const;

        // ? operator[]
        mapped_type& operator[] (const key_type& k);

        // ? insert
        pair<iterator,bool> insert (const value_type& val);
        	
        iterator insert (iterator position, const value_type& val);

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last);
        
        // ? insert
        void erase (iterator position);

        size_type erase (const key_type& k);

        void erase (iterator first, iterator last);

        // ? swap
        void swap (map& x);
        // ? key_comp
        key_compare key_comp() const;

        // ? value_comp
        class value_compare
        {
            private:
                friend class map;
            protected:
                key_compare comp;
                value_compare (key_compare c) : comp(c) {}
            public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        };

        value_compare value_comp() const;

        // ? value_comp
        allocator_type get_allocator() const;
      
        // ? find
        iterator find (const key_type& k);
        const_iterator find (const key_type& k) const;

        // ? count
        size_type count (const key_type& k) const;

        // ? lower_bound
        iterator lower_bound (const key_type& k);
        const_iterator lower_bound (const key_type& k) const;

        // ? upper_bound
        iterator upper_bound (const key_type& k);
        const_iterator upper_bound (const key_type& k) const;

        // ? equal_range
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
        pair<iterator,iterator>             equal_range (const key_type& k);



        template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator== ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
        {
            if (lhs.size() != rhs.size())
                return (false);
            typename ft::map<_Key,_T,_Compare,_Alloc>::const_iterator it = lhs.begin(), it1 = rhs.begin();
            while ( it1 != rhs.end())
                if (*(it++) != *(it1++))
                    return (false);
            return (true);
        }

        template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator!= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )  {return !(lhs == rhs);}

        template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator<  ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs )
            {
                typename ft::map<_Key,_T,_Compare,_Alloc>::const_iterator it = lhs.begin(), it1 = rhs.begin();
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

        template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator<= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) {return !(rhs < lhs);}

        template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator>  ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) { return (rhs < lhs);}

        template <class _Key, class _T, class _Compare, class _Alloc>
            friend bool operator>= ( const map<_Key,_T,_Compare,_Alloc>& lhs, const map<_Key,_T,_Compare,_Alloc>& rhs ) {return !(lhs < rhs);}

    // private: // *data member
        RBT<key_type, mapped_type, key_compare, allocator_type>     root;
        size_type            __size;

    private: // *func member
        void delete_node(RBT<key_type, mapped_type, key_compare, allocator_type> n,const  allocator_type& _alloc)
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
ft::map<Key, T, Compare, Alloc>::map (const key_compare& comp, const allocator_type& alloc):__size(0)
{
    (void)comp;
    (void)alloc;
}

/***********************************************/
/*               range constructor             */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
template <class InputIterator>
    ft::map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
    {
        (void)comp;
        (void)alloc;
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
    if (size())
        root.clear_node(root.__root);
    root.__root = 0;
    __size = 0;
}
/***********************************************/
/*                 max_size                    */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
size_t ft::map<Key, T, Compare, Alloc>::max_size() const
{
    int sizeT = sizeof(T);
    if (sizeT == 1)
        sizeT = 2;
    return (std::numeric_limits<std::size_t>::max() / sizeT);
    // return (MAX_SIZE_T / sizeT);
}

/***********************************************/
/*                   begin                     */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::begin()
{
    iterator tmp(this->root.Minimum(root.__root), root.__root);
    return (tmp);
}

/***********************************************/
/*                 const begin                 */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::begin() const
{
    // RBT<key_type, mapped_type, key_compare, allocator_type> tmp_r(root);
    return (const_iterator(root.Minimum(root.__root),root.__root));
}

/***********************************************/
/*                   end                     */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::end()
{
    return (iterator(nullptr, root.__root));
}

/***********************************************/
/*                 const end                   */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::end() const
{
    return (const_iterator(nullptr, root.__root));
}

/***********************************************/
/*                   rbegin                    */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin()
{
    return reverse_iterator(end());
}

/***********************************************/
/*                 const rbegin                */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin() const
{;
    return (const_reverse_iterator(end()));
}

/***********************************************/
/*                   rend                     */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rend()
{
    return (reverse_iterator(begin()));
}

/***********************************************/
/*                 const rend                 */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rend() const
{
    return (const_reverse_iterator(begin()));
}

/***********************************************/
/*                   empty                     */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
bool ft::map<Key, T, Compare, Alloc>::empty() const
{
    if (this->root.__root)
        return (false);
    return (true);
}

/***********************************************/
/*                   operator[]                */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_type& ft::map<Key, T, Compare, Alloc>::operator[] (const ft::map<Key, T, Compare, Alloc>::key_type& k)
{
    if (!root.Search(root.__root, ft::make_pair(k, mapped_type())))
        this->insert(ft::make_pair(k, mapped_type()));
    iterator it(root.Search(root.__root, ft::make_pair(k, mapped_type())), root.__root);
    return (it->second);
}

/***********************************************/
/*                    insert                   */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator,bool> ft::map<Key, T, Compare, Alloc>::insert (const value_type& val)
{
    bool is = (root.Search(root.__root, val)) ? true : false;
    if (!is)   
    {
        this->__size++;
        this->root.Insert(val);
    }
    iterator it(root.Search(root.__root, val), root.__root);
    return (ft::make_pair(it, !is));
}

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::insert (iterator position, const value_type& val)
{
    (void) position;
    bool is = (root.Search(root.__root, val)) ? true : false;
    if (!is)   
    {
        this->__size++;
        this->root.Insert(val);
    }
    iterator it(root.Search(root.__root, val), root.__root);
    return (it);
}

template < class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void ft::map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last)
{
    while (first != last) this->insert(*(first++));
}

/***********************************************/
/*                    erase                    */
/***********************************************/
template < class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::erase (typename ft::map<Key, T, Compare, Alloc>::iterator position)
{
    value_type n = (*position);
    root.Delete(n);
    __size--;
}

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::erase (const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
    root.Delete(ft::make_pair(k, mapped_type()));
    __size--;
    return (1);
}

template < class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::erase (typename ft::map<Key, T, Compare, Alloc>::iterator first, typename ft::map<Key, T, Compare, Alloc>::iterator last)
{
    while (first != last) {
        erase(first++);
    }      
}

/***********************************************/
/*                    swap                     */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::swap (ft::map<Key, T, Compare, Alloc>& x)
{
    std::swap(this->root.__root, x.root.__root);
    std::swap(__size, x.__size);
}

/***********************************************/
/*                  key_comp                  */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::key_compare ft::map<Key, T, Compare, Alloc>::key_comp() const
{
    return (key_compare());
}

/***********************************************/
/*                  value_comp                 */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::value_compare ft::map<Key, T, Compare, Alloc>::value_comp() const
{
    return (value_compare(key_comp()));
}

/***********************************************/
/*                get_allocator                */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::allocator_type ft::map<Key, T, Compare, Alloc>::get_allocator() const
{
    return (this->root.__alloc);
}

/***********************************************/
/*                     find                    */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::find (const ft::map<Key, T, Compare, Alloc>::key_type& k)
{
    return (iterator(root.Search(root.__root, ft::make_pair(k, mapped_type())), root.__root));
}

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::find (const ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
    return (const_iterator(root.Search(root.__root, ft::make_pair(k, mapped_type())), root.__root));
}

/***********************************************/
/*                    count                    */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::count (const ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
    if (find(k)!= end())
        return (1);
    return (0);
}

/***********************************************/
/*               lower_bound                   */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator  ft::map<Key, T, Compare, Alloc>::lower_bound (const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
    iterator it (root.find(root.__root, ft::make_pair(k, mapped_type())), root.__root);
    if (it != begin() && it->first < k)
       while (it != end() && it->first < k) it++;
    else if (it != begin()  && it->first > k)
    {
        while (it != begin() && it->first > k) --it;
        it++;
    }
    return it;
}

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator    ft::map<Key, T, Compare, Alloc>::lower_bound (const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
    const_iterator it (root.find(root.__root, ft::make_pair(k, mapped_type())), root.__root);
    if (it != begin() && it->first < k)
       while (it != end() && it->first < k) it++;
    else if (it != begin()  && it->first > k)
    {
        while (it != begin() && it->first > k) --it;
        it++;
    }
    return it;
}

/***********************************************/
/*                upper_bound                  */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator  ft::map<Key, T, Compare, Alloc>::upper_bound (const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
    iterator it  = lower_bound(k);
    if (it != end() && it->first == k)
        return (++it);
    return (it);
}

template < class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator    ft::map<Key, T, Compare, Alloc>::upper_bound (const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
    const_iterator it  = lower_bound(k);
    if (it != end() && it->first == k)
        return (++it);
    return (it);
}

/***********************************************/
/*                equal_range                  */
/***********************************************/

template < class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator,typename ft::map<Key, T, Compare, Alloc>::const_iterator> ft::map<Key, T, Compare, Alloc>::equal_range (const typename ft::map<Key, T, Compare, Alloc>::key_type& k) const
{
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
}

template < class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator,typename ft::map<Key, T, Compare, Alloc>::iterator> ft::map<Key, T, Compare, Alloc>::equal_range (const typename ft::map<Key, T, Compare, Alloc>::key_type& k)
{
    return (ft::make_pair(lower_bound(k), upper_bound(k)));
}



#endif

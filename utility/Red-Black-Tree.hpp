# ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__
# include "pair.hpp"
# include <iostream>



template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class RBT
{
    public:
        typedef     Key                                            key_type;
        typedef     T                                              mapped_type;
        typedef     ft::pair<const key_type,mapped_type>           value_type;
        typedef     Compare                                        key_compare;
    public:
        class Node
        {
            public:
                value_type  __val;
                bool        __color; // ? 0 = red & 1 =  black
                Node        *__parent;
                Node        *__left;
                Node        *__right;
                
                Node(value_type val) : __val(val), __color(0), __parent(0), __left(0), __right(0){}
        };
        typedef typename Alloc::template rebind<Node>::other    allocator_type;
        typedef Alloc                                           val_allocator;


        RBT():__root(nullptr){}
        RBT(const RBT& x)
        {
            duplicate_tree(x.__root);
        }
        RBT&    operator= (const RBT& x)
        {
            if (__root) clear_node(__root);
            duplicate_tree(x.__root);
            return (*this);
        }
        void    right_Rotate(Node *x);
        void    left_Rotate(Node *x);
        void    Insert(value_type n);
        void    Delete(value_type n);
        Node*   Minimum(Node *z);
        Node*   Maximum(Node *z);
        void    printTree(Node* node, std::string indent, bool last);
        Node*   Search(Node *z, const value_type& k)
        {
            if (!z || k == z->__val)
                retrun (z);
            if (less_than(k , z->__val))
                return (Search(z->__left, k))
            return (Search(z->__right, k));
        }

        void    clear_node(Node* z)
        {
            if(!z) return ;

            clear_node(z->__left);
            clear_node(z->__right);
           __val__alloc.destroy(&z->__val);
           __val__alloc.deallocate(&z->__val, 1);
            __alloc.destroy(z);
            __alloc.deallocate(z, 1);
        }


    public: // !private
        Node    *__root;
        allocator_type  __alloc;
        val_allocator   __val__alloc;
        key_compare     less_than;


    private: //*func memb
        void    insert_FixUp(Node *z);
        void    transplant(Node *z, Node *y);
        Node    *new_node(value_type val)
        {
            value_type* new_val = __val__alloc.allocate(1);
            Node*       node = __alloc.allocate(1);

            __val__alloc.construct(new_val, val);
            __alloc.construct(node,*new_val);
            
            return node;
        }
        void duplicate_tree(Node *z)
        {
            if (z) return;

            Insert(z->__val);
            duplicate_tree(z->__left);
            duplicate_tree(z->__right);
        }
};

template < typename Key, typename T, typename Compare, typename Alloc>
void RBT<Key, T, Compare, Alloc>::printTree(RBT<Key, T, Compare, Alloc>::Node* node, std::string indent, bool last)
{
    if (indent == "" & !node) std::cout << "this tree is empty:D\n";
    if (node != nullptr)
    {
        std::cout << indent;
        if (last) {
            std::cout << "├─";
            indent += "│ ";
        } else {
            std::cout << "└─";
            indent += "  ";
        }

        if (node->__color)
            std::cout << "[" << node->__val << "]" << std::endl;
        else
            std::cout << "\033[31m" << "[" << node->__val << "]" << "\033[0m\n";

        printTree(node->__right, indent, true);
        printTree(node->__left, indent, false);
    }
}

template < typename Key, typename T, typename Compare, typename Alloc>
void RBT<Key, T, Compare, Alloc>::right_Rotate(Node *x)
{
    if (!x->__left) return ;
    Node *y = x->__left;
    x->__left = y->__right;
    if (y->__right)
        y->__right->__parent = x;
    y->__parent = x->__parent;
    if (!x->__parent)
        __root = y;
    else if (x == x->__parent->__left)
        x->__parent->__left = y;
    else
        x->__parent->__right = y;
    y->__right = x;
    x->__parent = y;
}

template < typename Key, typename T, typename Compare, typename Alloc>
void RBT<Key, T, Compare, Alloc>::left_Rotate(Node *x)
{
    if (!x->__right) return ;

    Node *y = x->__right;
    x->__right = y->__left;
    if (y->__left)
        y->__left->__parent = x;
    y->__parent = x->__parent;
    if (!x->__parent)
        __root = y;
    else if (x == x->__parent->__left)
        x->__parent->__left = y;
    else
        x->__parent->__right = y;
    y->__left = x;
    x->__parent = y;
}

template < typename Key, typename T, typename Compare, typename Alloc>
void RBT<Key, T, Compare, Alloc>::Insert(value_type n)
{
    Node *y = nullptr;
    Node *x = __root;
    Node *z = new_node(n);

    while(x)
    {
        y = x;
        if(less_than(z->__val , x->__val)) //? (z->__val < x->__val)
            x = x->__left;
        else
            x = x->__right;
    }
    z->__parent = y;
    if (!y)
        __root = z;
    else if (less_than(z->__val , y->__val)) //? z->__val < y->__val
        y->__left = z;
    else
        y->__right = z;
    insert_FixUp(z);
}

template < typename Key, typename T, typename Compare, typename Alloc>
void RBT<Key, T, Compare, Alloc>::insert_FixUp(Node *z)
{
    Node *y;

    if (!z->__parent)
        z->__color = 1;
    while (z->__parent && z->__parent->__parent && !z->__parent->__color)
    {
        if (z->__parent == z->__parent->__parent->__left)
        {
            y = z->__parent->__parent->__right;
            if (y && !y->__color)
            {
                z->__parent->__color = 1;
                y->__color = 1;
                z->__parent->__parent->__color = 0;
                z = z->__parent->__parent;
            }
            else
            {
                if (z == z->__parent->__right)
                {
                    z = z->__parent;
                    left_Rotate(z);
                }
                z->__parent->__color = 1;
                z->__parent->__parent->__color = 0;
                right_Rotate(z->__parent->__parent);
            }
        }
        else // ! the simetrique for this 3 cas ^\^
        {
            y = z->__parent->__parent->__left;
            if (y && !y->__color)
            {
                z->__parent->__color = 1;
                y->__color = 1;
                z->__parent->__parent->__color = 0;
                z = z->__parent->__parent;
            }
            else
            {
                if (z == z->__parent->__left)
                {
                    z = z->__parent;
                    right_Rotate(z);
                }
                z->__parent->__color = 1;
                z->__parent->__parent->__color = 0;
                left_Rotate(z->__parent->__parent);
            }
        }
    }
}

template < typename Key, typename T, typename Compare, typename Alloc>
void    RBT<Key, T, Compare, Alloc>::transplant(Node *z, Node *y)
{
    if (!z->__parent)
        __root = y;
    else if (z == z->__parent->__left)
        z->__parent->__left = y;
    else
        z->__parent->__right = y;
    if (y)
        y->__parent = z->__parent;
}

template < typename Key, typename T, typename Compare, typename Alloc>
void RBT<Key, T, Compare, Alloc>::Delete(value_type n)
{
    Node *z = new_node(n);
    Node *y  = z;
    Node *x;
    bool y_col = y->__color;
    if (!z->__left)
    {
        x = z->__right;
        transplant(z, z->__right);
    }
    else if (!z->__right)
    {
        x = z->__left;
        transplant(z, z->__left);
    }
    else
    {
        y = Minimum(z->__right);
        y_col = y->__color;
        x = y->__right;
        if (y->__parent == z)
            x->__parent = y;
        else
        {
            transplant(y, y->__right);
            y->__right = z->__right;
            y->__right->__parent = y;
        }
        transplant(z,y);
        y->__left = z->__left;
        y->__left->__parent = y;
        y->__color = z->__color;
    }
    // ! destroy z here/! \!!!!
    // if (y_col)
    //     Delete_FixUp(x);
}

template < typename Key, typename T, typename Compare, typename Alloc>
typename RBT<Key, T, Compare, Alloc>::Node* RBT<Key, T, Compare, Alloc>::Minimum(Node *z)
{
    while(z->__left)
        z = z->__left;
    return (z);
}

template < typename Key, typename T, typename Compare, typename Alloc>
typename RBT<Key, T, Compare, Alloc>::Node* RBT<Key, T, Compare, Alloc>::Maximum(Node *z)
{
    while(z->__right)
        z = z->__right;
    return (z);
}


#endif
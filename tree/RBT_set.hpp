# ifndef __RBT_SET__HPP__
# define __RBT_SET__HPP__
# include "../iterator/set_iterator.hpp"
# include <iostream>



template < class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
class RBT_S
{
    public:
        typedef     Key                                         key_type;
        typedef     key_type                                    value_type;
        typedef     Compare                                     key_compare;
    public:
        class Node
        {
            public:
                value_type  *__val;
                bool        __color; // ? 0 = red & 1 =  black
                Node        *__parent;
                Node        *__left;
                Node        *__right;
                
                Node(value_type *val) : __val(val), __color(0), __parent(0), __left(0), __right(0){}
                ~Node(){ __parent = 0; __left = 0; __right = 0;}
        };
        typedef typename Alloc::template rebind<Node>::other    allocator_type;
        typedef Alloc                                           val_allocator;
        typedef set_iterator<Node, value_type>                  iterator;
        typedef set_iterator<const Node, value_type>            const_iterator;

        RBT_S():__root(nullptr), __max(nullptr)
        {
            nil = new_node(value_type());
            nil->__color = 1;
        }
        RBT_S(const RBT_S& x)
        {
            duplicate_tree(x.__root);
            nil = new_node(value_type());
            nil->__color = 1;
            this->__max = this->Maximum(this->__root);
        }
         RBT_S&    operator= (const RBT_S& x)
        {
            clear_node(__root);
            in(x);
            this->__max = this->Maximum(this->__root);
            return (*this);
        }
        
        ~RBT_S(){destroy_n(nil);}
        void in(const RBT_S& x)
        {
            __root = 0;
            if (x.__root)
            {
                __root = new_node(*(x.__root->__val));
                __root->__color = 1;
            }
            duplicate_tree(__root, x.__root);
        }
        void    swap(RBT_S *x)
        {
            std::swap(this->__root, x->__root);
        }
        void    right_Rotate(Node *x);
        void    left_Rotate(Node *x);
        void    Insert(value_type n);
        void    Delete(value_type n);
        Node*   Minimum(Node *z) const;
        Node*   Maximum(Node *z) const;
        void    printTree(Node* node, std::string indent, bool last);
        Node*   Search(Node *z, const value_type& k) const
        {
            if (!z || k == *(z->__val))
                return (z);
            if (less_than(k, *(z->__val)))
                return (Search(z->__left, k));
            return (Search(z->__right, k));
        }

        Node*   find(Node *z, const value_type& k) const
        {
            if (!z || k == *(z->__val) )
                return (z);
            Node *x;
            if (less_than(k, *(z->__val)))
            {
                x = find(z->__left, k);
                if(!x)
                    return (z);
                return (x);
            }
            else
            {
                x = find(z->__right, k);
                if(!x)
                    return (z);
                return (x);
            }
        }

        void destroy_n(Node* z)
        {
            __val__alloc.destroy(z->__val);
            __alloc.destroy(z);
            if (sizeof(z->__val))
                __val__alloc.deallocate(z->__val, 1);
            if (sizeof(z))
                __alloc.deallocate(z, 1);
        }
        void clear_node(Node* z)
        {
            if(!z) return;

            clear_node(z->__left);
            clear_node(z->__right);
            destroy_n(z);
        }

    public: // !private
        Node            *__root;
        Node            *__max;
        Node            *nil;
        allocator_type  __alloc;
        val_allocator   __val__alloc;
        key_compare     less_than;


    private: //*func memb
        void    insert_FixUp(Node *z);
        void    Delete_FixUp(Node *z);
        void    transplant(Node *z, Node *y);
        Node    *new_node(value_type val)
        {
            value_type* new_val = __val__alloc.allocate(1);
            Node*       node = __alloc.allocate(1);

            __val__alloc.construct(new_val, val);
            __alloc.construct(node, new_val);
            
            return node;
        }
                void duplicate_tree(Node *z , Node* y)
        {
            if (!y) return;
            except_Insert(z, y);
            duplicate_tree(z->__left,y->__left);
            duplicate_tree(z->__right,y->__right);
        }
        void except_Insert(Node *z,Node * y)
        {
            if (y->__right)
            {
            Node* right = new_node(*(y->__right->__val));
            right->__parent = z;
            right->__color = y->__color;
            z->__right = right;

            }
            if (!y->__left)
                return ;
            Node* left = new_node(*(y->__left->__val));
            left->__color = y->__color;
            left->__parent = z;
            z->__left = left;
        }
};

template < typename Key, typename Compare, typename Alloc>
void RBT_S<Key, Compare, Alloc>::printTree(RBT_S<Key, Compare, Alloc>::Node* node, std::string indent, bool last)
{
    if (indent == "" & !node) std::cerr << "this tree is empty:D\n";
    if (node != nullptr)
    {
        std::cerr << indent;
        if (last) {
            std::cerr << "├─";
            indent += "│ ";
        } else {
            std::cerr << "└─";
            indent += "  ";
        }

        if (node->__color)
            std::cerr << "[" << *(node->__val) << "]" << std::endl;
        else
            std::cerr << "\033[31m" << "[" << *(node->__val) << "]" << "\033[0m\n";

        printTree(node->__right, indent, true);
        printTree(node->__left, indent, false);
    }
}

template < typename Key, typename Compare, typename Alloc>
void RBT_S<Key, Compare, Alloc>::right_Rotate(Node *x)
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

template < typename Key, typename Compare, typename Alloc>
void RBT_S<Key, Compare, Alloc>::left_Rotate(Node *x)
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

template < typename Key, typename Compare, typename Alloc>
void RBT_S<Key, Compare, Alloc>::Insert(value_type n)
{
    Node *y = nullptr;
    Node *x = __root;
    Node *z = new_node(n);

    while(x)
    {
        y = x;
        if(less_than(*(z->__val) , *(x->__val))) //? (z->__val < x->__val)
            x = x->__left;
        else
            x = x->__right;
    }
    z->__parent = y;
    if (!y)
        __root = z;
    else if (less_than(*(z->__val) , *(y->__val))) //? z->__val < y->__val
        y->__left = z;
    else
        y->__right = z;
    insert_FixUp(z);
    this->__root->__color = 1;
    this->__max = this->Maximum(this->__root);
}

template < typename Key, typename Compare, typename Alloc>
void RBT_S<Key, Compare, Alloc>::insert_FixUp(Node *z)
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
        else // * the simetrique for this 3 cas ^\^
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

template < typename Key, typename Compare, typename Alloc>
void    RBT_S<Key, Compare, Alloc>::transplant(Node *z, Node *y)
{
    if(!y)
        y = nil;
    if (!z->__parent)
        __root = y;
    else if (z == z->__parent->__left)
        z->__parent->__left = y;
    else
        z->__parent->__right = y;
    y->__parent = z->__parent;
}

template < typename Key, typename Compare, typename Alloc>
void RBT_S<Key, Compare, Alloc>::Delete(value_type n)
{
    Node *z = Search(__root, n);
    if(!z)
        return ;
    Node *y  = z;
    Node *x;
    bool y_col = y->__color;


    this->__max = (z == __max) ? z->__parent : __max;
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
        if (x && y->__parent == z)
            x->__parent = y;
        else
        {
            transplant(y, y->__right);
            y->__right = z->__right;
            if(y->__right)
                y->__right->__parent = y;
        }
        transplant(z,y);
        y->__left = z->__left;
        y->__left->__parent = y;
        y->__color = z->__color;
    }
    if(!x)
        x = nil;
    if (x && y_col)
        Delete_FixUp(x);
    if (x == nil)
    {
        if (x->__parent->__left == x)
            x->__parent->__left = nullptr;
        else
            x->__parent->__right = nullptr;
    }
    destroy_n(z);
    __root->__color = 1;
}

template < typename Key, typename Compare, typename Alloc>
typename RBT_S<Key, Compare, Alloc>::Node* RBT_S<Key, Compare, Alloc>::Minimum(Node *z) const
{
    while(z && z->__left)
        z = z->__left;
    return (z);
}

template < typename Key, typename Compare, typename Alloc>
typename RBT_S<Key, Compare, Alloc>::Node* RBT_S<Key, Compare, Alloc>::Maximum(Node *z) const
{

    while(z && z->__right)
        z = z->__right;
    return (z);
}

template < typename Key, typename Compare, typename Alloc>
void RBT_S<Key, Compare, Alloc>::Delete_FixUp(Node *z)
{
    Node* y;


    if (z == nil)
    {
        if(z == z->__parent->__left &&  !z->__parent->__right)
            z->__parent->__color = 1;
        else if(z == z->__parent->__left &&  !z->__parent->__right)
            z->__parent->__color = 1;
        return ;
    }

    while (z != __root && z->__color)
    {
        if (z->__parent && z == z->__parent->__left)
        {
            y = z->__parent->__right;
            if (y &&!y->__color)
            {
                y->__color = 1;
                z->__parent->__color = 0;
                left_Rotate(z->__parent);
                y = z->__parent->__right;
                if(!y)
                {
                    z = z->__parent;
                    break;
                }
            }
            if(!y)
                break;
            if ((!y->__left || y->__left->__color) && (!y->__right || y->__right->__color))
            {
                y->__color = 0;
                z = z->__parent;
            }
            else
            {
                if (y->__right && y->__right->__color)
                {
                    y->__left->__color = 1;
                    y->__color = 0;
                    right_Rotate(y);
                    y = z->__parent->__right;
                }
                y->__color = z->__parent->__color;
                z->__parent->__color = 1;
                if(y->__right)
                    y->__right->__color = 1;
                left_Rotate(z->__parent);
                z = __root;
            }
        }
        else 
        {
            y = z->__parent->__left;
            if (!y->__color)
            {
                y->__color = 1;
                z->__parent->__color = 0;
                left_Rotate(z->__parent);
                if(!z->__parent)
                    break;
                y = z->__parent->__left;
                if(!y)
                {
                    z = z->__parent;
                    break;
                }
            }
            if ((!y->__left || y->__left->__color) && (!y->__right || y->__right->__color))
            {
                y->__color = 0;
                z = z->__parent;
            }
            else
            {
                if (y->__left->__color)
                {
                    y->__right->__color = 1;
                    y->__color = 0;
                    left_Rotate(y);
                    y = z->__parent->__left;
                }
                y->__color = z->__parent->__color;
                z->__parent->__color = 1;
                y->__left->__color = 1;
                right_Rotate(z->__parent);
                z = __root;
            }
        }

    }
    z->__color = 1;
}

#endif
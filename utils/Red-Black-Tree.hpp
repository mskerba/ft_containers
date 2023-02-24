# ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__
# include <iostream>



template <typename Value, typename Key>
class RBT
{
    public:
        typedef     Value       value_type;
        typedef     Key         key_type;

    public:

        class Node
        {
            public:
                key_type    __key;
                value_type  __val;
                bool        ___color; // ? 0 = red & 1 =  black
                Node        *__parent;
                Node        *__left;
                Node        *__right;
                
                Node(key_type key, value_type val) : __key(key), __val(val), ___color(0), __parent(0), __left(0), __right(0){}
        };
        RBT():__root(0){}
        void    right_Rotate(Node *x);
        void    left_Rotate(Node *x);
        void    insert(Node *z);
        void    insert_FixUp(Node *z);

    public: // !private
        Node *__root;
};

template <typename Value, typename Key>
void RBT<Value, Key>::right_Rotate(Node *x)
{
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

template <typename Value, typename Key>
void RBT<Value, Key>::left_Rotate(Node *x)
{
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

template <typename Value, typename Key>
void RBT<Value, Key>::insert(Node *z)
{
    Node *y = nullptr;
    Node *x = __root;
    while(x)
    {
        y = x;
        if(z->__key < x->__key)
            x = x->__left;
        else
            x = x->__right;
    }
    z->__parent = y;
    if (!y)
        __root = z;
    else if (z->__key < y->__key)
        y->__left = z;
    else
        y->__right = z;
    insert_FixUp(z);
}


template <typename Value, typename Key>
void RBT<Value, Key>::insert_FixUp(Node *z)
{
    Node *y;
    while (!z->__parent->___color)
    {
        if (z->__parent == z->__parent->__parent->__left)
        {
            y = z->__parent->__parent->__right;
            if (!y->___color)
            {
                z->__parent->___color = 1;
                y->___color = 1;
                z->__parent->__parent->___color = 0;
                z = z->__parent->__parent;
            }
            else
            {
                if (z == z->__parent->__right)
                {
                    z = z->__parent;
                    left_Rotate(z);
                }
                z->__parent->___color = 1;
                z->__parent->__parent = 0;
                right_Rotate(z);
            }
        }
        else // ! the simetrique for this 3 cas 
        {
            y = z->__parent->__parent->__left;
            if (!y->___color)
            {
                z->__parent->___color = 1;
                y->___color = 1;
                z->__parent->__parent->___color = 0;
                z = z->__parent->__parent;
            }
            else
            {
                if (z == z->__parent->__left)
                {
                    z = z->__parent;
                    right_Rotate(z);
                }
                z->__parent->___color = 1;
                z->__parent->__parent = 0;
                left_Rotate(z);
            }
        }
    }
}

#endif
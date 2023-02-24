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
                bool        __color; // ? 0 = red & 1 =  black
                Node        *__parent;
                Node        *__left;
                Node        *__right;
                
                Node(key_type key, value_type val) : __key(key), __val(val), __color(0), __parent(0), __left(0), __right(0){}
        };
        RBT():__root(0){}
        void    right_Rotate(Node *x);
        void    left_Rotate(Node *x);
        void    Insert(Node *z);
        void    Delete(Node *z);
        Node*   Minimum(Node *z);

    public: // !private
        Node *__root;
        void    insert_FixUp(Node *z);
        void    transplant(Node *z, Node *y);
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
void RBT<Value, Key>::Insert(Node *z)
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
    while (!z->__parent->__color)
    {
        if (z->__parent == z->__parent->__parent->__left)
        {
            y = z->__parent->__parent->__right;
            if (!y->__color)
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
                z->__parent->__parent = 0;
                right_Rotate(z);
            }
        }
        else // ! the simetrique for this 3 cas 
        {
            y = z->__parent->__parent->__left;
            if (!y->__color)
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
                z->__parent->__parent = 0;
                left_Rotate(z);
            }
        }
    }
}

template <typename Value, typename Key>
void    RBT<Value, Key>::transplant(Node *z, Node *y)
{
    if (!z->__parent)
        __root = y;
    else if (z = z->__parent->__left)
        z->__parent->__left = y;
    else
        z->__parent->__right = y;
        y->__parent = z->__parent;
}

template <typename Value, typename Key>
void RBT<Value, Key>::Delete(Node *z)
{
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
    // if (y_col)
    //     Delete_FixUp(x);
}

template <typename Value, typename Key>
typename RBT<Value, Key>::Node* RBT<Value, Key>::Minimum(Node *z)
{
    while(z->__left)
        z = z->__left;
    retunr (z);
}


$env:GITHUB_TOKEN="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"
#endif
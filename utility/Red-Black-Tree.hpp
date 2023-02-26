# ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__
# include <iostream>



template <typename Value>
class RBT
{
    public:
        typedef     Value       value_type;

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
        RBT():__root(nullptr){}
        void    right_Rotate(Node *x);
        void    left_Rotate(Node *x);
        void    Insert(Node *z);
        void    Delete(Node *z);
        Node*   Minimum(Node *z);
        void printTree(Node* node, std::string indent, bool last);


    public: // !private
        Node *__root;
        void    insert_FixUp(Node *z);
        void    transplant(Node *z, Node *y);
};

template<typename val>
void RBT<val>::printTree(RBT<val>::Node* node, std::string indent, bool last)
{
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

template <typename Value>
void RBT<Value>::right_Rotate(Node *x)
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

template <typename Value>
void RBT<Value>::left_Rotate(Node *x)
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

template <typename Value>
void RBT<Value>::Insert(Node *z)
{
    Node *y = nullptr;
    Node *x = __root;

    while(x)
    {
        y = x;
        if(z->__val < x->__val)
            x = x->__left;
        else
            x = x->__right;
    }
    z->__parent = y;
    if (!y)
        __root = z;
    else if (z->__val < y->__val)
        y->__left = z;
    else
        y->__right = z;
    insert_FixUp(z);
}

template <typename Value>
void RBT<Value>::insert_FixUp(Node *z)
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

template <typename Value>
void    RBT<Value>::transplant(Node *z, Node *y)
{
    if (!z->__parent)
        __root = y;
    else if (z == z->__parent->__left)
        z->__parent->__left = y;
    else
        z->__parent->__right = y;
        y->__parent = z->__parent;
}

template <typename Value>
void RBT<Value>::Delete(Node *z)
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

template <typename Value>
typename RBT<Value>::Node* RBT<Value>::Minimum(Node *z)
{
    while(z->__left)
        z = z->__left;
    retunr (z);
}


#endif

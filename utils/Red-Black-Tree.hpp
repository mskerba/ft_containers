# ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

template <typename Value, typename Key>
class RBT
{
    public:
        typedef     Value       value_type;
        typedef     Key         key_type;

    public:
        RBT();
        RBT(Key key, Value val);
        RBT(Key key, Value val, RBT *parent, RBT *left, RBT *right);
        ~RBT();
        void rotate_right(RBT *root, RBT* right);
        void rotate_left(RBT *root, RBT* left);
        void rbt_insert(RBT *root, RBT *newnode);
        class Node
        {
            key_type    key;
            value_type  val;
            bool        __color;
            RBT         *__parent;
            RBT         *__left;
            RBT         *__right;
        };

};


#endif
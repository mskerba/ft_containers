# ifndef __STACK_HPP__
# define __STACK_HPP__
# include "../vector/vector.hpp"
# include "../vector/vector.tmp"
# include <iostream>
# include <memory>

namespace ft
{
    template <typename T, typename Container>
    class stack;
};

template <typename T, typename Container = ft::vector<T> >
class ft::stack
{
    public:
        typedef     T                        value_type;
        typedef     Container                container_type;
        typedef     size_t                   size_type;
        typedef typename     Container::reference     reference;
        typedef typename     Container::const_reference     const_reference;


    protected:
        container_type c;

    public:
        explicit stack (const container_type& ctnr = container_type());
        bool empty() const;
        size_type size() const;
        value_type& top();
        const value_type& top() const;
        void push (const value_type& val);
        void pop();

        template <typename _T, typename _Container>
            friend bool operator== (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs) {return (lhs.c == rhs.c);}

        template <typename _T, typename _Container>
            friend bool operator!= (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs) {return (lhs.c != rhs.c);}

        template <typename _T, typename _Container>
            friend bool operator<  (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs) {return (lhs.c < rhs.c);}

        template <typename _T, typename _Container>
            friend bool operator<= (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs) {return (lhs.c <= rhs.c);}

        template <typename _T, typename _Container>
            friend bool operator>  (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs) {return (lhs.c > rhs.c);}

        template <typename _T, typename _Container>
            friend bool operator>= (const ft::stack<_T,_Container>& lhs, const ft::stack<_T,_Container>& rhs) {return (lhs.c >= rhs.c);}

};


template <typename T, typename Container>
ft::stack<T, Container>::stack (const ft::stack<T, Container>::container_type& ctnr) : c(ctnr){}


template <typename T, typename Container>
bool ft::stack<T, Container>::empty() const
{
    return (c.empty());
}

template <typename T, typename Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const
{
    return (c.size());
}

template <typename T, typename Container>
typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top()
{
    return (c.back());
}

template <typename T, typename Container>
const typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top() const
{
    return (c.back());
}

template <typename T, typename Container>
void ft::stack<T, Container>::push (const value_type& val)
{
    return (c.push_back(val));
}

template <typename T, typename Container>
void ft::stack<T, Container>::pop()
{
    return (c.pop_back());
}


             
#endif

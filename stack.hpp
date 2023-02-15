# ifndef __STACK_HPP__
# define __STACK_HPP__
# include "ft_containers.hpp"
# include "vector.hpp"
# include "pair.hpp"

namespace ft
{
    template <typename T, typename Container>
    class stack;
}


template <typename T, typename Container = ft::vector<T> >
class ft::stack
{
    public:
        typedef     T                        value_type;
        typedef     Container                container_type;
        typedef     size_t                   size_type;

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

        template <typename T1, typename T2>
            friend bool operator== (const ft::stack<T1>& lhs, const ft::stack<T2>& rhs) {return (lhs.c == rhs.c);}

        template <typename T1, typename T2>
            friend bool operator!= (const ft::stack<T1>& lhs, const ft::stack<T2>& rhs) {return (lhs.c != rhs.c);}

        template <typename T1, typename T2>
            friend bool operator<  (const ft::stack<T1>& lhs, const ft::stack<T2>& rhs) {return (lhs.c < rhs.c);}

        template <typename T1, typename T2>
            friend bool operator<= (const ft::stack<T1>& lhs, const ft::stack<T2>& rhs) {return (lhs.c <= rhs.c);}

        template <typename T1, typename T2>
            friend bool operator>  (const ft::stack<T1>& lhs, const ft::stack<T2>& rhs) {return (lhs.c > rhs.c);}

        template <typename T1, typename T2>
            friend bool operator>= (const ft::stack<T1>& lhs, const ft::stack<T2>& rhs) {return (lhs.c >= rhs.c);}

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

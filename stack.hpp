# ifndef __STACK_HPP__
# define __STACK_HPP__
# include "ft_containers.hpp"
# include "vector.hpp"
# include "pair.hpp"

template <class T, class Container = ft::vector<T> >
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

        template <class _T, class _Container>
            friend bool operator== (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) {return (lhs.c == rhs.c);}

        template <class _T, class _Container>
            friend bool operator!= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) {return (lhs.c != rhs.c);}

        template <class _T, class _Container>
            friend bool operator<  (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) {return (lhs.c < rhs.c);}

        template <class _T, class _Container>
            friend bool operator<= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) {return (lhs.c <= rhs.c);}

        template <class _T, class _Container>
            friend bool operator>  (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) {return (lhs.c > rhs.c);}

        template <class _T, class _Container>
            friend bool operator>= (const stack<_T,_Container>& lhs, const stack<_T,_Container>& rhs) {return (lhs.c >= rhs.c);}

};


template <class T, class Container>
ft::stack<T, Container>::stack (const ft::stack<T, Container>::container_type& ctnr) : c(ctnr){}


template <class T, class Container>
bool ft::stack<T, Container>::empty() const
{
    return (c.empty());
}

template <class T, class Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const
{
    return (c.size());
}

template <class T, class Container>
typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top()
{
    return (c.back());
}

template <class T, class Container>
const typename ft::stack<T, Container>::value_type& ft::stack<T, Container>::top() const
{
    return (c.back());
}

template <class T, class Container>
void ft::stack<T, Container>::push (const value_type& val)
{
    return (c.push_back(val));
}

template <class T, class Container>
void ft::stack<T, Container>::pop()
{
    return (c.pop_back());
}


             
#endif

# ifndef  __PAIR__HPP__
# define  __PAIR__HPP__


namespace ft{
    template <class T1, class T2>
        struct pair;
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const ft::pair<T1, T2>& x)
{
    os << x.first<< ", " << x.second;
    return os;
}
}

template <class T1, class T2>
struct ft::pair
{
    public:
        typedef      T1                 first_type;
        typedef      T2                 second_type;

        first_type first;
        second_type second;
    
    public:
        pair(){}
        template<class U, class V>
            pair (const pair<U,V>& pr) : first(pr.first), second(pr.second){}
        pair (const first_type& a, const second_type& b) : first(a) , second(b){}
        pair& operator= (const pair& pr)
        {
            first = pr.first;
            second = pr.second;
        }


        template <class _T1, class _T2>
            friend bool operator== (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second);}

        template <class _T1, class _T2>
            friend bool operator!= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) { return (lhs.first != rhs.first && lhs.second != rhs.second);}

        template <class _T1, class _T2>
            friend bool operator<  (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) { return (lhs.first < rhs.first && lhs.second < rhs.second);}

        template <class _T1, class _T2>
            friend bool operator<= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) { return (lhs.first <= rhs.first && lhs.second <= rhs.second);}

        template <class _T1, class _T2>
            friend bool operator>  (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) { return (lhs.first > rhs.first && lhs.second > rhs.second);}

        template <class _T1, class _T2>
            friend bool operator>= (const pair<_T1,_T2>& lhs, const pair<_T1,_T2>& rhs) { return (lhs.first >= rhs.first && lhs.second >= rhs.second);}
};




template <typename T1, typename T2>
ft::pair<T1,T2> make_pair (T1 x, T2 y)
{
    ft::pair<T1, T2> tmp(x, y);
    return (tmp);
}

#endif 

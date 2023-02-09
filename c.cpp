template<typename T, typename A>
ft::vector<T, A>::reverse_iterator::reverse_iterator (){}

template<typename T, typename A>
ft::vector<T, A>::reverse_iterator::reverse_iterator (pointer p): ptr(p){}

template<typename T, typename A>
ft::vector<T, A>::reverse_iterator::reverse_iterator (const reverse_iterator& x):ptr(x.ptr){}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator& ft::vector<T, A>::reverse_iterator::operator= (const reverse_iterator& x)
{
    this->ptr = x.ptr;
    return (*this);
}

template<typename T, typename A>
bool    ft::vector<T, A>::reverse_iterator::operator== (const reverse_iterator& x) const
{
    if (this->ptr == x.ptr) return (true);
    return (false);
}

template<typename T, typename A>
bool    ft::vector<T, A>::reverse_iterator::operator!= (const reverse_iterator& x) const
{
    if (this->ptr != x.ptr) return (true);
    return (false);
}

template<typename T, typename A>
bool    ft::vector<T, A>::reverse_iterator::operator>= (const reverse_iterator& x) const
{
    if (this->ptr <= x.ptr) return (true);
    return (false);
}

template<typename T, typename A>
bool    ft::vector<T, A>::reverse_iterator::operator<= (const reverse_iterator& x) const
{
    if (this->ptr >= x.ptr) return (true);
    return (false);
}

template<typename T, typename A>
bool    ft::vector<T, A>::reverse_iterator::operator< (const reverse_iterator& x) const
{
    if (this->ptr > x.ptr) return (true);
    return (false);
}

template<typename T, typename A>
bool    ft::vector<T, A>::reverse_iterator::operator> (const reverse_iterator& x) const
{
    if (this->ptr < x.ptr) return (true);
    return (false);
}

template<typename T, typename A>
typename ft::vector<T, A>::reference ft::vector<T, A>::reverse_iterator::operator* () const
{
    return (*ptr);
}

template<typename T, typename A>
typename ft::vector<T, A>::pointer ft::vector<T, A>::reverse_iterator::operator-> () const
{
    return (ptr);
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator& ft::vector<T, A>::reverse_iterator::operator++ ()
{
    --ptr;
    return (*this);
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator& ft::vector<T, A>::reverse_iterator::operator-- ()
{
    ++ptr;
    return (*this);
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::reverse_iterator::operator++ (int)
{
    reverse_iterator tmp =(*this);

    --(ptr);
    return (tmp);
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::reverse_iterator::operator-- (int)
{
    reverse_iterator tmp = (*this);

    ++(ptr);
    return (tmp);
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator& ft::vector<T, A>::reverse_iterator::operator+= (typename ft::vector<T, A>::difference_type n)
{
    ptr -= n;
    return (*this);
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator& ft::vector<T, A>::reverse_iterator::operator-= (typename ft::vector<T, A>::difference_type n)
{
    ptr += n;
    return (*this);
}

template<typename T, typename A>
T& ft::vector<T, A>::reverse_iterator::operator[] (typename ft::vector<T, A>::difference_type n) const
{
    return (this->ptr[n]);
}

template<typename T, typename A>
typename ft::vector<T, A>::difference_type ft::vector<T, A>::reverse_iterator::operator- (const ft::vector<T, A>::reverse_iterator& it)
{
    return this->ptr + it.ptr;
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::reverse_iterator::operator+ (typename ft::vector<T, A>::difference_type n) const
{
    return (reverse_iterator(ptr - n));
}

template<typename T, typename A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::reverse_iterator::operator- (typename ft::vector<T, A>::difference_type n) const
{
    return (reverse_iterator(ptr + n));
}
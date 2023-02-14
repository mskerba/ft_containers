# ifndef __FT_CONTAINERS_HPP
# define __FT_CONTAINERS_HPP

namespace ft
{
    template<typename T, typename A>
    class vector;

    template <typename T>
    void swap (ft::vector<T, std::allocator<T> >& x, ft::vector<T, std::allocator<T> >& y);
}

# endif


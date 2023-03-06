# ifndef __ENABLE_IF__
# define __ENABLE_IF__
# include "is_integral.hpp"

namespace ft{
    template <bool B, typename T = void>
    struct enable_if {};
};
template <typename T>
struct ft::enable_if<true, T> {
    typedef T type;
};

#endif



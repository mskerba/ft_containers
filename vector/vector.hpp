# ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include "../iterator/iterator.hpp"
# include "../iterator/reverse_iterator.hpp"
# include <iostream>
# include <memory>
#include <type_traits>

// # define MAX_SIZE_T 18446744073709551615

namespace ft
{
    template<typename T, typename A>
    class vector;

    
    // template <typename T, typename A>
    // void swap (ft::vector<T, std::allocator<T> >& x, ft::vector<T, std::allocator<T> >& y);
}

class   A
{
    public:
        static  int i;
        int id;
        A(){
            this->id = 0;
            std::cout << "default constructor -> " << id<< std::endl;

        }
        A(int id) {
            this->id = id;
            std::cout << "parametrize constructor -> " << id<< std::endl;
        }
        ~A() {
            std::cout << "destructor -> " << id << std::endl; 
            }
        A(const A &x) {
            std::cout << "copy constructor -> " << x.id << std::endl;
            id = x.id;
            }
        A &operator=(const A &x) {
            std::cout << "copy assignement operator -> " << x.id << std::endl;
            id = x.id;
            return *this;
            }
};

std::ostream& operator<<(std::ostream& out, A a)
{
    out << a.id;
    return (out);
}

// ? iterator
template <typename T, typename Category>
class Iterator;

// ? reverse_iterator
template <typename T>
class reverse_iterator;

template<typename T, typename A = std::allocator<T>  >
class ft::vector
{

    public:

        typedef   T                                     value_type;
        typedef   A                                     allocator_type;
        typedef   T&                                    reference;
        typedef   const T&                              const_reference;
        typedef   T*                                    pointer;
        typedef   const T*                              const_pointer;
        typedef   Iterator<T>                           iterator;
        typedef   Iterator<const T>                     const_iterator;
        typedef   ft::reverse_iterator<iterator>        reverse_iterator;
        typedef   ft::reverse_iterator<const_iterator>  const_reverse_iterator;
        typedef   ptrdiff_t                             difference_type;
        typedef   size_t                                size_type;

    public:

        // ? default constructor
        explicit vector (const allocator_type& alloc = allocator_type());
        
        // ? fill constructor
        // explicit vector (size_type n) : __container(nullptr), __size(n), __capacity (n)
        // {
        //     __container = __alloc.allocate(__capacity);
        //     for (size_type i = 0; i < __size; i++)
        //         __alloc.construct(__container + i);
        // }
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
        
        // ? range constructor
        template <class InputIterator>
        vector (typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type());
        // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

        
        // ? copy constructor
        vector (const vector& x);

        // ? destructor
        ~vector();

        // ? operator=
        vector& operator= (const vector& x);

        // ? size
        size_type size() const;

        // ? max_size
        size_type max_size() const;

        // ? resize
        void resize (size_type n, value_type val = value_type());

        // ? capacity
        size_type capacity() const;

        // ? empty
        bool empty() const;

        // ? reserve
        void reserve (size_type n);

        // ? shrink_to_fit
        void shrink_to_fit();

        // ? operator []
        reference operator[] (size_type n);
        const_reference operator[] (size_type n) const;

        // ? at
        reference at (size_type n);
        const_reference at (size_type n) const;

        // ? front
        reference front();
        const_reference front() const;

        // ? back
        reference back();
        const_reference back() const;

        // ? data

        value_type* data() throw();
        const value_type* data() const throw();

        // ? assigner
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val);

        // ? push_back
        void push_back (const value_type& val);

        // ? pop_back
        void pop_back ();

		// ? swap
		void swap (vector& x);

        // ? clear
        void clear();

        // ? get_allocator
        allocator_type get_allocator() const;
        
        // ? insert
		iterator insert (iterator position, const T& val);

        // ? insert fill
    	void insert (iterator position, size_t n, const T& val);
        
        // ? insert range
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		// ? erase
		iterator erase (iterator position);
		
        // ? erase range
		iterator erase (iterator first, iterator last);

        // ? begin
        iterator begin();
        const_iterator begin() const;

        // ? end
        iterator end();
        const_iterator end() const;

        // ? rbegin
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;

        // ? rend
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // // ? operator!=
        // bool operator!=(const vector& x);

        // // ? operator==
        // bool operator==(const vector& x);

        // // ? operator>
        // bool operator> (const vector& x);
        
        // // ? operator<
        // bool operator< (const vector& x);

        // // ? operator>=
        // bool operator>= (const vector& x);

        // // ? operator<=
        // bool operator<= (const vector& x);

    template <class _T, class  _Alloc>
        friend bool operator== (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs)
    {
        if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
            return (false);
        for (size_type i = 0; i < rhs.size() && i < lhs.size(); i++)
            if (lhs.__container[i] != rhs.__container[i]) return (false);
        return (true);
    }

    template <class _T, class  _Alloc>
        friend bool operator!= (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs) {return !(lhs == rhs);}
    // {
    //     if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
    //         return (true);
    //     for (size_type i = 0; i < rhs.size() && i < lhs.size(); i++)
    //         if (lhs.__container[i] != rhs.__container[i]) return (true);
    //     return (false);
    // }

    template <class _T, class  _Alloc>
        friend bool operator<  (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs)
    {
        for (size_type i = 0; i < rhs.size() && i < lhs.size(); i++)
        {
            if (lhs.__container[i] > rhs.__container[i]) return (false);
            else if (lhs.__container[i] < rhs.__container[i]) return (true);
        }
        if (lhs.size() < rhs.size()) return (true);
        return (false);
    }

    template <class _T, class  _Alloc>
        friend bool operator<= (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs) {return !(rhs < lhs);}

    template <class _T, class  _Alloc>
        friend bool operator>  (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs) { return (rhs < lhs);}

    template <class _T, class  _Alloc>
        friend bool operator>= (const vector<_T, _Alloc>& lhs, const vector<_T, _Alloc>& rhs) {return !(lhs < rhs);}


    private: // *data member
        pointer              __container;
        size_type            __size;
        size_type            __capacity;
        allocator_type       __alloc;
    
    private: // *member function
        void destroyed();
};





#endif

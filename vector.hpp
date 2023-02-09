# ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
#include "ft_containers.hpp"
#include <iostream>
#include <memory>


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
template<typename T, typename A = std::allocator<T>  >
class ft::vector
{

    public:

        typedef   T                           value_type;
        typedef   size_t                      size_type;
        typedef   A                           allocator_type;
        typedef   T&                          reference;
        typedef   const T&                    const_reference;
        typedef   T*                          pointer;
        typedef   const T*                    const_pointer;
        typedef   ptrdiff_t                   difference_type;

    public:

        // ? default constructor
        explicit vector (const allocator_type& alloc = allocator_type());
        
        // ? fill constructor
        explicit vector (size_type n) : __container(nullptr), __size(n), __capacity (n)
        {
            __container = __alloc.allocate(__capacity);
            for (size_type i = 0; i < __size; i++)
                __alloc.construct(__container + i);
        }
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
        
        // ? range constructor
        template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
        
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

        // ? pop_back

		// ! iterator insert (iterator position, const value_type& val);
    	// ! void insert (iterator position, size_type n, const value_type& val);
		// ! template <class InputIterator>
		// ! void insert (iterator position, InputIterator first, InputIterator last);

		// ? erase

		// ! iterator erase (iterator position);
		// ! iterator erase (iterator first, iterator last);

		// ? swap

		void swap (vector& x);

        // ? clear

        void clear();

        // ? get_allocator

        allocator_type get_allocator() const;
        
        // ? iterator

        class iterator
        {
            private:
                pointer ptr;
            public:
                typedef   T                                value_type;
                typedef   T&                               reference;
                typedef   T*                               pointer;
                typedef   ptrdiff_t                        difference_type;
                typedef   std::random_access_iterator_tag  iterator_category;
                iterator ();
                iterator (pointer p);
                iterator (const iterator& x);
                iterator& operator= (const iterator& x);
                bool operator== (const iterator& x) const;
                bool operator!= (const iterator& x) const;
                reference operator* () const;
                pointer operator-> () const;
                iterator& operator++ ();
                iterator& operator-- ();
                iterator operator++ (int);
                iterator operator-- (int);
                difference_type operator- (const iterator& it);
                iterator operator+ (difference_type n) const;
                iterator operator- (difference_type n) const;
                bool operator< (const iterator& x) const;
                bool operator> (const iterator& x) const;
                bool operator>= (const iterator& x) const;
                bool operator<= (const iterator& x) const;
                iterator& operator+= (difference_type n);
                iterator& operator-= (difference_type n);
                reference operator[] (difference_type n) const;
        };

        // ? reverse_iterator

        class reverse_iterator
        {
            private:
                pointer ptr;
            public:
                reverse_iterator ();
                reverse_iterator (pointer p);
                reverse_iterator (const reverse_iterator& x);
                reverse_iterator& operator= (const reverse_iterator& x);
                bool operator== (const reverse_iterator& x) const;
                bool operator!= (const reverse_iterator& x) const;
                reference operator* () const;
                pointer operator-> () const;
                reverse_iterator& operator++ ();
                reverse_iterator& operator-- ();
                reverse_iterator operator++ (int);
                reverse_iterator operator-- (int);
                friend reverse_iterator operator+ (difference_type n, const reverse_iterator& it);
                difference_type operator- (const reverse_iterator& it);
                reverse_iterator operator+ (difference_type n);
                reverse_iterator operator- (difference_type n);
                bool operator< (const reverse_iterator& x) const;
                bool operator> (const reverse_iterator& x) const;
                bool operator>= (const reverse_iterator& x) const;
                bool operator<= (const reverse_iterator& x) const;
                reverse_iterator operator+= (difference_type n) const;
                reverse_iterator operator-= (difference_type n) const;
                reference operator[] (difference_type n) const;
        };
        // typedef     reverse_iterator<const T>      const_reverse_iterator;
        // typedef     iterator<const T>              const_iterator;

        // ? begin

        iterator begin();
        // const_iterator begin() const;

        // ? end

        iterator end();
        // const_iterator end() const;

        // ? rbegin

        reverse_iterator rbegin();
        // const_reverse_iterator rbegin() const;

        // ? rend

        reverse_iterator rend();
        // const_reverse_iterator rend() const;

        bool operator!=(const vector& x)
        {
            if (this->size() != x.size())
                return (true);
            if (this->capacity() != x.capacity())
                return (true);
            for (size_type i = 0; i < x.size() && i < this->size(); i++)
                if (this->__container[i] != x.__container[i]) return (true);
            return (false);
        }
        bool operator==(const vector& x)
        {
            if (this->size() != x.size())
                return (false);
            if (this->capacity() != x.capacity())
                return (false);
            for (size_type i = 0; i < x.size() && i < this->size(); i++)
                if (this->__container[i] != x.__container[i]) return (false);
            return (true);
        }

        bool operator> (const vector& x)
        {
            for (size_type i = 0; i < x.size() && i < this->size(); i++)
            {
                if (this->__container[i] < x.__container[i]) return (false);
                else if (this->__container[i] > x.__container[i]) return (true);
            }
            if (this->size() > x.size()) return (true);
            return (false);
        }

        bool operator< (const vector& x)
        {
            for (size_type i = 0; i < x.size() && i < this->size(); i++)
            {
                if (this->__container[i] > x.__container[i]) return (false);
                else if (this->__container[i] < x.__container[i]) return (true);
            }
            if (this->size() < x.size()) return (true);
            return (false);
        }
        bool operator>= (const vector& x)
        {
            for (size_type i = 0; i < x.size() && i < this->size(); i++)
            {
                if (this->__container[i] < x.__container[i]) return (false);
                else if (this->__container[i] > x.__container[i]) return (true);
            }
            if (this->size() >= x.size()) return (true);
            return (false);
        }

        bool operator<= (const vector& x)
        {
            for (size_type i = 0; i < x.size() && i < this->size(); i++)
            {
                if (this->__container[i] > x.__container[i]) return (false);
                else if (this->__container[i] < x.__container[i]) return (true);
            }
            if (this->size() <= x.size()) return (true);
            return (false);
        }

    


    private:
        pointer              __container;
        size_type            __size;
        size_type            __capacity;
        allocator_type       __alloc;
        void    destroyed()
        {
            for (size_type i = this->__size;i; i--)
                __alloc.destroy(&this->__container[i - 1]);
            if(this->capacity())
                __alloc.deallocate(__container, this->__capacity);
        }
};
ft::vector<int, std::allocator<int> >::iterator operator+ (int n, const ft::vector<int, std::allocator<int> >::iterator& it)
{
    ft::vector<int, std::allocator<int> >::iterator it1(it);
    return (it1 + n);
}
#endif

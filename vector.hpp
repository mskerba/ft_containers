# ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include "ft_containers.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include <iostream>
# include <memory>


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

template <typename T>
class reverse_iterator;

template<typename T, typename A = std::allocator<T>  >
class ft::vector
{

    public:

        typedef   T                                 value_type;
        typedef   A                                 allocator_type;
        typedef   T&                                reference;
        typedef   const T&                          const_reference;
        typedef   T*                                pointer;
        typedef   const T*                          const_pointer;
        typedef   Iterator<T>                       iterator;
        typedef   Iterator<const T>                 const_iterator;
        typedef   ft::reverse_iterator<const_iterator>  const_reverse_iterator;
        typedef   ft::reverse_iterator<iterator>        reverse_iterator;
        typedef   ptrdiff_t                         difference_type;
        typedef   size_t                            size_type;

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

		// ? swap

		void swap (vector& x);

        // ? clear

        void clear();

        // ? get_allocator

        allocator_type get_allocator() const;
        
        // ? insert


		iterator insert (iterator position, const T& val);
    	void insert (iterator position, size_t n, const T& val);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		// ? erase

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

        // ? begin

        iterator begin();
        const_iterator begin() const;

        // ? end

        iterator end();
        const_iterator end() const;

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
        void destroyed()
        {
            if (__container != nullptr)
            {
                for (size_type i = this->__size;i; i--)
                    __alloc.destroy(&this->__container[i - 1]);
                if(this->capacity())
                    __alloc.deallocate(__container, this->__capacity);
            }
        }
};





#endif

# ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include "ft_containers.hpp"


class   A
{
    public:
        static  int i;
        int id;
        A(int id) {
            this->id = id;
            std::cout << "default constructor -> " << id<< std::endl;
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

template<class T>
class ft::vector
{

	public:

		typedef   T                           value_type;
		typedef   size_t                      size_type;
		typedef   std::allocator<T>           allocator_type;
        typedef   T&                          reference;
        typedef   const T&                    const_reference;
        typedef   T*                          pointer;
        typedef   const T*                    const_pointer;
        typedef   ptrdiff_t                   difference_type;

	public:

		void print()
		{
			for(size_type i = 0; i< __size; i++)
				std::cout << __container[i] << " ";
				std::cout << std::endl;
		}

		// default constructor
		explicit vector (const allocator_type& alloc = allocator_type());
		
		// fill constructor
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		
		// range constructor
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		
		// copy constructor
		vector (const vector& x);

		// destructor
		~vector();

		// operator=
		vector& operator= (const vector& x);

		// size
		size_type size() const;

		// max_size
		size_type max_size() const;

		// resize
		void resize (size_type n, value_type val = value_type());


	private:
		pointer				__container;
		size_type			__size;
		size_type			__capacity;
		allocator_type		__alloc;
};


#endif

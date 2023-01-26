# ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include "ft_containers.hpp"


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

		// operator=
		vector& operator= (const vector& x);

		// destructor
		~vector();

	private:
		pointer				__container;
		size_type			__size;
		size_type			__capacity;
		allocator_type		__alloc;
};

template<class T>
ft::vector<T>::explicit vector (const allocator_type& alloc = allocator_type()) :__alloc(alloc), __container(0), __size(0), __capacity(0){}

template<class T>
ft::vector<T>::vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):__alloc(alloc), __size(n), __capacity(n)
{
	__container = __alloc.allocate(n);
	for(size_type i = 0; i< __size; i++)
		__alloc.construct(&__container[i], val);
}

template<class T>
template <class InputIterator> 
ft::vector<T>::vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):__alloc(alloc), __size(last - first), __capacity(__size)
{
	if (first > last)
		throw std::invalid_argument("Invalid range passed to vector constructor");
	this->__container = __alloc.allocate(this->__size);
	size_type i = -1;
	while (first != last)
		__alloc.construct(&__container[++i], *(first++));
}

template<class T>
ft::vector<T>::vector(const vector& x): __size(x.__size), __capacity(x.__capacity)
{
	this->__container = __alloc.allocate(this->__size);
	for(size_type i = 0; i < this->__size; i++)
		__alloc.construct(&__container[i], x.__container[i]);
}

template<class T>
ft::vector& ft::vector<T>::operator= (const ft::vector& x)
{

}

template<class T>
ft::vector<T>::~vector(){}

#endif

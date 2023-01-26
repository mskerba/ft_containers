# ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include "ft_containers.hpp"


template<class T>
class ft::vector
{

	public:

		using value_type = T;
		using size_type = size_t;
		using allocator_type = std::allocator<T>;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_pointer = const T*;
        using difference_type = ptrdiff_t;

	public:

		void print()
		{
			for(size_type i = 0; i< __size; i++)
				std::cout << __container[i] << " ";
				std::cout << std::endl;
		}

		// default constructor
		explicit vector ();	
		
		// range constructor
		template <class InputIterator>
		vector (InputIterator first, InputIterator last);
		
		// fill constructor
		explicit vector (size_type n, const value_type& val = value_type());
		
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
		allocator_type		alloc;
};

template<class T>
ft::vector<T>::vector () : __container(0), __size(0), __capacity(0){}

template<class T>
ft::vector<T>::vector (size_type n, const value_type& val): __size(n), __capacity(n)
{
	__container = alloc.allocate(n);
	for(size_type i = 0; i< __size; i++)
		alloc.construct(&__container[i], val);
}

template<class T>
template <class InputIterator> 
ft::vector<T>::vector (InputIterator first, InputIterator last): __size(last - first), __capacity(__size)
{
	if (first > last)
		throw std::invalid_argument("Invalid range passed to vector constructor");
	this->__container = alloc.allocate(this->__size);
	size_type i = -1;
	while (first != last)
		this->__container[++i] = *(first++);
}

template<class T>
ft::vector<T>::vector(const vector& x): __size(x.__size), __capacity(x.__capacity)
{
	this->__container = alloc.allocate(this->__size);
	for(size_type i = 0; i < this->__size; i++)
		this->__container[i] = x.__container[i];
}

template<class T>
ft::vector& ft::vector<T>::operator= (const ft::vector& x)
{

}

template<class T>
ft::vector<T>::~vector(){}

#endif

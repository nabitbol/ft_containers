/* -------------------------------------------------------------------------- */
/*                                 vector.hpp                                 */
/* -------------------------------------------------------------------------- */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <string>
#include <iostream>

namespace	ft {

template <typename T, typename A = std::allocator<T> >
class vector {

	public:
/* ----------------------------- type definition ---------------------------- */

	typedef	T											value_type;
	typedef	A											allocator_type;
	typedef	std::size_t									size_type;
	typedef	typename allocator_type::reference			reference;
	typedef	typename allocator_type::const_reference	const_reference;
	typedef	typename allocator_type::pointer			pointer;
	typedef	typename allocator_type::const_pointer		const_pointer;

	private :
		allocator_type			_allocator;
		size_type				_size;
		size_type				_cpacity;
		value_type				*_ptr;

	public:
/* ------------------------------ constructors ------------------------------ */

		explicit vector(): _size(0), _ptr(NULL) {};

		explicit vector(size_type n, value_type value): _size(n), _ptr(NULL) {
			_ptr = allocateMemory(n);
			for (size_type i = 0; i < n; i++) {
				saveData((_ptr + i), value);
			}
		};

		explicit vector(const vector<value_type, allocator_type> &instance) {
			*this = instance;
		}

/* ------------------------------- destructor ------------------------------- */

		~vector() {
			deallocateMemory(_ptr, _size);
		};

/* -------------------------------- operators ------------------------------- */

		vector	&operator=(const vector<value_type, allocator_type> &instance) {
			_ptr = allocateMemory(instance._size);
			_size = instance._size;
			copyData(_ptr, instance._ptr, _size);
			return (*this);
		};

		value_type	&operator[](int index) const {
			return (*(_ptr + index));
		};

/* -------------------------------- acessors -------------------------------- */

		size_type	size() {
			return (_size);
		};

		size_type	max_size() {
			return (_allocator.max_size());
		};

		void		resize(size_type n, value_type value) {
			value_type	*tmp = NULL;

			tmp = allocateMemory(n);
			if (_size > n)
				copyData(tmp, _ptr, n);
			if (_size < n) {
				copyData(tmp, _ptr, _size);
				for (size_type j = _size; j < n; j++) {
					saveData((tmp + j), value);
				}
			}
			deallocateMemory(_ptr, _size);
			_ptr = allocateMemory(n);
			copyData(_ptr, tmp, n);
			deallocateMemory(tmp, _size);
			_size = n;
		};

		void		resize(size_type n) {
			value_type	*tmp = NULL;

			tmp = _allocator.allocate(n);
			if (_size > n)
				copyData(tmp, _ptr, n);
			if (_size < n) {
				copyData(tmp, _ptr, _size);
				for (size_type j = _size; j < n; j++) {
					saveData((tmp + j), 0);
				}
			}
			deallocateMemory(_ptr, _size);
			_ptr = allocateMemory(n);
			copyData(_ptr, tmp, n);
			deallocateMemory(tmp, _size);
			_size = n;
		};

/* ---------------------------------- utils --------------------------------- */

	private:

		value_type	*allocateMemory(size_type n) {
				return(_allocator.allocate(n));
		};

		void	deallocateMemory(value_type *ptr, size_type size) {
			_allocator.deallocate(ptr, size);
		};

		void	saveData(value_type *ptr, value_type value) {
			_allocator.construct(ptr, value);
		};

		void	copyData(value_type *copyPtr, value_type *ptr, size_type size) {
			for (size_type i = 0; i < size; i++) {
				saveData((copyPtr + i), *(ptr + i));
			}
		}

	};

}

#endif

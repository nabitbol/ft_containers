/* -------------------------------------------------------------------------- */
/*                                 vector.hpp                                 */
/* -------------------------------------------------------------------------- */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterators.hpp"
#include "type_traits.hpp"
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

namespace	ft {

template <typename T, typename A = std::allocator<T> >
class vector {

	public:
/* ----------------------------- type definition ---------------------------- */

	typedef	T																				value_type;
	typedef	A																				allocator_type;
	typedef	std::size_t																		size_type;
	typedef	typename ft::vectorIterator<value_type>											iterator;
	typedef	typename ft::vectorIterator<const value_type>									const_iterator;
	typedef	typename ft::reverse_iterator<iterator>											reverse_iterator;
	typedef	typename ft::reverse_iterator<const iterator>									const_reverse_iterator;
	typedef	typename allocator_type::reference												reference;
	typedef	typename allocator_type::const_reference										const_reference;
	typedef	typename allocator_type::pointer												pointer;
	typedef	typename allocator_type::const_pointer											const_pointer;

	private :
		allocator_type			_allocator;
		size_type				_size;
		size_type				_capacity;
		value_type				*_ptr;

	public: 
/* ------------------------------ constructors ------------------------------ */

		explicit vector(): _allocator(A()), _size(0), _capacity(0),  _ptr(NULL) {};

		explicit vector(size_type n, value_type value): _allocator(A()), _size(n), _capacity(n), _ptr(NULL) {
			_ptr = allocateMemory(n);
			for (size_type i = 0; i < n; i++) {
				saveData((_ptr + i), value);
			}
		};

		vector(const vector<value_type, allocator_type> &instance) {
			*this = instance;
		}

/* ------------------------------- destructor ------------------------------- */

		~vector() {
			deallocateMemory(_ptr, _size);
		};

/* -------------------------------- operators ------------------------------- */

		vector	&operator=(const vector<value_type, allocator_type> &instance) {
			_allocator = instance._allocator;
			_size = instance._size;
			_capacity = instance._capacity;
			if (_ptr == NULL)
				deallocateMemory(_ptr, _size);
			_ptr = allocateMemory(_capacity);
			copyData(_ptr, instance._ptr, _size);
			return (*this);
		};

		value_type	&operator[](int index) const {
			return (*(_ptr + index));
		};

/* -------------------------------- iterators ------------------------------- */

		iterator begin() {
			return (iterator(_ptr));
		};

		const_iterator begin() const {
			return (const_iterator(_ptr));
		};

		iterator end() {
			return (iterator(_ptr + _size));
		};

		const_iterator end() const {
			return (const_iterator(_ptr + _size));
		};

/* ---------------------------- reverse iterator ---------------------------- */

		reverse_iterator rbegin() {
			return (reverse_iterator(_ptr));
		};

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_ptr));
		};

		reverse_iterator rend() {
			return (reverse_iterator(_ptr + _size));
		};

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(_ptr + _size));
		};

/* -------------------------------- acessors -------------------------------- */

		size_type	size() const {
			return (_size);
		};

		size_type	max_size() const {
			return (_allocator.max_size());
		};

		size_type	capacity() const {
			return (_capacity);
		};

		void		resize(size_type n, value_type value) {
			size_type	newCapacity = 0;

			if (_size >= n) {
				for (size_type i = n; i < _size; i++) {
				deleteData(_ptr, i);
				}
			} else if (_size < n && (newCapacity = getNewCapacity(n)) != _capacity) {
				reallocate(&_ptr, _size, newCapacity);
				saveDataChunk(_ptr, value, _size, n);
				_capacity = newCapacity;
			} else {
				saveDataChunk(_ptr, value, _size, n);
			}
			_size = n;
		};

		void		resize(size_type n) {
			resize(n, 0);
		};

		bool		empty() const {
			if (_size != 0)
				return (false);
			return (true);
		}

		void reserve (size_type n) {
			if (n > _capacity) {
				reallocate(&_ptr, _size, n);
				_capacity = n;
			}
		};

		reference at (size_type n) {
			if (n > _size || n < 0)  {
				std::stringstream tmp;
				tmp << "vector::_M_range_check: __n (which is " << n;
				tmp << ") >= this->size() (which is ";
				tmp << _size << ")";
				throw std::out_of_range(tmp.str());
			}
			return (*(_ptr + n));
		};

		const_reference at (size_type n) const {
			if (n > _size || n < 0) {
				std::stringstream tmp;
				tmp << "vector::_M_range_check: __n (which is " << n;
				tmp << ") >= this->size() (which is ";
				tmp << _size << ")";
				throw std::out_of_range(tmp.str());
			}
			return (*(_ptr + n));
		};

		 reference front() {
			 return (*_ptr);
		 };

		reference front() const {
			 return (*_ptr);
		 };

		 reference back() {
			 return (*(_ptr + (_size - 1)));
		 };

		reference back() const {
			 return (*(_ptr + (_size - 1)));
		 };

/* ---------------------------------- utils --------------------------------- */

	private:

		value_type	*allocateMemory(size_type n) {
				return(_allocator.allocate(n));
		};

		void	deallocateMemory(value_type *ptr, size_type size) {
			_allocator.deallocate(ptr, size);
		};

		void	deleteData(value_type *ptr, size_type index) {
			_allocator.destroy((ptr + index));
		}

		void	saveData(value_type *ptr, value_type value) {
			_allocator.construct(ptr, value);
		};

		void	saveDataChunk(value_type *ptr, value_type value, size_type start, size_type end) {
			for (size_type j = start; j < end; j++) {
				saveData((ptr + j), value);
			}
		}

		void	copyData(value_type *copyPtr, value_type *ptr, size_type size) {
			for (size_type i = 0; i < size; i++) {
				saveData((copyPtr + i), *(ptr + i));
			}
		}

		size_type	getNewCapacity(size_type n) {
			if (n > _capacity && n < (_capacity * 2)) {
				return (_capacity * 2);
			} else if (n > _capacity && n >= (_capacity * 2)) {
				return (n);
			} else {
				return (_capacity);
			}
		};

		void reallocate(value_type **ptr, size_type size, size_type newCapacity) {
			value_type	*tmp = NULL;

			tmp = allocateMemory(newCapacity);
			copyData(tmp, *ptr, size);
			deallocateMemory(*ptr, size);
			*ptr = tmp;
		};

	};

}

#endif

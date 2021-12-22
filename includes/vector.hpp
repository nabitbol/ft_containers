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
		allocator_type			allocator;
		size_type				size;
		value_type				*ptr;

	public:
/* ------------------------------ constructors ------------------------------ */

		vector(): size(0), ptr(NULL) {};

		vector(size_type n, value_type value): size(n), ptr(NULL) {
			ptr = allocator.allocate(n);
			for (size_type i = 0; i < n; i++) {
				allocator.construct((ptr + i), value);
			}
		};

/* ------------------------------- destructor ------------------------------- */

		~vector() {
			allocator.deallocate(ptr, size);
		};

	};
}

#endif

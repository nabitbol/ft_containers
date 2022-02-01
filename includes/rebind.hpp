/* -------------------------------------------------------------------------- */
/*                                 rebind.hpp                                 */
/* -------------------------------------------------------------------------- */

#ifndef REBIND_HPP
# define REBIND_HPP

namespace ft {

	template <class Type>
	struct rebind {
		typedef std::allocator<Type> other;
	};

}

#endif

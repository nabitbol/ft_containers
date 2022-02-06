/* -------------------------------------------------------------------------- */
/*                                   set.hpp                                  */
/* -------------------------------------------------------------------------- */

#ifndef SET_HPP
# define SET_HPP

#include "map.hpp"

namespace ft
{
	template<typename T, typename Compare = std::less<T> >
	class Set: public ft::map<T, T, Compare> {

		 public:

			typedef map<T, T, Compare> base;

			using typename base::difference_type;
			using typename base::size_type;
			using typename base::key_type;
			using typename base::value_type;
			using typename base::pointer;
			using typename base::const_pointer;
			using typename base::reference;
			using typename base::const_reference;
			using typename base::key_compare;
			using typename base::value_compare;
			using typename base::tree_type;
			using typename base::node_type;
			using typename base::node_pointer;
			using typename base::iterator;
			using typename base::const_iterator;
			using typename base::reverse_iterator;
			using typename base::const_reverse_iterator;

			Set(): base() {};

			Set(iterator first, iterator last): base(first, last) {};

			Set(Set const &other): base(other) {};

			virtual ~Set() {};

/* -------------------------------- operators ------------------------------- */

			Set &operator=(Set const &other) {
				this->base::operator=(other);
				return (*this);
			};

	};
}

#endif

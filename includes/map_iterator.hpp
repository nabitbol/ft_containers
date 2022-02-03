/* -------------------------------------------------------------------------- */
/*                              map_iterator.hpp                              */
/* -------------------------------------------------------------------------- */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <memory>
#include "iterators_utils.hpp"

namespace ft {

	template<
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T& >
	class mapIterator : public iterator<ft::bidirectional_iterator_tag,
							Distance,
							Pointer,
							Reference> {

	 public:
/* ----------------------------- type definition ---------------------------- */

	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;

	Pointer	element;

	mapIterator(): element() {};

	mapIterator(pointer element): element(element) {};

	mapIterator(const mapIterator<value_type> &instance) {
		*this = instance;
	};

	virtual ~mapIterator() {};

/* ------------------------- implicit convertibility ------------------------ */

	/*
	** link to the implicit convertible method : https://www.fluentcpp.com/2018/01/05/making-strong-types-implicitly-convertible/
	*/

	operator	mapIterator<const value_type>() const {
		return (mapIterator<const value_type>(element));
	};

	mapIterator	&operator=(const mapIterator<value_type> &instance) {
		element = instance.element;
		return (*this);
	};

	/*
	** comparison
	*/

	friend bool operator==(const mapIterator<value_type> &lhs, const mapIterator<value_type> &rhs) {
		if (lhs.element == rhs.element)
			return (true);
		return (false);
	};

	friend bool operator!=(const mapIterator<value_type> &lhs, const mapIterator<value_type> &rhs) {
		if (lhs.element != rhs.element)
			return (true);
		return (false);
	};

	/*
	**	incrementation/decrementation
	*/

	mapIterator   &operator++(void) {
		element = element->next(element);
		return (*this);
	};

	mapIterator   &operator--(void) {
		element = element->previous(element);
		return (*this);
	};

	mapIterator   operator++(int) { // post-increment, return unmodified copy
		mapIterator copy(*this);
		++(*this);
		return (copy);
	};

	mapIterator   operator--(int) { // post-increment, return unmodified copy
		mapIterator copy(*this);
		--(*this);
		return (copy);
	};

	/*
	**	dereferencing
	*/

	typename T::value_type	&operator*(void) const {
		return (element->value);
	};

	typename T::value_type	*operator->(void) const {
		return (&(element->value));
	};

	};

}

#endif

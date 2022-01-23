#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <memory>
#include "iterators_utils.hpp"

namespace ft {

/* ----------------------------- vector iterator ---------------------------- */

template<
    class T,
    class Distance = std::ptrdiff_t,
    class Pointer = T*,
    class Reference = T& >
class vectorIterator : public iterator<ft::random_access_iterator_tag,
						Distance,
						Pointer,
						Reference> {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;

	Pointer	element;

 /* ------------------------------ constructors ------------------------------ */

	vectorIterator(): element() {};

	vectorIterator(pointer element): element(element) {};

	vectorIterator(const vectorIterator<value_type> &instance) {
		*this = instance;
	};

	virtual ~vectorIterator() {};

/* ------------------------- implicit convertibility ------------------------ */

	/*
	** link to the implicit convertible method : https://www.fluentcpp.com/2018/01/05/making-strong-types-implicitly-convertible/
	*/

	operator	vectorIterator<const value_type>() const {
		return (vectorIterator<const value_type>(element));
	};

/* -------------------------------- operators ------------------------------- */

	vectorIterator	&operator=(const vectorIterator<value_type> &instance) {
		element = instance.element;
		return (*this);
	};

	/*
	** comparison
	*/

	friend bool operator==(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		if (lhs.element == rhs.element)
			return (true);
		return (false);
	};

	friend bool operator!=(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		if (lhs.element != rhs.element)
			return (true);
		return (false);
	};

	friend bool operator>(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		if (lhs.element > rhs.element)
				return (true);
		return (false);
	};

	friend bool operator>=(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		if (lhs.element >= rhs.element)
				return (true);
		return (false);
	};

	friend bool operator<(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		if (lhs.element < rhs.element)
				return (true);
		return (false);
	};

	friend bool operator<=(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		if (lhs.element <= rhs.element)
				return (true);
		return (false);
	};

	/*
	** substraction/addition
	*/

	friend difference_type operator+(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		return (*(lhs.element) + *(rhs.element));
	};

	friend difference_type operator-(const vectorIterator<value_type> &lhs, const vectorIterator<value_type> &rhs) {
		return (lhs.element - rhs.element);
	};


	friend vectorIterator operator+(const difference_type &rhs, const vectorIterator<value_type> &lhs) {
		return (lhs.element + rhs);
	};

	friend vectorIterator operator-(const vectorIterator<value_type> &lhs, const difference_type &rhs) {
		return (lhs.element - rhs);
	};

	vectorIterator operator+(const difference_type &instance) {
		return (element + instance);
	};

	vectorIterator operator+=(const typename ft::vectorIterator<T>::difference_type value) {
		return (element = (element + value));
	};

	vectorIterator operator-=(const typename ft::vectorIterator<T>::difference_type value) {
		return (element = (element - value));
	};

	/*
	**	incrementation/decrementation
	*/

	vectorIterator   &operator++(void) {
		element++;
		return (*this);
	};

	vectorIterator   &operator--(void) {
		element--;
		return (*this);
	};

	vectorIterator   operator++(int) { // post-increment, return unmodified copy
		vectorIterator copy(*this);
		++(*this);
		return (copy);
	};

	vectorIterator   operator--(int) { // post-increment, return unmodified copy
		vectorIterator copy(*this);
		--(*this);
		return (copy);
	};

	/*
	**	dereferencing
	*/

	reference	operator*(void) const {
		return (*element);
	};

	Pointer		operator->(void) const {
		return (element);
	};

	reference operator[](difference_type index) const {
		return ((this->element[index]));
	};

};

};

#endif

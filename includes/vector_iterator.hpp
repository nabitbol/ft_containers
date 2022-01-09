#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <memory>

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

	vectorIterator(): element(NULL) {};

	vectorIterator(pointer element): element(element) {};

	vectorIterator(const vectorIterator<value_type> &instance) {
		*this = instance;
	};

	~vectorIterator() {};

/* ------------------------- implicit convertibility ------------------------ */

	/*
	** link to the implicit convertible method : https://www.fluentcpp.com/2018/01/05/making-strong-types-implicitly-convertible/
	*/

	operator	vectorIterator<const value_type>() const {
		return element;
	};

/* -------------------------------- operators ------------------------------- */


	vectorIterator	&operator=(const vectorIterator<value_type> &instance) {
		element = instance.element;
		return (*this);
	};

	/*
	** comparison
	*/

	bool   operator==(const vectorIterator<value_type> &instance) {
		if (element == instance.element)
			return (true);
		return (false);
	};

	bool   operator!=(const vectorIterator<value_type> &instance) {
		if (element != instance.element)
			return (true);
		return (false);
	};

	/*
	** substraction/addition
	*/

	vectorIterator operator+(const vectorIterator<value_type> &instance) {
		return(*this + instance);
	};

	vectorIterator operator-(const vectorIterator<value_type> &instance) {
		return(*this - instance);
	};

	vectorIterator operator+(const difference_type &instance) const {
		return(element + instance);
	};

	vectorIterator operator-(const difference_type &instance) const {
		return(element - instance);
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
		operator++();
		return (copy);
	};

	vectorIterator   operator--(int) { // post-increment, return unmodified copy
		vectorIterator copy(*this);
		operator--();
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

};

template<typename T>
ft::vectorIterator<T> operator+(typename ft::vectorIterator<T>::difference_type value, ft::vectorIterator<T> &instance) {
    return (&(*instance) + value);
};

template<typename T>
ft::vectorIterator<T> operator-(typename ft::vectorIterator<T>::difference_type value, ft::vectorIterator<T> &instance) {
    return (&(*instance) - value);
};

};

#endif

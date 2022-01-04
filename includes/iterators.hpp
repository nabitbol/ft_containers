/* -------------------------------------------------------------------------- */
/*                                iterators.hpp                               */
/* -------------------------------------------------------------------------- */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include <memory>


namespace ft {

/* ---------------------------------- tags ---------------------------------- */

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };
struct contiguous_iterator_tag: public random_access_iterator_tag { };

/* ------------------------------ Base iterator ----------------------------- */

template<
    class Category,
    class T,
    class Distance = std::ptrdiff_t,
    class Pointer = T*,
    class Reference = T& >
class iterator : public Category {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
	typedef Category  iterator_category;

};

template <class Iterator>
class iterator_traits {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;

};



template <class Iterator> 
class reverse_iterator {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef	Iterator										iterator_type;

 private:

	pointer		_element;

 public:

 /* ------------------------------ constructors ------------------------------ */

	reverse_iterator() : _element(NULL) {};

	explicit reverse_iterator (iterator_type it) {
		*this->_element = it->_element;	
	};

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it) {
		*this = rev_it;
	};

/* ------------------------- implicit convertibility ------------------------ */

	/*
	** link to the implicit convertible method : https://www.fluentcpp.com/2018/01/05/making-strong-types-implicitly-convertible/
	*/

	operator	reverse_iterator<const value_type>() const {
		return _element;
	};

/* -------------------------------- operators ------------------------------- */

	/*
	**	incrementation/decrementation
	*/

	reverse_iterator   &operator++(void) {
		_element++;
		return (*this);
	};

	reverse_iterator   &operator--(void) {
		_element++;
		return (*this);
	};

	/*
	**	dereferencing
	*/

	reference	operator*(void) const {
		return (*_element);
	};

	pointer		operator->(void) const {
		return (_element);
	};


};

/* ----------------------------- vector iterator ---------------------------- */

template<
    class T,
    class Distance = std::ptrdiff_t,
    class Pointer = T*,
    class Reference = T& >
class vectorIterator : iterator<ft::random_access_iterator_tag,
						Distance,
						Pointer,
						Reference> {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;

 private:

	Pointer	_element;

 public:
 /* ------------------------------ constructors ------------------------------ */

	vectorIterator(): _element(NULL) {};

	vectorIterator(pointer element): _element(element) {};

	vectorIterator(const vectorIterator<value_type> &instance) {
		*this = instance;
	};

	~vectorIterator() {};

/* ------------------------- implicit convertibility ------------------------ */

	/*
	** link to the implicit convertible method : https://www.fluentcpp.com/2018/01/05/making-strong-types-implicitly-convertible/
	*/

	operator	vectorIterator<const value_type>() const {
		return _element;
	};

/* -------------------------------- operators ------------------------------- */


	vectorIterator	&operator=(const vectorIterator<value_type> &instance) {
		_element = instance._element;
		return (*this);
	};

	bool   operator==(const vectorIterator<value_type> &instance) {
		if (_element == instance._element)
			return (true);
		return (false);
	};

	bool   operator!=(const vectorIterator<value_type> &instance) {
		if (_element != instance._element)
			return (true);
		return (false);
	};

	/*
	**	incrementation/decrementation
	*/

	vectorIterator   &operator++(void) {
		_element++;
		return (*this);
	};

	vectorIterator   &operator--(void) {
		_element--;
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
		return (*_element);
	};

	Pointer		operator->(void) const {
		return (_element);
	};

};

};

#endif

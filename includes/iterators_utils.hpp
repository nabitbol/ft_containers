/* -------------------------------------------------------------------------- */
/*                                iterators.hpp                               */
/* -------------------------------------------------------------------------- */

#ifndef ITERATORS_UTILS_HPP
# define ITERATORS_UTILS_HPP

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

template< class T >
struct iterator_traits<T*> {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef typename T::value_type			value_type;
	typedef typename T::difference_type		difference_type;
	typedef typename T::pointer				pointer;
	typedef typename T::reference			reference;
	typedef typename T::iterator_category	iterator_category;

};

template< class T >
struct iterator_traits<const T*> {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef typename T::value_type			value_type;
	typedef typename T::difference_type		difference_type;
	typedef typename T::pointer				pointer;
	typedef typename T::reference			reference;
	typedef typename T::iterator_category	iterator_category;

};

template <class Iterator> 
class reverse_iterator {

 public:
/* ----------------------------- type definition ---------------------------- */

	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef typename ft::iterator_traits<Iterator>::reference			reference;
	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef	Iterator										iterator_type;

	iterator_type		element;

 /* ------------------------------ constructors ------------------------------ */

	reverse_iterator() : element() {};

	explicit reverse_iterator (iterator_type it): element(it) {};

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it): element(rev_it.base()){
	};

	virtual ~reverse_iterator() {};

/* -------------------------- base member function -------------------------- */

	iterator_type base() const {
		return (element);
	};

/* -------------------------------- operators ------------------------------- */

	/*
	**	assignation
	*/

	reverse_iterator &operator=(const reverse_iterator &instance) {
		if (this != &instance)
			this->element = instance.element;
		return(*this);
	}

	/*
	** substraction/addition
	*/

	friend reverse_iterator operator+(const reverse_iterator<iterator_type> &lhs, const reverse_iterator<iterator_type> &rhs) {
		return (lhs.element - rhs.element);
	};

	reverse_iterator operator+(const difference_type &value) {
		return (reverse_iterator(element - value));
	};

	difference_type operator-(const reverse_iterator<iterator_type> &rhs) {
		return (rhs.base() - (element));
	};

	reverse_iterator operator-(const difference_type &value) {
		return (reverse_iterator(element + value));
	};

	reverse_iterator &operator+=(const difference_type value) {
		element = (element - value);
		return (*this);
	};

	reverse_iterator &operator-=(const difference_type value) {
		element = (element + value);
		return (*this);
	};

	/*
	**	incrementation/decrementation
	*/

	reverse_iterator   &operator++(void) {
		element--;
		return (*this);
	};

	reverse_iterator   &operator--(void) {
		element++;
		return (*this);
	};

	reverse_iterator   operator++(int) { // post-increment, return unmodified copy
		reverse_iterator copy = (*this);
		operator++();
		return (copy);
	};

	reverse_iterator   operator--(int) { // post-increment, return unmodified copy
		reverse_iterator copy = (*this);
		operator--();
		return (copy);
	};

	/*
	**	dereferencing
	*/

	reference	operator*(void) const {
		iterator_type	copy = element;
		return (*(--copy));
	};

	pointer		operator->(void) const {
		return (&(operator*()));
	};

	reference	operator[](int index) const {
		return (element[-index - 1]);
	};

};

template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
					return (lhs.base() == rhs.base());
				};

template <class Iterator, class Iterator_C>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator_C>& rhs) {
					return (lhs.base() == rhs.base());
				};

template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
						return (lhs.base() != rhs.base());
				};

template <class Iterator, class Iterator_C>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator_C>& rhs) {
						return (lhs.base() != rhs.base());
				};

template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
						return (lhs.base() > rhs.base());
				};

template <class Iterator, class Iterator_C>
	bool operator< (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator_C>& rhs) {
						return (lhs.base() > rhs.base());
				};

template <class Iterator>
	bool operator<=  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
						return (lhs.base() >= rhs.base());
				};

template <class Iterator, class Iterator_C>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator_C>& rhs) {
						return (lhs.base() >= rhs.base());
				};

template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
						return (lhs.base() < rhs.base());
				};

template <class Iterator, class Iterator_C>
	bool operator> (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator_C>& rhs) {
						return (lhs.base() < rhs.base());
				};

template <class Iterator>
	bool operator>=  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
						return (lhs.base() <= rhs.base());
				};

template <class Iterator, class Iterator_C>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator_C>& rhs) {
						return (lhs.base() <= rhs.base());
				};

template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) {
				return (reverse_iterator<Iterator>(rev_it.base() - n));
			};

template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) {
				return (rev_it.base() + n);
			};


/* -------------------------------- functions ------------------------------- */

template <class InputIterator, class Distance>
	void advance (InputIterator& it, Distance n) {
		it += n;
	};

template<class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last) {
		std::size_t index;

		index = 0;
		while (first != last) {
			index++;
			first++;
		};
		return (index);
	};

};

#endif

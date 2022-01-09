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
	** substraction/addition
	*/

	reverse_iterator operator+(const reverse_iterator<iterator_type> &instance) {
		return (element - instance);
	};

	reverse_iterator operator-(const reverse_iterator<iterator_type> &instance) {
		return (element + instance);
	};

	void operator+=(const difference_type value) {
		element = (element - value);
	};

	void operator-=(const difference_type value) {
		element = (element + value);
	};

	/*
	**	incrementation/decrementation
	*/

	reverse_iterator   &operator++(void) {
		return (--element);
	};

	reverse_iterator   &operator--(void) {
		return (++element);
	};

	reverse_iterator   operator++(int) { // post-increment, return unmodified copy
		return (element--);
	};

	reverse_iterator   operator--(int) { // post-increment, return unmodified copy
		return (element++);
	};

	/*
	**	dereferencing
	*/

	reference	operator*(void) const {
		return (*element);
	};

	pointer		operator->(void) const {
		return (element);
	};

	value_type	operator[](int index) const{
		return (element[index]);
	};

};

template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
					return (lhs.base() == rhs.base());
				};

template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
						return (lhs.base() != rhs.base());
				};

template <class Iterator>
  bool operator<  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
					return(lhs.base() < rhs.base());
				};

template <class Iterator>
  bool operator<=  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
					return(lhs.base() <= rhs.base());
				};

template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
					return(lhs.base() > rhs.base());
				};

template <class Iterator>
  bool operator>=  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
					return(lhs.base() >= rhs.base());
				};

template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) {
				return(rev_it - n);
			};

template <class Iterator>
	reverse_iterator<Iterator> operator- (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) {
				return(rev_it + n);
			};

};

#endif

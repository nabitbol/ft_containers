/* -------------------------------------------------------------------------- */
/*                              map_iterator.hpp                              */
/* -------------------------------------------------------------------------- */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <memory>
#include "iterators_utils.hpp"

namespace ft {

template< typename T, typename N >
class mapIterator : public iterator<ft::bidirectional_iterator_tag,
						T,
						std::ptrdiff_t,
						T*,
						T&> {


	 public:

/* ----------------------------- type definition ---------------------------- */
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef std::ptrdiff_t difference_type;
	typedef N node_type;
	typedef node_type* node_pointer;
	typedef ft::bidirectional_iterator_tag iterator_category;

	node_pointer	element;

	mapIterator(): element() {};

	mapIterator(node_pointer element): element(element) {};

	mapIterator(const mapIterator<value_type, node_type> &instance) {
		*this = instance;
	};

	virtual ~mapIterator() {};

/* ------------------------- implicit convertibility ------------------------ */

	/*
	** link to the implicit convertible method : https://www.fluentcpp.com/2018/01/05/making-strong-types-implicitly-convertible/
	*/

	operator	mapIterator<const value_type, const node_type>() const {
		return (mapIterator<const value_type, const node_type>(element));
	};

	mapIterator	&operator=(const mapIterator<value_type, node_type> &instance) {
		element = instance.element;
		return (*this);
	};

	/*
	** comparison
	*/

	friend bool operator==(const mapIterator<value_type, node_type> &lhs, const mapIterator<value_type, node_type> &rhs) {
		if (lhs.element == rhs.element)
			return (true);
		return (false);
	};

	friend bool operator!=(const mapIterator<value_type, node_type> &lhs, const mapIterator<value_type, node_type> &rhs) {
		if (lhs.element != rhs.element)
			return (true);
		return (false);
	};

	/*
	**	incrementation/decrementation
	*/

	mapIterator   &operator++(void) {
		element = next(element);
		return (*this);
	};

	mapIterator   &operator--(void) {
		element = previous(element);
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

	reference operator*(void) const {
		return (element->value);
	};

	pointer operator->(void) const {
		return (&element->value);
	};

	private:

	node_pointer next(node_pointer node)
		{
			if (node->right != NULL) {
				node = node->right;
				while (node->left != NULL)
					node = node->left;
			} else {
				node_pointer tmp = node->parent;
				while (node == tmp->right) {
					node = tmp;
					tmp = tmp->parent;
				}
				if (node->right != tmp)
					node = tmp;
			}
			return node;
	};

	node_pointer previous(node_pointer node)
	{
		if (node->color == RED && node->parent->parent == node)
			node = node->right;
		else if (node->left != NULL) {
			node_pointer tmp = node->left;
			while (tmp->right != NULL)
				tmp = tmp->right;
			node = tmp;
		} else {
			node_pointer tmp = node->parent;
			while (node == tmp->left) {
				node = tmp;
				tmp = tmp->parent;
			}
			node = tmp;
		}
		return node;
	};

	};
}

#endif

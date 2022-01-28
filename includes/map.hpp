/* -------------------------------------------------------------------------- */
/*                                   map.hpp                                  */
/* -------------------------------------------------------------------------- */

#ifndef MAP_HPP
# define MAP_HPP

#include "dependency.hpp"

namespace ft {

	template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
			typename _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	class map {

	 public:

		typedef typename _Key									key_type;
		typedef typename _Tp									mapped_type;
		typedef typename ft::pair<const _Key, _Tp>				value_type;
		typedef typename _Compare								key_compare;
		typedef typename _Alloc									allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef	typename allocator_type::const_pointer			const_pointer;
		typedef	std::size_t										size_type;
		typedef	std::ptrdiff_t									difference_type;

	 private
		red_black_tree	_tree;
		size_type		_size;
		allocator_type	_allocator;
		key_compare		_comp;

/* ------------------------------ constructors ------------------------------ */

		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _size(0), _allocator(alloc), _comp(comp) {};

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());

		// map (const map& x);

		~map();

/* -------------------------------- operators ------------------------------- */

 		map &operator=(const map &instance) {
			 _size = instance._size;
			 _allocator = instance._allocator;
			_comp = instance._comp;
		 };

		bool empty() const {
			return (_size == 0);
		};

		size_type size() const {
			return (_size);
		};

		size_type max_size() const {
			return (allocator.max_size());
		};
	};

}

#endif

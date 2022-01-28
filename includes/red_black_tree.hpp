/* -------------------------------------------------------------------------- */
/*                             red_black_tree.hpp                             */
/* -------------------------------------------------------------------------- */

#ifndef RED_BALCK_TREE_HPP
# define RED_BALCK_TREE_HPP

namespace ft {

	enum node_color {
		RED = false,
		BLACK = true
	};

	template <typename T>
	class red_black_tree {

	 public:

		typedef red_black_tree *		ptr;
		typedef const red_black_tree *	const_ptr;
		typedef	T						value_type;

		node_color	color;
		value_type	value;
		ptr			right;
		ptr			left;
		ptr			parent;

/* ------------------------------- constructor ------------------------------ */

	red_black_tree(value_type &val): color(BLACK), value(val), right(NULL), left(NULL), parent(NULL) {};

	};

}

#endif

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

	enum node_direction {
		RIGHT = false,
		LEFT = true
	};

	template <typename T>
	struct red_black_tree {

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

	red_black_tree(value_type &val): color(RED), value(val), right(NULL), left(NULL), parent(NULL) {};

	~red_black_tree();

	};


	template <typename T>
	struct node_data {
		node_direction		direction;
		red_black_tree<T>	*node;

/* ------------------------------- constructor ------------------------------ */

		node_data(const node_direction &dir, red_black_tree<T> *tree) : direction(dir), node(tree) {};

		~node_data() {};
	};


}

#endif

/* -------------------------------------------------------------------------- */
/*                             red_black_tree.hpp                             */
/* -------------------------------------------------------------------------- */

#ifndef RED_BALCK_TREE_HPP
#define RED_BALCK_TREE_HPP

namespace ft
{

	enum node_color
	{
		RED = false,
		BLACK = true
	};

	enum node_direction
	{
		NONE = 0,
		RIGHT = 1,
		LEFT = 2
	};

	template <typename T>
	struct red_black_tree
	{

	public:

		typedef red_black_tree * ptr;
		typedef const red_black_tree * const_ptr;
		typedef T value_type;

		node_color color;
		value_type value;
		ptr right;
		ptr left;
		ptr parent;

		/* ------------------------------- constructor ------------------------------ */

		red_black_tree(value_type &val = value_type()) : color(RED), value(val), right(NULL), left(NULL), parent(NULL){};

		~red_black_tree() {};

		operator	red_black_tree<const value_type>() const {
			return (red_black_tree<const value_type>(value));
		};

		red_black_tree &operator=(const red_black_tree &instance)
		{
			color = instance.color;
			value = instance.value;
			right = instance.right;
			left = instance.left;
			parent = instance.parent;
			return (*this);
		};

		static ptr min(ptr node)
		{
			ptr tmp = node;
			while (tmp->left != NULL)
				tmp = tmp->left;
			return tmp;
		};

		static const ptr const_min(const ptr node)
		{
			ptr tmp = node;
			while (tmp->left != NULL)
				tmp = tmp->left;
			return tmp;
		};

		static ptr max(ptr node)
		{
			ptr tmp = node;
			while (tmp->right != NULL) {
				tmp = tmp->right;
			}
			return tmp;
		};

		static const ptr const_max(const ptr node)
		{
			ptr tmp = node;
			while (tmp->right != NULL)
				tmp = tmp->right;
			return tmp;
		};
	};

	template <typename T>
	struct node_data
	{
		node_direction direction;
		red_black_tree<T> *node;

		/* ------------------------------- constructor ------------------------------ */

		node_data(const node_direction &dir, red_black_tree<T> *tree) : direction(dir), node(tree){};

		~node_data(){};
	};
}

#endif

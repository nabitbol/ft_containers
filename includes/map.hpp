/* -------------------------------------------------------------------------- */
/*                                   map.hpp                                  */
/* -------------------------------------------------------------------------- */

#ifndef MAP_HPP
# define MAP_HPP

#include "dependency.hpp"
#include "class.format.hpp"
#include "map_iterator.hpp"

namespace ft {

	template <typename _Key, typename _Tp, class _Compare = std::less<_Key>,
			class _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	class map {

	 public:

		typedef  _Key															key_type;
		typedef  _Tp															mapped_type;
		typedef  ft::pair<const _Key, _Tp>										value_type;
		typedef  _Compare														key_compare;
		typedef  _Alloc															allocator_type;
		typedef	typename allocator_type::reference								reference;
		typedef	typename allocator_type::const_reference						const_reference;
		typedef	typename allocator_type::pointer								pointer;
		typedef	typename allocator_type::const_pointer							const_pointer;
		typedef	typename ft::mapIterator<red_black_tree<value_type>>			iterator;
		typedef	typename ft::mapIterator<const red_black_tree<value_type>>		const_iterator;
		typedef	typename ft::reverse_iterator<iterator>							reverse_iterator;
		typedef	typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef	std::size_t														size_type;
		typedef	std::ptrdiff_t													difference_type;


	 private:

		typedef	red_black_tree<value_type>						rbt;

	 public:
		rbt												*_tree;
		rbt												*_begin;
		rbt												*_sentinal;
		size_type										_size;
		allocator_type									_allocator;
		typename _Alloc::template rebind<rbt>::other	_allocatorNode;
		key_compare										_comp;

/* ------------------------------ constructors ------------------------------ */

	 public:

		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(NULL), _begin(NULL), _sentinal(NULL), _size(0), _allocator(alloc), _comp(comp) {};

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());

		// map (const map& x);

		~map() {
			clear();
		};

/* -------------------------------- operators ------------------------------- */

 		map &operator=(const map &instance) {
			 clear();
			 _tree = instance._tree;
			 _begin = instance.begin;
			 _sentinal = instance.end;
			 _size = instance._size;
			 _allocator = instance._allocator;
			_comp = instance._comp;
		 };

/* -------------------------------- iterators ------------------------------- */

		iterator begin() {
			return (iterator(_tree->min(_begin)));
		};

		const_iterator begin() const {
			return (const_iterator(_tree->const_min(_begin)));
		};

		iterator end() {
			value_type tmp;
			rbt *sentinal = createNode(tmp);
			node_data<value_type> node_data(RIGHT, _tree->max(_begin));
			linkNode(node_data, sentinal);
			_sentinal = sentinal;
			return (iterator(sentinal));
		};

		const_iterator end() const {
			rbt *sentinal = createNode(NULL);
			node_data<value_type> node_data(RIGHT, _tree->const_max(_begin));
			linkNode(node_data, sentinal);
			_sentinal = sentinal;
			return (const_iterator(sentinal));
		};

/* -------------------------------- capacity -------------------------------- */

		bool empty() const {
			return (_size == 0);
		};

		size_type size() const {
			return (_size);
		};

		size_type max_size() const {
			return (_allocator.max_size());
		};

/* -------------------------------- modifiers ------------------------------- */

		void clear() {
			rbt *tmp = _begin;

			clear(tmp);
		};

/* ------------------------------- operations ------------------------------- */

	iterator lower_bound (const key_type& k) {
		iterator ite = this->end();

		for (iterator itb = this->begin(); itb != ite; itb++) {
			if (!this->_comp(itb->first, k))
				return (itb);
		}
		return (ite);
	}

	const_iterator lower_bound (const key_type& k) const {
		const_iterator ite = this->end();

		for (const_iterator itb = this->begin(); itb != ite; itb++) {
			if (!this->_comp(itb->first, k))
				return (itb);
		}
		return (ite);
	}

	iterator	upper_bound (const key_type& k) {
		iterator ite = this->end();

		for (iterator itb = this->begin(); itb != ite; itb++) {
			if (this->_comp(k, itb->first)) {
				return (itb);
			}
		}
		return (ite);
	}

	const_iterator	upper_bound (const key_type& k) const {
		const_iterator ite = this->end();

		for (const_iterator itb = this->begin(); itb != ite; itb++) {
			if (this->_comp(k, itb->first)) {
				itb++;
				return (itb);
			}
		}
		return (ite);
	}

	private:

		void clear(rbt *node) {
			if (!node)
				return;
			if (node->left) clear(node->left);
			if (node->right) clear(node->right);
			clearNode(node);
		};

	 private:

		value_type	*allocateMemory(size_type n) {
				return(_allocator.allocate(n));
		};

		void	deallocateMemory(value_type *ptr, size_type size) {
			_allocator.deallocate(ptr, size);
		};

		void	saveData(value_type *ptr, value_type value) {
			_allocator.construct(ptr, value);
		};

		void	deleteData(value_type *ptr, size_type index) {
			_allocator.destroy((ptr + index));
		}

		void	addNode(value_type &value) {
			if (_tree == NULL) {
				_tree = createNode(value);
				_begin = _tree;
			} else {
				if (_tree->min(_begin) == _sentinal || _tree->max(_begin) == _sentinal) {
					clearNode(_sentinal);
					_size += 1;
				}
				node_data<value_type> node_data = findNewNodeLocation(value);
				if (node_data.direction != NONE) {
					linkNode(node_data, createNode(value));
					checkRb(node_data);
				}
			}
			_size += 1;
		};

		rbt	*createNode(value_type &value) {
			rbt	*node = _allocatorNode.allocate(sizeof(node) * 1);
			_allocatorNode.construct(node, value);
			return (node);
		};

		node_data<value_type>	findNewNodeLocation(value_type &value) {
			rbt	*tmp = _begin;

			return (findNewNodeLocation(value, tmp));
		};

		node_data<value_type>	findNewNodeLocation(value_type &value, rbt *tree) {
			while (tree->right != NULL || tree->left != NULL) {
				if (tree->value.first == value.first) {return (node_data<value_type>(NONE, tree));}
				else if (tree->value < value && tree->right != NULL) {tree = tree->right;}
				else if (tree->value > value && tree->left != NULL)  {tree =tree->left;}
				else
					break;
			}
			if (tree->value < value && tree->right == NULL)
				return (node_data<value_type>(RIGHT, tree));
			if (tree->value > value && tree->left == NULL)
				return (node_data<value_type>(LEFT, tree));
			tree = (tree->value < value) ? tree->right : tree->left;
			findNewNodeLocation(value, tree);
			return (node_data<value_type>(LEFT, tree));
		};

		void	linkNode(node_data<value_type> &node_data, rbt *node) {
			rbt	*tmp;

			if (node_data.direction == RIGHT) {
				node_data.node->right = node;
				tmp = node_data.node->right;
			} else {
				node_data.node->left =  node;
				tmp = node_data.node->left;
			}
			tmp->parent = node_data.node;
		};

		void checkRb(node_data<value_type> node_data) {
			rbt *tmp;

			if (node_data.direction == RIGHT) {
				tmp = node_data.node->right;
				checkUncle(tmp);
			}
			if (node_data.direction == LEFT) {
				tmp = node_data.node->left;
				checkRbViolation(tmp);
				checkUncle(tmp);
			}
			rebalance(tmp);
		};

		void checkUncle(rbt *node) {
			rbt 			*tmp;

			if (!node->parent || !node->parent->parent) {
				return;
			}
			tmp = node->parent->parent;
			if (tmp->right != NULL && tmp->right->color == RED) {
				tmp->right->color = BLACK;
			}
			if (tmp->left != NULL && tmp->left->color == RED) {
				tmp->left->color = BLACK;
			}
			tmp->color = RED;
			if (tmp->value == _tree->value)
				tmp->color = BLACK;
			std::cout << toString().str() << std::endl;
		};

		void checkRbViolation(rbt *node) {
			if (node->color == RED) {
				if (node->parent->color == RED) {
					node->parent->color = BLACK;
				}
			}
		};

		bool rebalanceConditions(rbt *node) {
			bool condition = false;
			condition = node->color == RED && node->parent->color == BLACK &&
				node->parent->parent->color == RED && node->parent->parent->parent->color == RED;
			if (condition == false)
				condition = node->color == RED && node->parent->color == RED &&
					node->parent->parent->color == BLACK && node->parent->parent->parent->color == BLACK;
			return (condition);
		}

		void rebalance(rbt *node) {
			node_direction	dir;

			if (!node->parent || !node->parent->parent || !node->parent->parent->parent)
				return ;
			if (rebalanceConditions(node) == true) {
				if (!node->parent->parent->parent->parent ||
					(node->parent->parent->parent->parent->right->value == node->parent->parent->parent->value))
					dir = RIGHT;
				else
					dir = LEFT;
				std::cout << "totem" << std::endl;
				if (dir == LEFT) {
					leftRotate(node->parent->parent);
					dir = RIGHT;
				}
				if (dir == RIGHT)
					rightRotate(node->parent->parent);
				_begin = getParent(_tree);
			}
		};

		void rightRotate(rbt *node) {
			rbt *tmp;

			if (!node->parent)
				return;
			tmp = node->parent;
			node->color = BLACK;
			tmp->color = RED;
			tmp->left = node->right;
			node->right = tmp;
			node->parent = NULL;
			tmp->parent = node;
		};

		void leftRotate(rbt *node) {
			rbt *tmp;
			rbt *tmp2;

			if (!node->parent || !node->parent->parent)
				return;
			tmp = node->parent;
			tmp2 = tmp->parent->parent;
			tmp->parent->left = tmp->right;
			tmp->right = node->left;
			node->left = tmp;
			node->parent = tmp->parent;
			tmp->parent = node;
		};

		rbt	*getParent(rbt *node) {
			while (node->parent)
				node = node->parent;
			return (node);
		}

		void clearNode(rbt *node) {
			_allocatorNode.destroy(node);
			_allocatorNode.deallocate(node, sizeof(node) * 1);
			_size -= 1;
		}

		public:

		void	insert(value_type *ptr, size_type size) {
			size_type count = 0;

			while (count < size) {
				addNode(*ptr);
				count++;
				ptr++;
			}
		};

		std::stringstream	toString() {
			return (toString(_begin, 0));
		};

		std::string getSpaces(int n) {
			std::string spaces("");
			while (--n >= 0) {
				spaces += "  ";
				spaces += ((n > 0) ? "│" : "└");
			}
			return spaces + "─ ";
		}

		std::string colorizeOutput(std::string ouput, rbt *tree) {
			std::stringstream tmp;

			if (tree->color == RED)
				tmp << std::internal << Format(tree->value.first).red().bold(); 
			if (tree->color == BLACK)
				tmp << std::internal << Format(tree->value.first).black().bold();
			ouput += tmp.str();
			return (ouput);
			
		}

		std::stringstream	toString(rbt *tmp, int depth) {
			std::stringstream 	output;

			if (!tmp)
				return (output);
			output << colorizeOutput(getSpaces(depth) + output.str(), tmp) << std::endl;
			if (tmp->left) output << toString(tmp->left, depth + 1).str();
			if (tmp->right) output << toString(tmp->right,depth + 1).str();
			return (output); 
		};
	};
	

	/* -------------------------- non-member attributs -------------------------- */

	// template <typename _Key, typename _Tp, class _Compare = std::less<_Key>,
	// 		class _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	// std::ostream  & operator<<(std::ostream  &outStream, map< const _Key, _Tp, _Compare, _Alloc> &instance) {
	// 	outStream << instance.toString().str();
	// 	return (outStream);
	// };

}

#endif

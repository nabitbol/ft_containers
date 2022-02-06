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
		typedef	typename ft::mapIterator<red_black_tree<value_type> >			iterator;
		typedef	typename ft::mapIterator<const red_black_tree<value_type> >		const_iterator;
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
		node_color										_nodeColorMemory;
		size_type										_size;
		allocator_type									_allocator;
		typename _Alloc::template rebind<rbt>::other	_allocatorNode;
		key_compare										_comp;

/* ------------------------------ constructors ------------------------------ */

	 public:

	class value_compare : public std::binary_function<value_type, value_type, bool> {

			// friend class map<Key, T, Compare, Alloc>;//remove friend here
		public:
			_Compare		comp;

			value_compare(_Compare __c = key_compare()) : comp(__c) {

			}

			bool operator()(const value_type& __x, const value_type& __y) const {

				return comp(__x.first, __y.first);
			}
	};

		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(NULL), _begin(NULL), _sentinal(NULL), _nodeColorMemory(RED), _size(0), _allocator(alloc), _comp(comp) {};

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());

		map (const map& x) {
			*this = x;
		}

		~map() {
			clear();
		};

/* -------------------------------- operators ------------------------------- */

 		map &operator=(const map &instance) {
			 clear();
			 _tree = instance._tree;
			 _begin = instance.begin;
			 _sentinal = instance.end;
			 _nodeColorMemory = instance._nodeColorMemory;
			 _size = instance._size;
			 _allocator = instance._allocator;
			_comp = instance._comp;
		 };

		mapped_type& operator[] (const key_type& k) {
			return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
		};
/* -------------------------------- iterators ------------------------------- */

		iterator begin() {
			return (iterator(_tree->min(_begin)));
		};

		const_iterator begin() const {
			return (const_iterator(_tree->const_min(_begin)));
		};

		iterator end() {
			return (iterator(_sentinal));
		};

		const_iterator end() const {
			return (const_iterator(_sentinal));
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

		ft::pair<iterator, bool> insert(const value_type& val) {
			if (addNode(val) == false) {
				return (ft::make_pair(find(val.first), false));
			}
			return (ft::make_pair(find(val.first), true));
		}

		iterator insert(iterator position, const value_type& val) {
			(void)position;
			return insert(val).first;
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			while (first != last) {
				insert(*first);
				first++;
			}
		}


		void	erase(iterator position) {
			this->erase(position->_node->first);
		}

		size_type erase(const key_type& k) {

			iterator itKey = find(k);

			if (itKey != end()) {
				rbt *replace = itKey.element;
				
				if (replace->parent) {
					node_direction dir;
					
					if (replace == replace->parent->right)
						dir = RIGHT;
					else
						dir = LEFT;
					eraseNode(node_data<value_type>(dir, replace->parent), replace);
				} else
					eraseNode(replace);
				clearNode(replace);
				return (1);
			}
			return (0);
		}

		void clear() {
			rbt *tmp = _begin;

			clear(tmp);
		};

/* -------------------------------- observes -------------------------------- */

		key_compare key_comp() const {
			return (key_compare());
		}

		value_compare value_comp() const {
			return (value_compare(key_compare()));
		}

/* ------------------------------- operations ------------------------------- */

		iterator	find(const key_type& k) {
			iterator ite = end();

			for (iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(itb->first, k) && !_comp(k, itb->first)) {
					return (itb);
				}
			}
			return (ite);
		};

		const_iterator	find(const key_type& k) const {
			const_iterator ite = end();

			for (const_iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(itb->first, k) && !_comp(k, itb->first)) {
					return (itb);
				}
			}
			return (ite);
		};

		size_type count(const key_type& k) const {
			return (find(k) != end() ? 1 : 0);
		}

		iterator lower_bound (const key_type& k) {
			iterator ite = end();

			for (iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(itb->first, k))
					return (itb);
			}
			return (ite);
		}

		const_iterator lower_bound (const key_type& k) const {
			const_iterator ite = end();

			for (const_iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(itb->first, k))
					return (itb);
			}
			return (ite);
		}

		iterator	upper_bound (const key_type& k) {
			iterator ite = end();

			for (iterator itb = begin(); itb != ite; itb++) {
				if (_comp(k, itb->first)) {
					return (itb);
				}
			}
			return (ite);
		}

		const_iterator	upper_bound (const key_type& k) const {
			const_iterator ite = end();

			for (const_iterator itb = begin(); itb != ite; itb++) {
				if (_comp(k, itb->first)) {
					itb++;
					return (itb);
				}
			}
			return (ite);
		}

		ft::pair<iterator,iterator>	equal_range (const key_type& k) {
			ft::pair<iterator, iterator> ret;

			ret.first = lower_bound(k);
			ret.second = upper_bound(k);
			return (ret);
		}

		ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
			ft::pair<const_iterator, const_iterator> ret;

			ret.first = lower_bound(k);
			ret.second = upper_bound(k);
			return (ret);
		}

	private:

		void clear(rbt *node) {
			if (!node)
				return;
			if (node->left) clear(node->left);
			if (node->right) clear(node->right);
			clearNode(node);
		};

		bool	addNode(value_type value) {
			if (_tree == NULL) {
				_tree = createNode(value);
				_begin = _tree;
				addSentinal();
			} else {
				if (_tree->min(_begin) == _sentinal || _tree->max(_begin) == _sentinal) {
					_tree->max(_begin)->parent->right = NULL;
					clearNode(_sentinal);
					_size += 1;
				}
				node_data<value_type> node_data = findNewNodeLocation(value);
				if (node_data.direction != NONE) {
					linkNode(node_data, createNode(value));
					checkRb(node_data);
					addSentinal();
				}
			}
			return (true);
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

		void addSentinal(void) {
			value_type	tmp;
			rbt *sentinal = createNode(tmp);
			node_data<value_type> node_data(RIGHT, _tree->max(_begin));
			linkNode(node_data, sentinal);
			_sentinal = sentinal;
		}

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
			rbt *tmp;

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
		};

		void eraseNode(node_data<value_type> node_data, rbt *node) {
			if (is2Child(node)) {
				linkNode(node_data, node->right);
				node->right->left = node->left;
				node->right->color = node->color;
			} else if (!isChild(node)) {
				if (node->color == BLACK)
					_nodeColorMemory = BLACK;
			} else {
				if (node->left)
					linkNode(node_data, node->left);
				if (node->right)
					linkNode(node_data, node->right);
			}
		};

		void eraseNode(rbt *node) {
			if (is2Child(node)) {
				node->right->parent = node->parent;
				node->right->left = node->left;
				node->right->color = node->color;
			} else if (!isChild(node)) {
				if (node->color == BLACK)
					_nodeColorMemory = BLACK;
			} else {
				if (node->left)
					node->left->parent = node->parent;
				if (node->right)
					node->right->parent = node->parent;
			}
		};

		bool is2Child(rbt *node) {
			if (node->right != NULL && node->left != NULL) {
					return (true);
			}
			return (false);
		};

		bool isChild(rbt *node) {
			if (node->right != NULL || node->left != NULL) {
					return (true);
			}
			return (false);
		};

		void clearNode(rbt *node) {
			_allocatorNode.destroy(node);
			_allocatorNode.deallocate(node, sizeof(node) * 1);
			_size -= 1;
		};

	public:

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

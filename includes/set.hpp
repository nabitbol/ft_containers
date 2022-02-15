/* -------------------------------------------------------------------------- */
/*                                   set.hpp                                  */
/* -------------------------------------------------------------------------- */

#ifndef SET_HPP
# define SET_HPP

#include "map.hpp"
#include "dependency.hpp"

namespace ft {

	template <typename _Key, class _Compare = std::less<_Key>, class _Alloc = std::allocator<_Key> >
	class set {

	 public:

		typedef  _Key																				key_type;
		typedef  _Key																				mapped_type;
		typedef  _Key																				value_type;
		typedef  _Compare																			key_compare;
		typedef  _Alloc																				allocator_type;
		typedef	typename allocator_type::reference													reference;
		typedef	typename allocator_type::const_reference											const_reference;
		typedef	typename allocator_type::pointer													pointer;
		typedef	typename allocator_type::const_pointer												const_pointer;
		typedef	typename ft::mapIterator<const value_type, const red_black_tree<value_type> >				iterator;
		typedef	typename ft::mapIterator<const value_type, const red_black_tree<value_type> >		const_iterator;
		typedef	typename ft::reverse_iterator<iterator>												reverse_iterator;
		typedef	typename ft::reverse_iterator<const_iterator>										const_reverse_iterator;
		typedef	std::size_t																			size_type;
		typedef	std::ptrdiff_t																		difference_type;


	 private:

		typedef	red_black_tree<value_type>						rbt;

	 public:
		rbt												*_tree;
		rbt												*_begin;
		rbt												*_sentinal;
		int												_nodeColorMemory;
		size_type										_size;
		allocator_type									_allocator;
		typename _Alloc::template rebind<rbt>::other	_allocatorNode;
		key_compare										_comp;

/* ------------------------------ constructors ------------------------------ */

	 public:

		class value_compare : public std::binary_function<value_type, value_type, bool> {

			public:
				_Compare		comp;

				value_compare(_Compare __c = key_compare()) : comp(__c) {

				}

				bool operator()(const value_type& __x, const value_type& __y) const {

					return comp(__x, __y);
				}
		};

		explicit set(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(NULL), _begin(NULL), _sentinal(NULL), _nodeColorMemory(RED), _size(0), _allocator(alloc), _comp(comp) {
				value_type	tmp;
				_sentinal = createNode(tmp);
			};

		template <class InputIterator>
		set (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) : _tree(NULL), _begin(NULL), _sentinal(NULL), _nodeColorMemory(RED), _size(0), _allocator(alloc), _comp(comp) {
			value_type	tmp;
			_sentinal = createNode(tmp);
			insert(first, last);
		};

		set (const set& x) : _tree(NULL), _begin(NULL), _sentinal(NULL), _size(0) {
			*this = x;
		}

		~set() {
			clear();
		};

/* -------------------------------- operators ------------------------------- */

 		set &operator=(const set &instance) {
			 clear();
			 _nodeColorMemory = instance._nodeColorMemory;
			 _allocator = instance._allocator;
			 _allocatorNode = instance._allocatorNode;
			_comp = instance._comp;

			insert(instance.begin(), instance.end());
			return (*this);
		 };

/* -------------------------------- iterators ------------------------------- */

		iterator begin() {
			if (!_begin)
				return (NULL);
			return (iterator(_tree->min(_begin)));
		};

		const_iterator begin() const {
			if (!_begin)
				return (NULL);
			return (const_iterator(_tree->const_min(_begin)));
		};

		iterator end() {
			if (!_sentinal)
				return (NULL);
			return (iterator(_sentinal));
		};

		const_iterator end() const {
			if (!_sentinal)
				return (NULL);
			return (const_iterator(_sentinal));
		};

		reverse_iterator rbegin() {
			return (reverse_iterator(_tree->max(_begin)));
		};

		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_tree->const_max(_begin)));
		};

		reverse_iterator rend() {
			return (reverse_iterator(_tree->min(_begin)));
		};

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(_tree->const_min(_begin)));
		};

/* -------------------------------- capacity -------------------------------- */

		bool empty() const {
			return (_size == 0);
		};

		size_type size() const {
			return (_size);
		};

		size_type max_size() const {
			return (_allocatorNode.max_size());
		};

/* -------------------------------- modifiers ------------------------------- */

		ft::pair<iterator, bool> insert(const value_type& val) {
			if (addNode(val) == false)
				return (ft::make_pair(find(val), false));
			return (ft::make_pair(find(val), true));
		};

		iterator insert(iterator position, const value_type& val) {
			(void)position;
			return insert(val).first;
		};

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			while (first != last) {
				insert(*first);
				first++;
			}
		};

		void erase(iterator position) {
			erase(*position);
		};

		size_type erase(const key_type& k) {

			iterator itKey = find(k);

			if (itKey != end()) {
				rbt *replace = const_cast<rbt *>(itKey.element);
				
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
				_size -= 1;
				return (1);
			}
			return (0);
		};

		void erase(iterator first, iterator last) {
			while (first != last)  {
				first = find(*first);
				erase(*first); 
				first++;
			}
		};

		void swap (set& x) {
			rbt *tmp_begin;
			rbt *tmp_sentinal;
			rbt *tmp_tree;
			size_type tmp_size;

			tmp_begin = x._begin;
			tmp_sentinal = x._sentinal;
			tmp_tree = x._tree;
			tmp_size = x._size;

			x._begin = _begin;
			x._sentinal = _sentinal;
			x._tree = _tree;
			x._size = _size;

			_begin = tmp_begin;
			_sentinal = tmp_sentinal;
			_tree = tmp_tree;
			_size = tmp_size;
		};

		void clear() {
			rbt *tmp = _begin;

			clear(tmp);
			_tree = NULL;
			_begin = NULL;
			_sentinal = NULL;
			_size = 0;
		};

/* -------------------------------- observes -------------------------------- */

		key_compare key_comp() const {
			return (key_compare());
		};

		value_compare value_comp() const {
			return (value_compare(key_compare()));
		};

/* ------------------------------- operations ------------------------------- */

		iterator	find(const key_type& k) {
			iterator ite = end();

			for (iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(*itb, k) && !_comp(k, *itb))
					return (itb);
			}
			return (ite);
		};

		const_iterator	find(const key_type& k) const {
			const_iterator ite = end();

			for (const_iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(*itb, k) && !_comp(k, *itb))
					return (itb);
			}
			return (ite);
		};

		size_type count(const key_type& k) const {
			return (find(k) != end());
		};

		iterator lower_bound (const key_type& k) {
			iterator ite = end();

			for (iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(*itb, k))
					return (itb);
			}
			return (ite);
		};

		const_iterator lower_bound (const key_type& k) const {
			const_iterator ite = end();

			for (const_iterator itb = begin(); itb != ite; itb++) {
				if (!_comp(*itb, k))
					return (itb);
			}
			return (ite);
		};

		iterator	upper_bound (const key_type& k) {
			iterator ite = end();

			for (iterator itb = begin(); itb != ite; itb++) {
				if (_comp(k, *itb)) {
					return (itb);
				}
			}
			return (ite);
		};

		const_iterator	upper_bound (const key_type& k) const {
			const_iterator ite = end();

			for (const_iterator itb = begin(); itb != ite; itb++) {
				if (_comp(k, *itb)) {
					return (itb);
				}
			}
			return (ite);
		};

		ft::pair<iterator,iterator>	equal_range (const key_type& k) {
			ft::pair<iterator, iterator> ret;

			ret.first = lower_bound(k);
			ret.second = upper_bound(k);
			return (ret);
		};

		ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
			ft::pair<const_iterator, const_iterator> ret;

			ret.first = lower_bound(k);
			ret.second = upper_bound(k);
			return (ret);
		};

/* -------------------------------- allocator ------------------------------- */

		allocator_type get_allocator() const {
			return (this->_alloc);
		};

/* --------------------------------- private -------------------------------- */

	private:

		void clear(rbt *node) {
			if (!node)
				return;
			if (node->left) clear(node->left);
			if (node->right) clear(node->right);
			clearNode(node);
			_size  -= 1;
		};

		bool	addNode(value_type value) {
			if (_tree == NULL) {
				_tree = createNode(value);
				_begin = _tree;
				mooveSentinal(_begin);
			} else {
				rbt *parentSentinalNode = _tree->max(_begin)->parent;
				parentSentinalNode->right = NULL;
				node_data<value_type> node_data = findNewNodeLocation(value);
				if (node_data.direction != NONE) {
					linkNode(node_data, createNode(value));
					checkRb(node_data);
					mooveSentinal(parentSentinalNode);
				} else {
					mooveSentinal(parentSentinalNode);
					return (false);
				}
			}
			_size++;
			return (true);
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
				if (tree->value == value) {return (node_data<value_type>(NONE, tree));}
				else if (_comp(tree->value, value) && tree->right != NULL) {tree = tree->right;}
				else if (!_comp(tree->value, value) && tree->left != NULL)  {tree =tree->left;}
				else
					break;
			}
			if (tree->value == value) {return (node_data<value_type>(NONE, tree));}
			if (_comp(tree->value, value) && tree->right == NULL)
				return (node_data<value_type>(RIGHT, tree));
			if (!_comp(tree->value, value) && tree->left == NULL)
				return (node_data<value_type>(LEFT, tree));
			tree = (_comp(tree->value, value)) ? tree->right : tree->left;
			findNewNodeLocation(value, tree);
			return (node_data<value_type>(LEFT, tree));
		};

		void addSentinal(void) {
			value_type	tmp;
			rbt *sentinal = createNode(tmp);
			node_data<value_type> node_data(RIGHT, _tree->max(_begin));
			linkNode(node_data, sentinal);
			_sentinal = sentinal;
		};

		void	mooveSentinal(rbt *node) {
			if (node != NULL && _sentinal != NULL) {
				if (node->right != NULL)
					node = node->right;
				node_data<value_type> node_data(RIGHT, node);
				linkNode(node_data, _sentinal); 
			} else if (_sentinal == NULL && node != NULL)
				addSentinal();
			else
				return;
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
			rbt *tmp;

			if (!node->parent || !node->parent->parent) {
				return;
			}
			tmp = node->parent->parent;
			if (tmp->right != NULL && tmp->right->color == RED && tmp->left != NULL && tmp->left->color == RED) {
				tmp->right->color = BLACK;
			}
			if (tmp->left != NULL && tmp->left->color == RED && tmp->right != NULL && tmp->right->color == RED) {
				tmp->left->color = BLACK;
			}
			tmp->color = RED;
			if (tmp->value == _begin->value)
				tmp->color = BLACK;
		};

		void checkRbViolation(rbt *node) {
			if (node->color == RED) {
				if (node->parent->color == RED)
					node->parent->color = BLACK;
			} if (node->color == BLACK) {
				if (node->parent->color == BLACK)
					node->parent->color = RED;
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
				if (!node->parent->parent->parent->parent || (node->parent->parent->parent->parent && node->parent->parent->parent->parent->right &&
				(node->parent->parent->parent->parent->right->value == node->parent->parent->parent->value)))
					dir = RIGHT;
				else
					dir = LEFT;
				if (dir == LEFT) {
					dir = RIGHT;
				}
				if (dir == RIGHT)
			_begin = getParent(_tree);
			}
		};

		void rightRotate(rbt *node) {
			rbt *tmp;

			if (!node || !node->parent)
				return;
			tmp = node->parent;
			tmp->right = node->left;
			if (node->left != NULL)
				node->left->parent = tmp;
			node->left = tmp;
			if (tmp->parent) {
				if (tmp->parent->right && tmp->parent->right->value == tmp->value)
					tmp->parent->right = node;
				else
					tmp->parent->left = node;
				node->parent = tmp->parent;
			} else
				node->parent = NULL;
			tmp->parent = node;
		};

		void leftRotate(rbt *node) {
			rbt *p;
			rbt *tmp;
			rbt *gp;

			if (!node->parent || !node->parent->parent)
				return;
			p = node->parent;
			tmp = p->parent;
			gp = tmp->parent;
			p->color = BLACK;
			tmp->color = RED;
			tmp->left = p->right;
			p->right = tmp;
			tmp->parent = p;
			if (tmp->right->left)
				tmp->right->left->parent = tmp->right;
			if (gp) {
				if (gp->right && gp->right->value == tmp->value)
					gp->right = p;
				else
					gp->left = p;
				p->parent = gp;
			} else
				p->parent = NULL;
		};

		rbt	*getParent(rbt *node) {
			while (node->parent)
				node = node->parent;
			return (node);
		};

		void eraseNode(node_data<value_type> node_data, rbt *node) {
			if (is2Child(node)) {
				linkNode(node_data, node->right);
				ft::node_data<value_type> node_data2(LEFT, _tree->min(node->right));
				linkNode(node_data2, node->left);
				node->right->color = node->color;
			} else if (!isChild(node)) {
				if (node_data.direction == RIGHT)
					node_data.node->right = NULL;
				else
					node_data.node->left = NULL;
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
				ft::node_data<value_type> node_data(LEFT, _tree->min(node->right));
				linkNode(node_data, node->left);
				node->right->color = node->color;
				_begin = node->right;
			} else if (!isChild(node)) {
				if (node->color == BLACK)
					_nodeColorMemory = BLACK;
			} else {
				if (node->left) {
					node->left->parent = node->parent;
					_begin = node->left;
				}
				if (node->right) {
					node->right->parent = node->parent;
					_begin = node->right;
				}
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
		};

		std::stringstream	toString() {
			return (toString(_begin, 0));
		};

		std::stringstream	toString(rbt *tmp, int depth) {
			std::stringstream 	output;

			if (!tmp)
				return (output);
			output << colorizeOutput(getSpaces(depth) + output.str(), tmp) << std::endl;
			if (tmp->left) output << toString(tmp->left, depth + 1).str();
			if (tmp->right) output << toString(tmp->right,depth + 1).str();
			return (output); 
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
			std::stringstream value_tmp;

			value_tmp << tree->value;
			if (tree->color == RED)
				tmp << std::internal << Format(value_tmp.str()).red().bold(); 
			if (tree->color == BLACK)
				tmp << std::internal << Format(value_tmp.str()).black().bold();
			ouput += tmp.str();
			return (ouput);
			
		};

	};

	/* -------------------------- non-member attributs -------------------------- */

	// template <typename _Key, typename _Tp, class _Compare = std::less<_Key>,
	// 		class _Alloc = std::allocator<ft::pair<_Key, _Tp> > >
	// std::ostream  & operator<<(std::ostream  &outStream, set<_Key, _Tp, _Compare, _Alloc> &instance) {
	// 	outStream << instance.toString().str();
	// 	return (outStream);
	// };

	// template <typename _Key, typename _Tp, class _Compare = std::less<_Key>,
	// 		class _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	// std::ostream  & operator<<(std::ostream  &outStream, set< const _Key, _Tp, _Compare, _Alloc> &instance) {
	// 	outStream << instance.toString().str();
	// 	return (outStream);
	// };

	template< class Key, class Compare, class Alloc >
	bool operator==( const ft::set<Key,Compare,Alloc>& lhs,
				const ft::set<Key,Compare,Alloc>& rhs ) {
		if (lhs.size() == rhs.size()) {
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin())); 
		}
		return (false);
	};

	template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::set<Key,Compare,Alloc>& lhs,
				const ft::set<Key,Compare,Alloc>& rhs ) {
		return (!(lhs == rhs));
	};

	template< class Key, class Compare, class Alloc >
	bool operator<( const ft::set<Key,Compare,Alloc>& lhs,
				const ft::set<Key,Compare,Alloc>& rhs ) {
		if (lhs != rhs)
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		return (false);
	};

	template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::set<Key,Compare,Alloc>& lhs,
				const ft::set<Key,Compare,Alloc>& rhs ) {
		if (lhs == rhs)
			return	(true);
		return (lhs < rhs);
	};

	template< class Key, class Compare, class Alloc >
	bool operator>( const ft::set<Key,Compare,Alloc>& lhs,
			const ft::set<Key,Compare,Alloc>& rhs ) {
		if (lhs != rhs)
			return (!(lhs < rhs));
		return (false);
	};

	template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::set<Key,Compare,Alloc>& lhs,
			const ft::set<Key,Compare,Alloc>& rhs ) {
		if (lhs == rhs)
			return	(true);
		return (!(lhs < rhs));
	};

}

#endif

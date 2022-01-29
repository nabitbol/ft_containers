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

		typedef  _Key											key_type;
		typedef  _Tp											mapped_type;
		typedef  ft::pair<const _Key, _Tp>						value_type;
		typedef  _Compare										key_compare;
		typedef  _Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef	typename allocator_type::const_pointer			const_pointer;
		typedef	std::size_t										size_type;
		typedef	std::ptrdiff_t									difference_type;


	 private:

		typedef	red_black_tree<value_type>						rbt;

		rbt							*_tree;
		size_type					_size;
		allocator_type				_allocator;
		key_compare					_comp;

/* ------------------------------ constructors ------------------------------ */

	 public:

		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()): _tree(NULL), _size(0), _allocator(alloc), _comp(comp) {};

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());

		// map (const map& x);

		~map() {};

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
			return (_allocator.max_size());
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
			} else {
				node_data<value_type> node_data = findNewNodeLocation(value);
				// std::cout << std::endl << "--node data--" << std::endl;
				// std::cout << node_data.direction << std::endl;
				// std::cout << node_data.node->value.first << std::endl;
				linkNode(node_data, createNode(value));
			}
			_size += 1;
		};

		rbt	*createNode(value_type &value) {
			value_type *tmp = allocateMemory(1);
			saveData(tmp, value);
			rbt	*node = new rbt(*tmp);
			return (node);
		};

		node_data<value_type>	findNewNodeLocation(value_type &value) {
			rbt	*tmp = _tree;

			return (findNewNodeLocation(value, tmp));
		};

		
		node_data<value_type>	findNewNodeLocation(value_type &value, rbt *tree) {
			while (tree->right != NULL || tree->left != NULL) {
				if (tree->value < value && tree->right != NULL) {tree = tree->right;}
				else if (tree->value > value && tree->left != NULL)  {tree =tree->left;}
				else
					break;
			}
			if (tree->value < value && tree->right == NULL) {
				return (node_data<value_type>(RIGHT, tree));
			}
			if (tree->value > value && tree->left == NULL) {
				return (node_data<value_type>(LEFT, tree));
			}
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
			return (toString(_tree, 0));
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
				tmp << std::internal << "\033[0;31m" << tree->value.first << "\033[0m" << std::flush; 
			if (tree->color == BLACK)
				tmp << std::internal << "\033[47;30m" << tree->value.first << "\033[0m" << std::flush;
			ouput += tmp.str();
			return (ouput);
			
		}

		std::stringstream	toString(rbt *tmp, int depth) {
			std::stringstream 	output;

			if (!tmp)
				return (output);
			output << colorizeOutput(getSpaces(depth) + output.str(), tmp) << std::endl;
			if (tmp->left) output << toString(tmp->left, depth + 1).str();
			if (tmp->right)  output << toString(tmp->right,depth + 1).str();
			return (output);
		};
	};
	

	/* -------------------------- non-member attributs -------------------------- */

	template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
			typename _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	std::ostream  & operator<<(std::ostream  &outStream, const map<const _Key, _Tp, _Compare, _Alloc> &instance) {
		outStream << instance.toString();
		return (outStream);
	};

}



#endif

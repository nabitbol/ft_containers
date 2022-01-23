/* -------------------------------------------------------------------------- */
/*                                  stack.hpp                                 */
/* -------------------------------------------------------------------------- */

#ifndef	STACK_HPP
# define	STACK_HPP

#include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {

	public:
/* ----------------------------- type definition ---------------------------- */

		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	protected:

		container_type	container;

	public:
/* ------------------------------ constructors ------------------------------ */

		explicit stack (const container_type& ctnr = container_type()): container(ctnr) {};

/* -------------------------------- acessors -------------------------------- */

		bool empty() const {
			return (this->container.empty());
		};

		size_type size() const {
			return (this->container.size());
		};

		reference top() {
			return (this->container.back());
		};

		const_reference top() const {
			return (this->container.back());
		};

		void push (const value_type& val) {
			this->container.push_back(val);
		};

		void pop() {
			this->container.pop_back();
		};

		template <class TOp, class ContainerOp >
		friend bool operator== (const stack<TOp,ContainerOp >& lhs, const stack<TOp,ContainerOp >& rhs); 

		template <class TOp, class ContainerOp >
		friend bool operator!= (const stack<TOp,ContainerOp >& lhs, const stack<TOp,ContainerOp >& rhs);

		template <class TOp, class ContainerOp >
		friend bool operator<  (const stack<TOp,ContainerOp >& lhs, const stack<TOp,ContainerOp >& rhs);

		template <class TOp, class ContainerOp >
		friend bool operator<= (const stack<TOp,ContainerOp >& lhs, const stack<TOp,ContainerOp >& rhs);

		template <class TOp, class ContainerOp >
		friend bool operator>  (const stack<TOp,ContainerOp >& lhs, const stack<TOp,ContainerOp >& rhs);

		template <class TOp, class ContainerOp >
		friend bool operator>=  (const stack<TOp,ContainerOp >& lhs, const stack<TOp,ContainerOp >& rhs);

	};

/* -------------------------- non-member attributs -------------------------- */

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.container == rhs.container);
	};

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.container != rhs.container);
	};

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.container < rhs.container);
	};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.container <= rhs.container);
	};

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return(lhs.container > rhs.container);
	};

	template <class T, class Container>
	bool operator>=  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return(lhs.container >= rhs.container);
	};


}


#endif

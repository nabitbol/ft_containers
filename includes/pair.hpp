/* -------------------------------------------------------------------------- */
/*                                  pair.hpp                                  */
/* -------------------------------------------------------------------------- */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <class T1, class T2> struct pair {

	 public:

	 	T1	first;
		T2	second;

/* ------------------------------ constructors ------------------------------ */

		pair() : first(), second() {};

		template<class U, class V>
		pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {};

		pair (const T1& a, const T2& b): first(a), second(b) {};

		~pair() {};

/* -------------------------------- operators ------------------------------- */

		operator	pair<const T1, const T2>() const {
			return (pair<const T1, const T2>(first, second));
		};

		pair& operator= (const pair& pr) {
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		};

	};

/* -------------------------- non-member attributs -------------------------- */

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

}


#endif

/* -------------------------------------------------------------------------- */
/*                               type_traits.hpp                              */
/* -------------------------------------------------------------------------- */

#ifndef		TYPE_TRAITS_HPP
# define	TYPE_TRAITS_HPP

namespace ft {

/* ---------------------------------- equal --------------------------------- */

	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	};

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, 
			InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

/* ------------------------- lexicographical compare ------------------------ */

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

/* -------------------------------- enable_if ------------------------------- */

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

/* ------------------------------- is_integral ------------------------------ */

	template< typename T >
	struct is_integral {
		static const bool value = false;
	};

	template<>
	struct is_integral<bool> {static const bool value = true;};

	template<>
	struct is_integral<int> {static const bool value = true;};

	template<>
	struct is_integral<char> {static const bool value = true;};

	template<>
	struct is_integral<wchar_t> {static const bool value = true;};

	template<>
	struct is_integral<signed char> {static const bool value = true;};

	template<>
	struct is_integral<short int> {static const bool value = true;};

	template<>
	struct is_integral<long int> {static const bool value = true;};

	template<>
	struct is_integral<long long int> {static const bool value = true;};

	template<>
	struct is_integral<unsigned char> {static const bool value = true;};

	template<>
	struct is_integral<unsigned short int> {static const bool value = true;};

	template<>
	struct is_integral<unsigned int> {static const bool value = true;};

	template<>
	struct is_integral<unsigned long int> {static const bool value = true;};

	template<>
	struct is_integral<unsigned long long int> {static const bool value = true;};

	template<>
	struct is_integral<const bool> {static const bool value = true;};

	template<>
	struct is_integral<const int> {static const bool value = true;};

	template<>
	struct is_integral<const char> {static const bool value = true;}; 

	template<>
	struct is_integral<const wchar_t> {static const bool value = true;};

	template<>
	struct is_integral<const signed char> {static const bool value = true;};

	template<>
	struct is_integral<const short int> {static const bool value = true;};

	template<>
	struct is_integral<const long int> {static const bool value = true;};

	template<>
	struct is_integral<const long long int> {static const bool value = true;};

	template<>
	struct is_integral<const unsigned char> {static const bool value = true;};

	template<>
	struct is_integral<const unsigned short int> {static const bool value = true;};

	template<>
	struct is_integral<const unsigned int> {static const bool value = true;};

	template<>
	struct is_integral<const unsigned long int> {static const bool value = true;};

	template<>
	struct is_integral<const unsigned long long int> {static const bool value = true;};

};

#endif

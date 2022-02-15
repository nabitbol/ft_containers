#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	set::displayObservers() {
	std::cout << "\n" << std::endl;
	displayTitle("[observers]: ");
}

/* --------------------------- key_comp functions --------------------------- */

void	set::testKeyComp() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::key_compare acomp = a.key_comp();
	std::set<int>::key_compare bcomp = b.key_comp();

	int ahighest = *(a.rbegin());     // key value of last element
	int bhighest = *(b.rbegin());     // key value of last element

	std::stringstream	result1;
	std::stringstream	result2;

	ft::set<int>::iterator ita = a.begin();
 	 do {
	result1 << *ita << " => " << *ita << '\n';
	} while ( acomp((*ita++), ahighest) );

	std::set<int>::iterator itb = b.begin();
 	 do {
	result2 << *itb << " => " << *itb << '\n';
	} while ( bcomp((*itb++), bhighest) );

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------- value_compare functions ------------------------ */

void	set::testValueComp() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	int ahighest = *(a.rbegin());     // key value of last element
	int bhighest = *(b.rbegin());     // key value of last element

	std::stringstream	result1;
	std::stringstream	result2;

	ft::set<int>::iterator ita = a.begin();
 	 do {
	result1 << *ita << " => " << *ita << '\n';
	} while ( a.value_comp()(*ita++, ahighest));

	std::set<int>::iterator itb = b.begin();
 	 do {
	result2 << *itb << " => " << *itb << '\n';
	} while ( b.value_comp()(*itb++, bhighest));

	displayCompareResult(result1, result2, NO_MESG);
}

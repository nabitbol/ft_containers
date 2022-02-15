#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* ----------------------------- size functions ----------------------------- */

void	set::testSize() {
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

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSize);
	result2 = exec(b, getSize);

	displayCompareResult(result1, result2, NO_MESG);
}

/* --------------------------- max_size functions --------------------------- */

void	set::testMaxSize() {
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

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMaxSize);
	result2 = exec(b, getMaxSize);

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- empty functions ---------------------------- */

/*
** test1
*/
void	set::testEmpty1() {
	ft::set<char, int> a;
	std::set<char, int> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test2
*/
void	set::testEmpty2() {
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

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, NO_MESG);
}

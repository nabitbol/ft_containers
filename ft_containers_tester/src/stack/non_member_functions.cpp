#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	stack::displayNonMemberFunctions() {
	std::cout << "\n" << std::endl;
	displayTitle("[non-member-functions]: ");
}

/* --------------------- relational operators functions --------------------- */

/*
** test1
*/
void	stack::testRop1() {
	ft::stack<std::string> a;
	ft::stack<std::string> c;
	std::stack<std::string> b;
	std::stack<std::string> d;

	a.push("toto");
	c.push("toto");
	b.push("toto");
	d.push("toto");

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = getCompare(a, c);
	result2 = getCompare(b, d);

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test2
*/
void	stack::testRop2() {
	ft::stack<int> a;
	ft::stack<int> c;
	std::stack<int> b;
	std::stack<int> d;

	a.push(1);
	c.push(2);
	b.push(1);
	d.push(2);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = getCompare(a, c);
	result2 = getCompare(b, d);

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test3
*/
void	stack::testRop3() {
	ft::stack<std::string> a;
	ft::stack<std::string> c;
	std::stack<std::string> b;
	std::stack<std::string> d;

	a.push("zr");
	c.push("toto");
	b.push("zr");
	d.push("toto");

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = getCompare(a, c);
	result2 = getCompare(b, d);

	displayCompareResult(result1, result2, NO_MESG);
}

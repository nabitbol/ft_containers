#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* -------------------------- constructor functions ------------------------- */

void	set::testEmptyParamConstructor() {
	ft::set<char> a;
	std::set<char> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "size: " << a.size() << "max_size: " << a.max_size();
	result2 << "size: " << b.size() << "max_size: " << b.max_size();

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testCopyConstructor() {
	ft::set<char> a;
	std::set<char> b;

	a.insert('b');
	a.insert('w');

	b.insert('b');
	b.insert('w');

	ft::set<char> c(a);
	std::set<char> d(b);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getSetCapacities);
	result2 = exec(d, getSetCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testIteratorConstructor() {
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

	ft::set<int>::iterator itf = a.begin();
	ft::set<int>::iterator itf2 = a.end();
	std::set<int>::iterator its = b.begin();
	std::set<int>::iterator its2 = b.end();

	itf = itf2;
	itf2--;
	its = its2;
	its2--;

	ft::set<int> ft_set(a.begin(), itf);
	std::set<int> std_set(b.begin(), its);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(ft_set, getSetCapacities);
	result2 = exec(std_set, getSetCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

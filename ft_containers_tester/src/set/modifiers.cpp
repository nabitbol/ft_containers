#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* ----------------------------- insert fuctions ---------------------------- */

void	set::testInsert1() {
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
	std::set<int>::iterator its = b.begin();

	itf++;
	its++;

	a.insert(itf, 32);
	b.insert(its, 32);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSetCapacities);
	result2 = exec(b, getSetCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testInsert2() {
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

	result1 = exec(a, getSetCapacities);
	result2 = exec(b, getSetCapacities);

	displayCompareResult(result1, result2, TEST_INSERT2);
}

void	set::testInsert3() {
	ft::set<int> a;
	ft::set<int> c;
	std::set<int> b;
	std::set<int> d;

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

	c.insert(a.begin(), a.end());
	d.insert(b.begin(), b.end());

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getSetCapacities);
	result2 = exec(d, getSetCapacities);

	displayCompareResult(result1, result2, TEST_INSERT4);
}

/* ---------------------------- erase functions ---------------------------- */

void	set::testErase2() {
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

	a.erase(19);
	b.erase(19);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSetCapacities);
	result2 = exec(b, getSetCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- swap functions ----------------------------- */

void	set::testSwap1() {
	ft::set<int> a;
	ft::set<int> c;
	std::set<int> b;
	std::set<int> d;

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

	c.insert(100);

	d.insert(100);

	a.swap(c);
	b.swap(d);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSetCapacities);
	result2 = exec(b, getSetCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testSwap2() {
	ft::set<int> a;
	ft::set<int> c;
	std::set<int> b;
	std::set<int> d;

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

	a.swap(c);
	b.swap(d);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "size: " << a.size() << "max_szie: " <<  a.max_size() << std::endl;
	result2 << "size: " << b.size() << "max_szie: " <<  b.max_size() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- clear functions ---------------------------- */

void	set::testClear1() {
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

	a.clear();
	b.clear();

	result1 << "size: " << a.size() << "max_szie: " <<  a.max_size() << std::endl;
	result2 << "size: " << b.size() << "max_szie: " <<  b.max_size() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testClear2() {
	ft::set<int> a;
	ft::set<int> c;
	std::set<int> b;
	std::set<int> d;

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

	c.insert(100);

	d.insert(100);


	a.swap(c);
	b.swap(d);

	a.clear();
	b.clear();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getSetCapacities);
	result2 = exec(d, getSetCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

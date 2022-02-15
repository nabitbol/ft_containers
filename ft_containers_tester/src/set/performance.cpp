#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	set::FTperf() {
	ft::set<int> a;
	ft::set<int> c;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	c.insert(100);
	c.insert(50);
	c.insert(4);
	c.insert(0);
	c.insert(-2);

	a.swap(c);

	c.erase(40);
	a.erase(-2);

	for (int i = 100; i < 150; i++) {
		a.insert(i);
	}


	std::stringstream	result1;

	result1 = exec(a, getSetCapacities);
}

void	set::STDperf() {
	std::set<int> a;
	std::set<int> c;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	c.insert(100);
	c.insert(50);
	c.insert(4);
	c.insert(0);
	c.insert(-2);

	a.swap(c);

	c.erase(40);
	a.erase(-2);

	for (int i = 100; i < 150; i++) {
		a.insert(i);
	}

	std::stringstream	result1;

	result1 = exec(a, getSetCapacities);
}

void	set::testPerf() {
	testPerformance(set::FTperf, set::STDperf);
}

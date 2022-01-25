#include "ft_containers_tester.hpp"

void	displayNonMembers() {
	std::cout << "\n" << std::endl;
	std::cout << "[Non-members]: ";
}

/* ---------------------- relation operators functions ---------------------- */

void	testComparison1() {
	ft::vector<int> a(7, 100);
	std::vector<int> b(7, 100);

	ft::vector<int> c(7, 100);
	std::vector<int> d(7, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = getCVectorComparison(a, c);
	result2 = getCVectorComparison(b, d);

	displayCompareResult(result1, result2, TEST_ASSIGN1);
}

void	testComparison2() {
	ft::vector<int> a(1, 100);
	std::vector<int> b(1, 100);

	ft::vector<int> c(7, 100);
	std::vector<int> d(7, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = getCVectorComparison(a, c);
	result2 = getCVectorComparison(b, d);

	displayCompareResult(result1, result2, TEST_ASSIGN1);
}

void	testComparison3() {
	ft::vector<int> a(7, 50);
	std::vector<int> b(7, 50);

	ft::vector<int> c(7, 100);
	std::vector<int> d(7, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = getCVectorComparison(a, c);
	result2 = getCVectorComparison(b, d);

	displayCompareResult(result1, result2, TEST_ASSIGN1);
}

/* ----------------------------- swap functions ----------------------------- */

void	testSwap4() {
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	ft::vector<int> c;
	std::vector<int> d;

	c.push_back(400);
	c.push_back(64);

	d.push_back(400);
	d.push_back(64);

	swap(a, c);
	swap(b, d);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	result1 << " return value: " << *itf;
	result2 << " return value: " << *its;

	displayCompareResult(result1, result2, TEST_SWAP4);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	vector::displayConstructor() {
	std::cout << "[Constructor]: ";
}

/* --------------------------- constructor funtions -------------------------- */

void	vector::testEmptyParamConstructor() {
	ft::vector<int> a;
	std::vector<int> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR1);
}

void	vector::testValueConstructor() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << a[1];
	result2 << b[1];

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR2);
}

void	vector::testCopyConstructor() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int> c(a);
	std::vector<int> d(b);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << c[1];
	result2 << d[1];

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR3);
}

void	vector::testIteratorConstructor() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	itf = itf2;
	itf2--;
	its = its2;
	its2--;

	ft::vector<int> ft_vector(a.begin(), itf);
	std::vector<int> std_vector(b.begin(), its);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *itf << ' ' << *itf2;
	result2 << *its << ' ' << *its2;
	iterate(ft_vector, result1, ft_vector.size(), save);
	iterate(std_vector, result2, std_vector.size(), save);

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR4);
}

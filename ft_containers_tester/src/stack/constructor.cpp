#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* --------------------------- constructor funtions -------------------------- */

void	stack::testEmptyParamConstructor() {
	ft::stack<int> a;
	std::stack<int> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << a.size();
	result2 << b.size();

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR1);
}

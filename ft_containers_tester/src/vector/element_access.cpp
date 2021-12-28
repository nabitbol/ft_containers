#include "ft_containers_tester.hpp"

void	displayElementAcess() {
	std::cout << "\n" << std::endl;
	std::cout << "[Element Access]: ";
}

/* ------------------------------ At functions ------------------------------ */

template <typename T>
std::stringstream		getAt(const T &instance) {
	std::stringstream tmp;
	tmp << instance.at(3);
	return (tmp);
}

void	testAt() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getAt);
	result2 = exec(b, getAt);

	displayCompareResult(result1, result2, TEST_AT);
}

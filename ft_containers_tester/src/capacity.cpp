#include "ft_containers_tester.hpp"

void	displayCapacity() {
	std::cout << "[Capacity]: ";
}

/* ----------------------------- size functions ----------------------------- */

template <typename T>
std::stringstream		getSize(const T &instance) {
	std::stringstream tmp;
	tmp << instance.size();
	return (tmp);
}

void	testSize() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSize);
	result2 = exec(b, getSize);

	displayCompareResult(result1, result2, TEST_SIZE);
}

/* --------------------------- max_size functions --------------------------- */


template <typename T>
std::stringstream		getMaxSize(const T &instance) {
	std::stringstream tmp;
	tmp << instance.max_size();
	return (tmp);
}

void	testMaxSize() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMaxSize);
	result2 = exec(b, getMaxSize);

	displayCompareResult(result1, result2, TEST_MAX_SIZE);
}

/* ---------------------------- capcity functions --------------------------- */

template <typename T>
std::stringstream		getCapacity(const T &instance) {
	std::stringstream tmp;
	tmp << instance.capacity();
	return (tmp);
}

void	testCapacity() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getCapacity);
	result2 = exec(b, getCapacity);

	displayCompareResult(result1, result2, TEST_CAPACITY);
}

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

/* ---------------------------- resize functions ---------------------------- */


/* --------------------------------- test 1 --------------------------------- */

template <typename T>
std::stringstream		getResize1(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " capacity: ";
	tmp << instance.capacity();
	tmp << " content: ";
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
}

void	testResize1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(5, 400);
	b.resize(5, 400);

	result1 = exec(a, getResize1);
	result2 = exec(b, getResize1);

	displayCompareResult(result1, result2, TEST_RESIZE1);
}

/* ---------------------------------- test2 --------------------------------- */

template <typename T>
std::stringstream		getResize2(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " capacity: ";
	tmp << instance.capacity();
	tmp << " content: ";
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
}


void	testResize2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(10, 7000);
	b.resize(10, 7000);

	result1 = exec(a, getResize2);
	result2 = exec(b, getResize2);

	displayCompareResult(result1, result2, TEST_RESIZE2);
}

/* --------------------------------- test 3 --------------------------------- */

template <typename T>
std::stringstream		getResize3(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " capacity: ";
	tmp << instance.capacity();
	tmp << " content: ";
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
}

void	testResize3() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(9);
	b.resize(9);

	result1 = exec(a, getResize3);
	result2 = exec(b, getResize3);

	displayCompareResult(result1, result2, TEST_RESIZE3);
}
/* --------------------------------- test 4 --------------------------------- */

template <typename T>
std::stringstream		getResize4(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " capacity: ";
	tmp << instance.capacity();
	tmp << " content: ";
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
}
void	testResize4() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(3);
	b.resize(3);

	result1 = exec(a, getResize4);
	result2 = exec(b, getResize4);

	displayCompareResult(result1, result2, TEST_RESIZE4);
}

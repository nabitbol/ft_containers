#include "ft_containers_tester.hpp"

void	displayCapacity() {
	std::cout << "[Capacity]: ";
}

template <typename T>
std::stringstream		getVectorCapacitiess(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " capacity: ";
	tmp << instance.capacity();
	tmp << " content: ";
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
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

/*
** test1
*/

void	testResize1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(5, 400);
	b.resize(5, 400);

	result1 = exec(a, getVectorCapacitiess);
	result2 = exec(b, getVectorCapacitiess);

	displayCompareResult(result1, result2, TEST_RESIZE1);
}

/*
** test2
*/
void	testResize2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(10, 7000);
	b.resize(10, 7000);

	result1 = exec(a, getVectorCapacitiess);
	result2 = exec(b, getVectorCapacitiess);

	displayCompareResult(result1, result2, TEST_RESIZE2);
}

/*
** test3
*/
void	testResize3() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(9);
	b.resize(9);

	result1 = exec(a, getVectorCapacitiess);
	result2 = exec(b, getVectorCapacitiess);

	displayCompareResult(result1, result2, TEST_RESIZE3);
}

/*
** test4
*/
void	testResize4() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(3);
	b.resize(3);

	result1 = exec(a, getVectorCapacitiess);
	result2 = exec(b, getVectorCapacitiess);

	displayCompareResult(result1, result2, TEST_RESIZE4);
}

/* ----------------------------- empty functions ---------------------------- */

template <typename T>
std::stringstream		getEmpty(const T &instance) {
	std::stringstream tmp;
	tmp << instance.empty();
	return (tmp);
}

/*
** test1
*/
void	testEmpty1() {
	ft::vector<int> a;
	std::vector<int> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, TEST_EMPTY1);
}

/*
** test2
*/
void	testEmpty2() {
	ft::vector<int> a(30, 2);
	std::vector<int> b(30, 2);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, TEST_EMPTY2);
}

/* ---------------------------- reserve functions --------------------------- */

/*
** test1
*/
void	testReserve1() {
	ft::vector<int> a(10, 40);
	std::vector<int> b(10, 40);

	std::stringstream	result1;
	std::stringstream	result2;

	a.reserve(100);
	b.reserve(100);

	result1 = exec(a, getVectorCapacitiess);
	result2 = exec(b, getVectorCapacitiess);

	displayCompareResult(result1, result2, TEST_RESERVE1);
}

/*
** test2
*/
void	testReserve2() {
	ft::vector<int> a(10, 40);
	std::vector<int> b(10, 40);

	std::stringstream	result1;
	std::stringstream	result2;

	a.reserve(8);
	b.reserve(8);

	result1 = exec(a, getVectorCapacitiess);
	result2 = exec(b, getVectorCapacitiess);

	displayCompareResult(result1, result2, TEST_RESERVE2);
}

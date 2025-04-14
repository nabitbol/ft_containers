#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	vector::displayElementAcess() {
	std::cout << "\n" << std::endl;
	displayTitle("[Element Access]: ");
}

template <typename T>
std::stringstream		getVectorContent(T &instance) {
	std::stringstream tmp;
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
}

/* -------------------------- operator [] functions ------------------------- */

void	vector::testOperatorAcess() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorContent);
	result2 = exec(b, getVectorContent);

	displayCompareResult(result1, result2, TEST_OPERATOR_ACESS);
}


/* ------------------------------ At functions ------------------------------ */

/*
** test1
*/
template <typename T>
std::stringstream		getAt(const T &instance) {
	std::stringstream tmp;
	tmp << instance.at(3);
	return (tmp);
}

void	vector::testAt1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getAt);
	result2 = exec(b, getAt);

	displayCompareResult(result1, result2, TEST_AT1);
}

/*
**	test2
*/
void	vector::testAt2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	for (unsigned i=0; i<a.size(); i++)
		a.at(i)=i;

	for (unsigned i=0; i<b.size(); i++)
		b.at(i)=i;

	result1 = exec(a, getVectorContent);
	result2 = exec(b, getVectorContent);

	displayCompareResult(result1, result2, TEST_AT2);
}

/*
** test3
*/
template <typename T>
std::stringstream		getAtOutOfRange(const T &instance) {
	std::stringstream tmp;
	try {
		(void)instance.at(5);
	} catch (std::out_of_range &e) {
		tmp << e.what();
	}
	return (tmp);
}

void	vector::testAt3() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getAtOutOfRange);
	result2 = exec(b, getAtOutOfRange);

	displayCompareResult(result1, result2, TEST_AT3);
}

/* ----------------------------- front functions ---------------------------- */

template <typename T>
std::stringstream		getFront(const T &instance) {
	std::stringstream tmp;
	tmp << instance.front();
	return (tmp);
}

void	vector::testFront() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	for (unsigned i=0; i<a.size(); i++)
		a.at(i)=i;

	for (unsigned i=0; i<b.size(); i++)
		b.at(i)=i;

	result1 = exec(a, getFront);
	result2 = exec(b, getFront);

	displayCompareResult(result1, result2, TEST_FRONT);
}

/* ----------------------------- back functions ----------------------------- */

template <typename T>
std::stringstream		getBack(const T &instance) {
	std::stringstream tmp;
	tmp << instance.back();
	return (tmp);
}

void	vector::testBack() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	for (unsigned i=0; i<a.size(); i++)
		a.at(i)=i;

	for (unsigned i=0; i<b.size(); i++)
		b.at(i)=i;

	result1 = exec(a, getBack);
	result2 = exec(b, getBack);

	displayCompareResult(result1, result2, TEST_BACK);
}


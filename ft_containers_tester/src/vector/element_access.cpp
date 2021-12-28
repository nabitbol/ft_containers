#include "ft_containers_tester.hpp"

void	displayElementAcess() {
	std::cout << "\n" << std::endl;
	std::cout << "[Element Access]: ";
}

template <typename T>
std::stringstream		getVectorContent(T &instance) {
	std::stringstream tmp;
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
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

void	testAt1() {
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
void	testAt2() {
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

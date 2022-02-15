#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	pair::displayMakePair() {
	std::cout << "\n" << std::endl;
	displayTitle("[make_pair]: ");
}

template <typename T>
std::stringstream		getPairContent(T &instance) {
	std::stringstream tmp;
	tmp << "first: " ;
	tmp << instance.first;
	tmp << "second: ";
	tmp << instance.second;
	return (tmp);
}

/* --------------------------- make_pair functions -------------------------- */


void	pair::testMakePair() {
	ft::pair <std::string,double> a;
	ft::pair <std::string,double> c;
	std::pair <std::string,double> b;
	std::pair <std::string,double> d;

	std::stringstream	result1;
	std::stringstream	result2;

	a = ft::make_pair("Earth",6371);
	b = std::make_pair("Earth",6371);

  	c = a;
	d = b;
	

	result1 = exec(c, getPairContent);
	result2 = exec(d, getPairContent);

	displayCompareResult(result1, result2, NO_MESG);
}

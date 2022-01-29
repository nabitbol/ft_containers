#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

template <typename T>
std::stringstream		getPairContent(T &instance) {
	std::stringstream tmp;
	tmp << "first: " ;
	tmp << instance.first;
	tmp << "second: ";
	tmp << instance.second;
	return (tmp);
}

/* --------------------------- constructor funtions -------------------------- */

void	pair::testEmptyParamConstructor() {
	ft::pair <std::string,double> a;
	std::pair <std::string,double> b;

	std::stringstream	result1;
	std::stringstream	result2;


	a.first = "shoes";
	a.second = 39.90;

	b.first = "shoes";
	b.second = 39.90;

	result1 = exec(a, getPairContent);
	result2 = exec(b, getPairContent);

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR1);
}

void	pair::testValueConstructor() {
	ft::pair <std::string,double> a("tomatoes",2.30);
	std::pair <std::string,double> b("tomatoes",2.30);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getPairContent);
	result2 = exec(b, getPairContent);

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR1);
}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void	pair::testCopyConstructor() {

	ft::pair <std::string, double> a("tomatoes", 2.30);
	ft::pair <std::string, double> c(a);

	std::pair <std::string,double> b("tomatoes",2.30);
	std::pair <std::string,double> d(b);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getPairContent);
	result2 = exec(d, getPairContent);

	displayCompareResult(result1, result2, TEST_CONSTRUCTOR1);

}

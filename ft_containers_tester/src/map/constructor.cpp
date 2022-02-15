#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* -------------------------- constructor functions ------------------------- */

void	map::testEmptyParamConstructor() {
	ft::map<char, int> a;
	std::map<char, int> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "size: " << a.size() << "max_size: " << a.max_size();
	result2 << "size: " << b.size() << "max_size: " << b.max_size();

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testCopyConstructor() {
	ft::map<char, int> a;
	std::map<char, int> b;

	a['b'] = 12;
	a['w'] = 43;

	b['b'] = 12;
	b['w'] = 43;

	ft::map<char, int> c(a);
	std::map<char, int> d(b);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getMapCapacities);
	result2 = exec(d, getMapCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testIteratorConstructor() {
	ft::map<std::string, int> a;
	std::map<std::string, int> b;

	a["toto"] = 19;
	a["zr"] = 50;
	a["coco"] = 4;
	a["this"] = 0;
	a["find"] = -2;

	b["toto"] = 19;
	b["zr"] = 50;
	b["coco"] = 4;
	b["this"] = 0;
	b["find"] = -2;

	ft::map<std::string, int>::iterator itf = a.begin();
	ft::map<std::string, int>::iterator itf2 = a.end();
	std::map<std::string, int>::iterator its = b.begin();
	std::map<std::string, int>::iterator its2 = b.end();

	itf = itf2;
	itf2--;
	its = its2;
	its2--;

	ft::map<std::string, int> ft_map(a.begin(), itf);
	std::map<std::string, int> std_map(b.begin(), its);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(ft_map, getMapCapacities);
	result2 = exec(std_map, getMapCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

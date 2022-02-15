#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* ----------------------------- size functions ----------------------------- */

void	map::testSize() {
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

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSize);
	result2 = exec(b, getSize);

	displayCompareResult(result1, result2, NO_MESG);
}

/* --------------------------- max_size functions --------------------------- */

void	map::testMaxSize() {
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

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMaxSize);
	result2 = exec(b, getMaxSize);

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- empty functions ---------------------------- */

/*
** test1
*/
void	map::testEmpty1() {
	ft::map<char, int> a;
	std::map<char, int> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test2
*/
void	map::testEmpty2() {
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

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, NO_MESG);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* ----------------------------- begin functions ---------------------------- */

void	map::testBegin() {
	ft::map<char, int> a;
	std::map<char, int> b;

	a['b'] = 12;
	a['w'] = 43;

	b['b'] = 12;
	b['w'] = 43;

	ft::map<char, int>::iterator itf = a.begin();
	std::map<char, int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << itf->first << ' ' << itf->second << std::endl;
	result2 << its->first << ' ' << its->second << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------------ end functions ----------------------------- */

void	map::testEnd() {
	ft::map<char, int> a;
	std::map<char, int> b;

	a['b'] = 12;
	a['w'] = 43;

	b['b'] = 12;
	b['w'] = 43;
	ft::map<char, int>::iterator itf = a.end();
	std::map<char, int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	itf--;
	its--;

	result1 << itf->first;
	result2 << its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ---------------------------- rbegin functions ---------------------------- */

void	map::testRbegin() {
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

	ft::map<std::string, int>::reverse_iterator rev_itf = a.rbegin();
	std::map<std::string, int>::reverse_iterator rev_its = b.rbegin();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf++;
	rev_its++;

	result1 << rev_itf->first;
	result2 << rev_its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testConstRbegin() {
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

	ft::map<std::string, int>::const_reverse_iterator rev_itf = a.rbegin();
	std::map<std::string, int>::const_reverse_iterator rev_its = b.rbegin();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf++;
	rev_its++;

	result1 << rev_itf->first;
	result2 << rev_its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- rend functions ----------------------------- */

void	map::testRend() {
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

	ft::map<std::string, int>::const_reverse_iterator rev_itf = a.rend();
	std::map<std::string, int>::const_reverse_iterator rev_its = b.rend();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf--;
	rev_its--;

	result1 << rev_itf->first;
	result2 << rev_its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testConstRend() {
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

	ft::map<std::string, int>::const_reverse_iterator rev_itf = a.rend();
	std::map<std::string, int>::const_reverse_iterator rev_its = b.rend();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf--;
	rev_its--;

	result1 << rev_itf->first;
	result2 << rev_its->first;

	displayCompareResult(result1, result2, NO_MESG);
}


/* ------------------------ incrementation functions ------------------------ */

void	map::testPostIncrementation() {
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
	std::map<std::string, int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf++;
	its++;

	result1 << itf->first;
	result2 << its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testPreIncrementation() {
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
	std::map<std::string, int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	++itf;
	++its;

	result1 << itf->first;
	result2 << its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------ decrementations functions ----------------------- */

void	map::testPostDecrementation1() {
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

	ft::map<std::string, int>::iterator itf = a.end();
	std::map<std::string, int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	itf--;
	its--;

	result1 << itf->first;
	result2 << its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testPostDecrementation2() {
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

	ft::map<std::string, int>::iterator itf = a.end();
	std::map<std::string, int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;
 
	--itf;
	--its;

	result1 << itf->first;
	result2 << its->first;

	displayCompareResult(result1, result2, NO_MESG);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* ----------------------------- insert fuctions ---------------------------- */

void	map::testInsert1() {
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

	itf++;
	its++;

	a.insert(itf, ft::make_pair("dor", 32));
	b.insert(its, std::make_pair("dor", 32));

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMapCapacities);
	result2 = exec(b, getMapCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testInsert2() {
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

	a.insert(ft::pair<std::string, int>("kas", 31));
	b.insert(std::pair<std::string, int>("kas", 31));

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMapCapacities);
	result2 = exec(b, getMapCapacities);

	displayCompareResult(result1, result2, TEST_INSERT2);
}


void	map::testInsert3() {
	ft::map<std::string, int> a;
	std::map<std::string, int> b;

	a.insert(ft::pair<std::string, int>("kas", 31));
	a.insert(ft::pair<std::string, int>("so", 1));
	a.insert(ft::pair<std::string, int>("te", 1000));

	b.insert(std::pair<std::string, int>("kas", 31));
	b.insert(std::pair<std::string, int>("so", 1));
	b.insert(std::pair<std::string, int>("te", 1000));


	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMapCapacities);
	result2 = exec(b, getMapCapacities);

	displayCompareResult(result1, result2, TEST_INSERT3);
}

void	map::testInsert4() {
	ft::map<std::string, int> a;
	ft::map<std::string, int> c;
	std::map<std::string, int> b;
	std::map<std::string, int> d;

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

	c.insert(a.begin(), a.end());
	d.insert(b.begin(), b.end());

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getMapCapacities);
	result2 = exec(d, getMapCapacities);

	displayCompareResult(result1, result2, TEST_INSERT4);
}

/* ---------------------------- erase functionsx ---------------------------- */

void	map::testErase1() {
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

	a.erase(a.begin(), a.end());
	b.erase(b.begin(), b.end());

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMapCapacities);
	result2 = exec(b, getMapCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testErase2() {
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

	a.erase("toto");
	b.erase("toto");

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMapCapacities);
	result2 = exec(b, getMapCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- swap functions ----------------------------- */

void	map::testSwap1() {
	ft::map<std::string, int> a;
	ft::map<std::string, int> c;
	std::map<std::string, int> b;
	std::map<std::string, int> d;

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

	c["oi"] = 100;

	d["oi"] = 100;

	a.swap(c);
	b.swap(d);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getMapCapacities);
	result2 = exec(b, getMapCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testSwap2() {
	ft::map<std::string, int> a;
	ft::map<std::string, int> c;
	std::map<std::string, int> b;
	std::map<std::string, int> d;

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

	a.swap(c);
	b.swap(d);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "size: " << a.size() << "max_szie: " <<  a.max_size() << std::endl;
	result2 << "size: " << b.size() << "max_szie: " <<  b.max_size() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- clear functions ---------------------------- */

void	map::testClear1() {
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

	a.clear();
	b.clear();

	result1 << "size: " << a.size() << "max_szie: " <<  a.max_size() << std::endl;
	result2 << "size: " << b.size() << "max_szie: " <<  b.max_size() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

void	map::testClear2() {
	ft::map<std::string, int> a;
	ft::map<std::string, int> c;
	std::map<std::string, int> b;
	std::map<std::string, int> d;

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

	c["oi"] = 100;

	d["oi"] = 100;

	a.swap(c);
	b.swap(d);

	a.clear();
	b.clear();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getMapCapacities);
	result2 = exec(d, getMapCapacities);

	displayCompareResult(result1, result2, NO_MESG);
}

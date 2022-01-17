#include "ft_containers_tester.hpp"

void	displayModifiers() {
	std::cout << "\n" << std::endl;
	std::cout << "[Modifiers]: ";
}

/* ---------------------------- assign functions ---------------------------- */

void	testAssign1() {
	ft::vector<int> a;
	std::vector<int> b;

	a.assign(7,100);
	b.assign(7,100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN1);
}

void	testAssign2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.assign(3,200);
	b.assign(3,200);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN2);
}

void	testAssign3() {
	ft::vector<int> a;
	ft::vector<int> c;
	std::vector<int> b;
	std::vector<int> d;

	a.assign (7,100);
	b.assign (7,100);

	ft::vector<int>::iterator itf;
	itf= a.begin() + 1;

	c.assign (itf, a.end() - 1);

	std::vector<int>::iterator its;
	its= b.begin() + 1;

	d.assign (its, b.end() - 1);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(c, getVectorCapacities);
	result2 = exec(d, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN3);
}

void	testAssign4() {
	ft::vector<int> a;
	std::vector<int> b;

	int myints[] = {1776,7,4};
	a.assign(40, myints[1]);
	b.assign(40, myints[1]);

	std::stringstream	result1;
	std::stringstream	result2;

	a.resize(20, 20);
	b.resize(20, 20);

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN4);
}

/* --------------------------- push_back functions -------------------------- */

void	testPushBack() {
	ft::vector<int> a;
	std::vector<int> b;

	a.push_back(20);
	a.push_back(30);

	b.push_back(20);
	b.push_back(30);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN4);
}

/* --------------------------- pop_back functions --------------------------- */

void	testPopBack1() {
	ft::vector<int> a;
	std::vector<int> b;

	a.push_back(20);
	a.push_back(30);

	b.push_back(20);
	b.push_back(30);

	while (!a.empty()) {
		a.pop_back();
	}

	while (!b.empty()) {
		b.pop_back();
	}

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN4);
}

void	testPopBack2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.pop_back();
	b.pop_back();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN4);
}

/* ----------------------------- insert fuctions ---------------------------- */

void	testInsert1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.begin() + 1;
	std::vector<int>::iterator its = b.begin() + 1;

	a.insert(itf, 47);
	b.insert(its, 47);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN4);
}

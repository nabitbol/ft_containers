#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	vector::displayModifiers() {
	std::cout << "\n" << std::endl;
	displayTitle("[Modifiers]: ");
}

/* ---------------------------- assign functions ---------------------------- */

void	vector::testAssign1() {
	ft::vector<int> a;
	std::vector<int> b;

	a.assign(7,100);
	b.assign(7,100);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_COMPARISON1);
}

void	vector::testAssign2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.assign(3,200);
	b.assign(3,200);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_COMPARISON2);
}

void	vector::testAssign3() {
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

	displayCompareResult(result1, result2, TEST_COMPARISON3);
}

void	vector::testAssign4() {
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

void	vector::testPushBack1() {
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

	displayCompareResult(result1, result2, TEST_PUSH_BACK1);
}

/* --------------------------- pop_back functions --------------------------- */

void	vector::testPopBack1() {
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

	displayCompareResult(result1, result2, TEST_POP_BACK1);
}

void	vector::testPopBack2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.pop_back();
	b.pop_back();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_POP_BACK2);
}

/* ----------------------------- insert fuctions ---------------------------- */

void	vector::testInsert1() {
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

	displayCompareResult(result1, result2, TEST_INSERT1);
}

void	vector::testInsert2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.end();
	std::vector<int>::iterator its = b.end();

	a.insert(itf, 22);
	b.insert(its, 22);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_INSERT2);
}


void	vector::testInsert3() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.begin() + 1;
	std::vector<int>::iterator its = b.begin() + 1;

	a.insert(itf, 2, 30);
	b.insert(its, 2, 30);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_INSERT3);
}

void	vector::testInsert4() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.reserve(8);
	b.reserve(8);

	ft::vector<int>::iterator itf = a.begin() + 1;
	std::vector<int>::iterator its = b.begin() + 1;

	a.insert(itf, 2, 30);
	b.insert(its, 2, 30);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_INSERT4);
}

void	vector::testInsert5() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.reserve(8);
	b.reserve(8);

	ft::vector<int>::iterator itf = a.begin() + 2;
	std::vector<int>::iterator its = b.begin() + 2;

	a.insert(itf, a.begin(), a.end());
	b.insert(its, b.begin(), b.end());

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ASSIGN4);
}

/* ---------------------------- erase functionsx ---------------------------- */

void	vector::testErase1() {
	ft::vector<int> a(4);
	std::vector<int> b(4);

	a.push_back(100);
	a.push_back(28);
	a.push_back(30);
	a.push_back(49);

	b.push_back(100);
	b.push_back(28);
	b.push_back(30);
	b.push_back(49);

	ft::vector<int>::iterator itf = a.begin() + 2;
	std::vector<int>::iterator its = b.begin() + 2;

	a.erase(itf);
	b.erase(its);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_ERASE1);
}

void	vector::testErase2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.push_back(400);
	b.push_back(400);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	ft::vector<int>::iterator itf2 = a.erase(itf);
	std::vector<int>::iterator its2 = b.erase(its);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	result1 << " return value: " << *itf2;
	result2 << " return value: " << *its2;

	displayCompareResult(result1, result2, TEST_ERASE2);
}

void	vector::testErase3() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.push_back(400);
	a.push_back(64);
	a.push_back(40);
	a.push_back(29);

	b.push_back(400);
	b.push_back(64);
	b.push_back(40);
	b.push_back(29);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	ft::vector<int>::iterator itf2 = a.erase(itf, (itf + 4));
	std::vector<int>::iterator its2 = b.erase(its, (its + 4));

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	result1 << " return value: " << *itf2;
	result2 << " return value: " << *its2;

	displayCompareResult(result1, result2, TEST_ERASE3);
}

/* ----------------------------- swap functions ----------------------------- */

void	vector::testSwap1() {
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	ft::vector<int> c;
	std::vector<int> d;

	c.push_back(400);
	c.push_back(64);
	c.push_back(40);
	c.push_back(29);

	d.push_back(400);
	d.push_back(64);
	d.push_back(40);
	d.push_back(29);


	a.swap(c);
	b.swap(d);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_SWAP1);
}

void	vector::testSwap2() {
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	ft::vector<int> c;
	std::vector<int> d;

	a.swap(c);
	b.swap(d);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_SWAP2);
}

void	vector::testSwap3() {
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	ft::vector<int> c;
	std::vector<int> d;

	c.push_back(400);
	c.push_back(64);

	d.push_back(400);
	d.push_back(64);

	a.swap(c);
	b.swap(d);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	result1 << " return value: " << *itf;
	result2 << " return value: " << *its;

	displayCompareResult(result1, result2, TEST_SWAP3);
}

/* ----------------------------- clear functions ---------------------------- */

void	vector::testClear1() {
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	std::stringstream	result1;
	std::stringstream	result2;

	a.clear();
	b.clear();

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_CLEAR1);
}

void	vector::testClear2() {
	ft::vector<int> a(3, 100);
	std::vector<int> b(3, 100);

	ft::vector<int> c;
	std::vector<int> d;

	c.push_back(400);
	c.push_back(64);

	d.push_back(400);
	d.push_back(64);

	a.swap(c);
	b.swap(d);

	a.clear();
	b.clear();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getVectorCapacities);
	result2 = exec(b, getVectorCapacities);

	displayCompareResult(result1, result2, TEST_CLEAR2);
}

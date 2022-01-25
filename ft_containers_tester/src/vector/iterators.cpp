#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	displayIterators() {
	std::cout << "\n" << std::endl;
	std::cout << "[Iterators]: ";
}

/* ----------------------------- begin functions ---------------------------- */

void	testBegin() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_BEGIN);
}

/* ------------------------------ end functions ----------------------------- */

void	testEnd() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.end();
	std::vector<int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_END);
}

/* ---------------------------- rbegin functions ---------------------------- */

void	testRbegin() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(6, 700);
	b.resize(6, 700);

	ft::vector<int>::reverse_iterator rev_itf = a.rbegin();
	std::vector<int>::reverse_iterator rev_its = b.rbegin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, TEST_RBEGIN);
}

void	testConstRbegin() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(6, 700);
	b.resize(6, 700);

	ft::vector<int>::const_reverse_iterator rev_itf = a.rbegin();
	std::vector<int>::const_reverse_iterator rev_its = b.rbegin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, TEST_CONST_RBEGIN);
}

/* ----------------------------- rend functions ----------------------------- */

void	testRend() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(6, 700);
	b.resize(6, 700);

	ft::vector<int>::const_reverse_iterator rev_itf = a.rend();
	std::vector<int>::const_reverse_iterator rev_its = b.rend();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, TEST_REND);
}

void	testConstRend() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(6, 700);
	b.resize(6, 700);

	ft::vector<int>::const_reverse_iterator rev_itf = a.rend();
	std::vector<int>::const_reverse_iterator rev_its = b.rend();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, TEST_CONST_REND);
}

/* --------------------------- addtions functions --------------------------- */

void	testAddition1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.begin();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf = itf2 + 5;
	its = its2 + 5;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_ITERATOR_ADDIION1);
}

void	testAddition2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.begin();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf = 5 + itf2;
	its = 5 + its2;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_ITERATOR_ADDIION2);
}

void	testAddition3() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf += 5;
	its += 5;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_ITERATOR_ADDIION3);
}

/* ------------------------- substraction functions ------------------------- */

void	testSubstarction1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.begin();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf = itf2 - 1;
	its = its2 - 1;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_ITERATOR_SUBSTRATCION1);
}

void	testSubstarction2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf -= 1;
	its -= 1;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_ITERATOR_SUBSTRATCION2);
}

/* ------------------------ incrementation functions ------------------------ */

void	testPostIncrementation() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf++;
	its++;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_INCREMENTATION1);
}

void	testPreIncrementation() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	++itf;
	++its;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_INCREMENTATION2);
}

/* ------------------------ decrementations functions ----------------------- */

void	testPostDecrementation1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.end();
	std::vector<int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	itf--;
	its--;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_DECREMENTATION1);
}

void	testPostDecrementation2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	ft::vector<int>::iterator itf = a.end();
	std::vector<int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;
 
	--itf;
	--its;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, TEST_DECREMENTATION2);
}

/* -------------------------- comparison functions -------------------------- */

void	testComparaison1() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf < itf2);
	result2 << (its < its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON1);
}

void	testComparaison2() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf <= itf2);
	result2 << (its <= its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON2);
}

void	testComparaison3() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.begin();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf <= itf2);
	result2 << (its <= its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON3);
}

void	testComparaison4() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf > itf2);
	result2 << (its > its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON4);
}

void	testComparaison5() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf >= itf2);
	result2 << (its >= its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON5);
}

void	testComparaison6() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.begin();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf >= itf2);
	result2 << (its >= its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON6);
}

void	testComparaison7() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.begin();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf == itf2);
	result2 << (its == its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON7);
}

void	testComparaison8() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf == itf2);
	result2 << (its == its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON8);
}

void	testComparaison9() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.begin();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf != itf2);
	result2 << (its != its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON9);
}

void	testComparaison10() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << (itf != itf2);
	result2 << (its != its2);

	displayCompareResult(result1, result2, TEST_ITERATOR_COMPARISON10);
}

/* ------------------------- dereference functions -------------------------- */

void	testDerefence() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	std::vector<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << itf[5];
	result2 << its[5];

	displayCompareResult(result1, result2, TEST_ITERATOR_DEREFERENCE);
}

/* -------------------------- multi pass functions -------------------------- */

void	testMultiPass() {
	ft::vector<int> a(4, 100);
	std::vector<int> b(4, 100);

	a.resize(5, 90);
	b.resize(5, 90);

	ft::vector<int>::iterator itf = a.begin();
	ft::vector<int>::iterator itf2 = a.end();
	std::vector<int>::iterator its = b.begin();
	std::vector<int>::iterator its2 = b.end();

	itf = itf2;
	itf2--;
	its = its2;
	its2--;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *itf << ' ' << *itf2;
	result2 << *its << ' ' << *its2;

	displayCompareResult(result1, result2, TEST_ITERATOR_MULTI_PASS);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

/* ----------------------------- begin functions ---------------------------- */

void	set::testBegin() {
	ft::set<char> a;
	std::set<char> b;

	a.insert('b');
	a.insert('w');

	b.insert('b');
	b.insert('w');


	ft::set<char>::iterator itf = a.begin();
	std::set<char>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << *itf << ' ' << *itf << std::endl;
	result2 << *its << ' ' << *its << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------------ end functions ----------------------------- */

void	set::testEnd() {
	ft::set<char> a;
	std::set<char> b;

	a.insert('b');
	a.insert('w');

	b.insert('b');
	b.insert('w');

	ft::set<char>::iterator itf = a.end();
	std::set<char>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	itf--;
	its--;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ---------------------------- rbegin functions ---------------------------- */

void	set::testRbegin() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::reverse_iterator rev_itf = a.rbegin();
	std::set<int>::reverse_iterator rev_its = b.rbegin();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf++;
	rev_its++;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testConstRbegin() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::const_reverse_iterator rev_itf = a.rbegin();
	std::set<int>::const_reverse_iterator rev_its = b.rbegin();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf++;
	rev_its++;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- rend functions ----------------------------- */

void	set::testRend() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::const_reverse_iterator rev_itf = a.rend();
	std::set<int>::const_reverse_iterator rev_its = b.rend();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf--;
	rev_its--;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testConstRend() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::const_reverse_iterator rev_itf = a.rend();
	std::set<int>::const_reverse_iterator rev_its = b.rend();

	std::stringstream	result1;
	std::stringstream	result2;

	rev_itf--;
	rev_its--;

	result1 << *rev_itf;
	result2 << *rev_its;

	displayCompareResult(result1, result2, NO_MESG);
}


/* ------------------------ incrementation functions ------------------------ */

void	set::testPostIncrementation() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::iterator itf = a.begin();
	std::set<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	itf++;
	its++;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testPreIncrementation() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::iterator itf = a.begin();
	std::set<int>::iterator its = b.begin();

	std::stringstream	result1;
	std::stringstream	result2;

	++itf;
	++its;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------ decrementations functions ----------------------- */

void	set::testPostDecrementation1() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::iterator itf = a.end();
	std::set<int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;

	itf--;
	its--;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, NO_MESG);
}

void	set::testPostDecrementation2() {
	ft::set<int> a;
	std::set<int> b;

	a.insert(19);
	a.insert(50);
	a.insert(4);
	a.insert(0);
	a.insert(-2);

	b.insert(19);
	b.insert(50);
	b.insert(4);
	b.insert(0);
	b.insert(-2);

	ft::set<int>::iterator itf = a.end();
	std::set<int>::iterator its = b.end();

	std::stringstream	result1;
	std::stringstream	result2;
 
	--itf;
	--its;

	result1 << *itf;
	result2 << *its;

	displayCompareResult(result1, result2, NO_MESG);
}

#ifndef		FT_CONTAINERS_HPP
# define	FT_CONTAINERS_HPP

/* -------------------------------------------------------------------------- */
/*                                your includes                               */
/* -------------------------------------------------------------------------- */

# include "../../includes/vector.hpp"

/* -------------------------------------------------------------------------- */
/*                               tester includes                              */
/* -------------------------------------------------------------------------- */

# include "./error_test_defines.hpp"
# include <vector>
# include <iostream>
# include <sstream>
# include <fstream>

/* --------------------------------- typedef -------------------------------- */

typedef	void	(*functionPtr)(void);

/* -------------------------------------------------------------------------- */
/*                               class regsiter                               */
/* -------------------------------------------------------------------------- */

class Register {

 private:
	std::vector<functionPtr> _testFunctions;
	std::vector<std::string> _testErrorMsg;

 public:
	Register();
	~Register();
	void	pushTestFunction(const std::string &str, const functionPtr &function);
	void	runAllTests();

};

/* ---------------------------------- utils --------------------------------- */


template <typename T>
std::stringstream		exec(const T &instance, std::stringstream function(const T &)) {
	return (function(instance));
}

void	displayCompareResult(const std::stringstream &result1, const std::stringstream &result2, const std::string &test);

template < typename T>
void	save(const T &instance, std::stringstream &tmp, int index) {
	tmp << instance[index];
	tmp << " ";
}

template < typename T>
void	iterate(const T &instance, std::stringstream &tmp, size_t size, void function(const T &, std::stringstream &, int)) {
	for (size_t i = 0; i < size; i++) {
		function(instance, tmp, i);
	}
}

/* -------------------------------------------------------------------------- */
/*                                   vector                                   */
/* -------------------------------------------------------------------------- */

void	addVectorFunctions(Register *list);

/* ---------------------------------- utils --------------------------------- */

template <typename T>
std::stringstream		getVectorCapacities(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " capacity: ";
	tmp << instance.capacity();
	tmp << " content: ";
	iterate(instance, tmp, instance.size(), save);
	return (tmp);
}

/* ---------------------------- constrcutor tests --------------------------- */

void	displayConstructor();

void	testEmptyParamConstructor();
void	testValueConstructor();
void	testCopyConstructor();
void	testIteratorConstructor();

/* ----------------------------- iterators tests ---------------------------- */

void	displayIterators();

void	testBegin();
void	testEnd();
void	testRbegin();
void	testConstRbegin();
void	testRend();
void	testConstRend();
void	testAddition1();
void	testAddition2();
void	testAddition3();
void	testSubstarction1();
void	testSubstarction2();
void	testPostIncrementation();
void	testPreIncrementation();
void	testPostDecrementation1();
void	testPostDecrementation2();
void	testComparaison1();
void	testComparaison2();
void	testComparaison3();
void	testComparaison4();
void	testComparaison5();
void	testComparaison6();
void	testComparaison7();
void	testComparaison8();
void	testComparaison9();
void	testComparaison10();
void	testDerefence();
void	testMultiPass();


/* ----------------------------- capacity tests ----------------------------- */

void	displayCapacity();

void	testSize();
void	testMaxSize();
void	testCapacity();
void	testResize1();
void	testResize2();
void	testResize3();
void	testResize4();
void	testEmpty1();
void	testEmpty2();
void	testReserve1();
void	testReserve2();

/* --------------------------- Element acess tests -------------------------- */

void	displayElementAcess();

void	testAt1();
void	testAt2();
void	testAt3();
void	testFront();
void	testBack();
void	testOperatorAcess();

/* ----------------------------- Modifiers tests ---------------------------- */

void	displayModifiers();

void	testAssign1();
void	testAssign2();
void	testAssign3();
void	testAssign4();

#endif

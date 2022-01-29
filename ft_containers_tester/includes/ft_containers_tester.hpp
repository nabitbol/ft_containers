#ifndef		FT_CONTAINERS_HPP
# define	FT_CONTAINERS_HPP

#define	NO_MESG	""

#define	SETW	20

/* -------------------------------------------------------------------------- */
/*                                your includes                               */
/* -------------------------------------------------------------------------- */

# include "../../includes/vector.hpp"
# include "../../includes/stack.hpp"
# include "../../includes/pair.hpp"
# include "../../includes/map.hpp"

/* -------------------------------------------------------------------------- */
/*                               tester includes                              */
/* -------------------------------------------------------------------------- */

# include <cstring>
# include <map>
# include <vector>
# include <stack>
# include <iostream>
# include <sstream>
# include <fstream>
# include <iomanip>

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

void	jumpNextLine();
void	displayTitle(std::string title);

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

template <typename T>
std::stringstream		getCVectorComparison(T &instance, T &instance2) {
	std::stringstream tmp;
	tmp << " ==: ";
	tmp << (instance == instance2);
	tmp << " !=: ";
	tmp << (instance != instance2);
	tmp << " >: ";
	tmp << (instance > instance2);
	tmp << " >=: ";
	tmp << (instance >= instance2);
	tmp << " <: ";
	tmp << (instance < instance2);
	tmp << " <=: ";
	tmp << (instance <= instance2);
	return (tmp);
}

	/* ---------------------------- Constrcutor tests --------------------------- */
namespace vector {

	void	addConstructor(Register *list);

	void	displayConstructor();

	void	testEmptyParamConstructor();
	void	testValueConstructor();
	void	testCopyConstructor();
	void	testIteratorConstructor();

	/* ----------------------------- Iterators tests ---------------------------- */

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


	/* ----------------------------- Capacity tests ----------------------------- */

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
	void	testPushBack1();
	void	testPopBack1();
	void	testPopBack2();
	void	testInsert1();
	void	testInsert2();
	void	testInsert3();
	void	testInsert4();
	void	testInsert5();
	void	testErase1();
	void	testErase2();
	void	testErase3();
	void	testSwap1();
	void	testSwap2();
	void	testSwap3();
	void	testClear1();
	void	testClear2();

	/* ---------------------------- Non members tests --------------------------- */

	void	displayNonMembers();

	void	testComparison1();
	void	testComparison2();
	void	testComparison3();
	void	testSwap4();

}

/* -------------------------------------------------------------------------- */
/*                                    Stack                                   */
/* -------------------------------------------------------------------------- */


	void	addStackFunctions(Register *list);

namespace stack {

	/* --------------------------- Constructors tests --------------------------- */

	void	addConstructor(Register *list);

	void	testEmptyParamConstructor();

}

/* -------------------------------------------------------------------------- */
/*                                    Pair                                    */
/* -------------------------------------------------------------------------- */

	void	addPairFunctions(Register *list);

namespace	pair {

	/* --------------------------- Constructors tests --------------------------- */

	void	addConstructor(Register *list);

	void	testEmptyParamConstructor();
	void	testValueConstructor();
	void	testCopyConstructor();

}

#endif

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
# include "../../includes/set.hpp"

/* -------------------------------------------------------------------------- */
/*                               tester includes                              */
/* -------------------------------------------------------------------------- */

# include <cstring>
# include <map>
# include <set>
# include <vector>
# include <stack>
#include <chrono>
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
void	saveMap(const T &instance, std::stringstream &tmp) {
	tmp << instance->first;
	tmp << " ";
	tmp << instance->second;
}


template < typename T>
void	saveSet(const T &instance, std::stringstream &tmp) {
	tmp << *instance;
	tmp << " ";
}

template < typename T>
void	iterate(const T &instance, std::stringstream &tmp, size_t size, void function(const T &, std::stringstream &, int)) {
	for (size_t i = 0; i < size; i++) {
		function(instance, tmp, i);
	}
}

template < typename T>
void	iterateMap(const T &instance, std::stringstream &tmp, void function(const typename T::const_iterator &, std::stringstream &)) {
	typename T::const_iterator ite = instance.end();
	for (typename T::const_iterator itb = instance.begin(); itb != ite; itb++) {
		function(itb, tmp);
	}
}

template <typename T>
std::stringstream		getSize(const T &instance) {
	std::stringstream tmp;
	tmp << instance.size();
	return (tmp);
}

template <typename T>
std::stringstream		getEmpty(const T &instance) {
	std::stringstream tmp;
	tmp << instance.empty();
	return (tmp);
}

template <typename T>
std::stringstream		getMaxSize(const T &instance) {
	std::stringstream tmp;
	tmp << instance.max_size();
	return (tmp);
}

template <typename T>
std::stringstream		getCompare(const T &instance, const T instance2) {
	std::stringstream tmp;
	tmp << "equality: ";
	tmp << (instance == instance2);
	tmp << "non-equal: ";
	tmp << (instance != instance2);
	tmp << "superior or equal: ";
	tmp << (instance >= instance2);
	tmp << "inferior or equal: ";
	tmp << (instance <= instance2);
	tmp << "superior: ";
	tmp << (instance > instance2);
	tmp << "inferior: ";
	tmp << (instance < instance2);
	return (tmp);
}


void	jumpNextLine();
void	displayTitle(std::string title);
void	testPerformance(void function(void), void function2(void));

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

	/* ------------------------------- performance ------------------------------ */

	void	FTperf();
	void	STDperf();
	void	testPerf();

}

/* -------------------------------------------------------------------------- */
/*                                    Stack                                   */
/* -------------------------------------------------------------------------- */


	void	addStackFunctions(Register *list);

namespace stack {

	/* --------------------------- Constructors tests --------------------------- */

	void	addConstructor(Register *list);

	void	testEmptyParamConstructor();
	void	testCopyConstructor();

	/* ------------------------------ Member tests ------------------------------ */

	void	addMemberFunctions(Register *list);

	void	displayMemberFunctions();

	void	testEmpty1();
	void	testEmpty2();
	void	testEmpty3();
	void	testSize1();
	void	testSize2();
	void	testTop();
	void	testPush1();
	void	testPush2();
	void	testPop1();
	void	testPop2();

	/* ---------------------------- Non member tests ---------------------------- */

	void	addNonMemberFunctions(Register *list);

	void	displayNonMemberFunctions();

	void	testRop1();
	void	testRop2();
	void	testRop3();

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

	/* ----------------------------- make_pair tests ---------------------------- */

	void	addMakePair(Register *list);

	void	displayMakePair();

	void	testMakePair();

}

/* -------------------------------------------------------------------------- */
/*                                     Map                                    */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- utils --------------------------------- */

template <typename T>
std::stringstream		getMapCapacities(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " max_size: ";
	tmp << instance.max_size();
	tmp << " content: ";
	iterateMap(instance, tmp, saveMap);
	return (tmp);
}

	void	addMapFunctions(Register *list);

namespace	map {

	/* --------------------------- Constructors tests --------------------------- */

	void	addConstructor(Register *list);

	void	testEmptyParamConstructor();
	void	testCopyConstructor();
	void	testIteratorConstructor();

	/* ----------------------------- Capacity tests ----------------------------- */

	void	addCapacity(Register *list);

	void	testSize();
	void	testMaxSize();
	void	testEmpty1();
	void	testEmpty2();

	/* ----------------------------- modifiers tests ---------------------------- */

	void	addModifiers(Register *list);

	void	testInsert1();
	void	testInsert2();
	void	testInsert3();
	void	testInsert4();
	void	testErase1();
	void	testErase2();
	void	testSwap1();
	void	testSwap2();
	void	testClear1();
	void	testClear2();

	/* ---------------------------- Iterators tests ----------------------------- */

	void	addIterators(Register *list);

	void	testBegin();
	void	testEnd();
	void	testRbegin();
	void	testConstRbegin();
	void	testRend();
	void	testConstRend();
	void	testPostIncrementation();
	void	testPreIncrementation();
	void	testPostDecrementation1();
	void	testPostDecrementation2();

	/* ----------------------------- observers tests ---------------------------- */

	void	addObservers(Register *list);

	void	displayObservers();

	void	testKeyComp();
	void	testValueComp();

	/* ---------------------------- operations tests ---------------------------- */

	void	addOperations(Register *list);

	void	displayOperations();

	void	testFind();
	void	testCount();
	void	testLowerUpperBound();
	void	testEqualRange();

	/* ------------------------------- performance ------------------------------ */

	void	FTperf();
	void	STDperf();
	void	testPerf();

}

/* -------------------------------------------------------------------------- */
/*                                     Set                                    */
/* -------------------------------------------------------------------------- */

/* ---------------------------------- utils --------------------------------- */

template <typename T>
std::stringstream		getSetCapacities(T &instance) {
	std::stringstream tmp;
	tmp << " size: ";
	tmp << instance.size();
	tmp << " max_size: ";
	tmp << instance.max_size();
	tmp << " content: ";
	iterateMap(instance, tmp, saveSet);
	return (tmp);
}

	void	addSetFunctions(Register *list);

namespace	set {

	/* --------------------------- Constructors tests --------------------------- */

	void	addConstructor(Register *list);

	void	testEmptyParamConstructor();
	void	testCopyConstructor();
	void	testIteratorConstructor();

	/* ----------------------------- Capacity tests ----------------------------- */

	void	addCapacity(Register *list);

	void	testSize();
	void	testMaxSize();
	void	testEmpty1();
	void	testEmpty2();

	/* ----------------------------- modifiers tests ---------------------------- */

	void	addModifiers(Register *list);

	void	testInsert1();
	void	testInsert2();
	void	testInsert3();
	void	testErase2();
	void	testSwap1();
	void	testSwap2();
	void	testClear1();
	void	testClear2();

	/* ---------------------------- Iterators tests ----------------------------- */

	void	addIterators(Register *list);

	void	testBegin();
	void	testEnd();
	void	testRbegin();
	void	testConstRbegin();
	void	testRend();
	void	testConstRend();
	void	testPostIncrementation();
	void	testPreIncrementation();
	void	testPostDecrementation1();
	void	testPostDecrementation2();

	/* ----------------------------- observers tests ---------------------------- */

	void	addObservers(Register *list);

	void	displayObservers();

	void	testKeyComp();
	void	testValueComp();

	/* ---------------------------- operations tests ---------------------------- */

	void	addOperations(Register *list);

	void	displayOperations();

	void	testFind();
	void	testCount();
	void	testLowerUpperBound();
	void	testEqualRange();

	/* ------------------------------- performance ------------------------------ */

	void	FTperf();
	void	STDperf();
	void	testPerf();

}


#endif

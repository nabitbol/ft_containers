#include "ft_containers_tester.hpp"

void	displaySet() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------- Set tests -------------------------------- */" << std::endl;
	std::cout << std::endl;
}
void	set::addConstructor(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayConstructor);
	list->pushTestFunction(NO_MESG, set::testEmptyParamConstructor);
	list->pushTestFunction(NO_MESG, set::testCopyConstructor);
	list->pushTestFunction(NO_MESG, set::testIteratorConstructor);
}

void	set::addCapacity(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayCapacity);
	list->pushTestFunction(NO_MESG, set::testSize);
	list->pushTestFunction(NO_MESG, set::testMaxSize);
	list->pushTestFunction(NO_MESG, set::testEmpty1);
	list->pushTestFunction(NO_MESG, set::testEmpty2);
}

void	set::addModifiers(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayModifiers);
	list->pushTestFunction(NO_MESG, set::testInsert1);
	list->pushTestFunction(NO_MESG, set::testInsert2);
	list->pushTestFunction(NO_MESG, set::testInsert3);
	list->pushTestFunction(NO_MESG, set::testErase2);
	list->pushTestFunction(NO_MESG, set::testSwap1);
	list->pushTestFunction(NO_MESG, set::testSwap2);
	list->pushTestFunction(NO_MESG, set::testClear1);
	list->pushTestFunction(NO_MESG, set::testClear2);
}

void	set::addIterators(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayIterators);
	list->pushTestFunction(NO_MESG, set::testBegin);
	list->pushTestFunction(NO_MESG, set::testEnd);
	list->pushTestFunction(NO_MESG, set::testRbegin);
	list->pushTestFunction(NO_MESG, set::testRend);
	list->pushTestFunction(NO_MESG, set::testConstRend);
	list->pushTestFunction(NO_MESG, set::testPreIncrementation);
	list->pushTestFunction(NO_MESG, set::testPostIncrementation);
	list->pushTestFunction(NO_MESG, set::testPostDecrementation1);
	list->pushTestFunction(NO_MESG, set::testPostDecrementation2);
}

void	set::addObservers(Register *list) {
	list->pushTestFunction(NO_MESG, set::displayObservers);
	list->pushTestFunction(NO_MESG, set::testKeyComp);
	list->pushTestFunction(NO_MESG, set::testValueComp);
}

void	set::addOperations(Register *list) {
	list->pushTestFunction(NO_MESG, set::displayOperations);
	list->pushTestFunction(NO_MESG, set::testFind);
	list->pushTestFunction(NO_MESG, set::testCount);
	list->pushTestFunction(NO_MESG, set::testEqualRange);
}

void	addSetFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displaySet);
	set::addConstructor(list);
	set::addCapacity(list);
	set::addModifiers(list);
	set::addIterators(list);
	set::addObservers(list);
	set::addOperations(list);
	list->pushTestFunction(NO_MESG, set::testPerf);
	list->pushTestFunction(NO_MESG, jumpNextLine);
}

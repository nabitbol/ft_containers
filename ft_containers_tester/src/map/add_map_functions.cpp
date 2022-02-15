#include "ft_containers_tester.hpp"

void	displayMap() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------- Map tests -------------------------------- */" << std::endl;
	std::cout << std::endl;
}
void	map::addConstructor(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayConstructor);
	list->pushTestFunction(NO_MESG, map::testEmptyParamConstructor);
	list->pushTestFunction(NO_MESG, map::testCopyConstructor);
	list->pushTestFunction(NO_MESG, map::testIteratorConstructor);
}

void	map::addCapacity(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayCapacity);
	list->pushTestFunction(NO_MESG, map::testSize);
	list->pushTestFunction(NO_MESG, map::testMaxSize);
	list->pushTestFunction(NO_MESG, map::testEmpty1);
	list->pushTestFunction(NO_MESG, map::testEmpty2);
}

void	map::addModifiers(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayModifiers);
	list->pushTestFunction(NO_MESG, map::testInsert1);
	list->pushTestFunction(NO_MESG, map::testInsert2);
	list->pushTestFunction(NO_MESG, map::testInsert3);
	list->pushTestFunction(NO_MESG, map::testInsert4);
	list->pushTestFunction(NO_MESG, map::testErase1);
	list->pushTestFunction(NO_MESG, map::testErase2);
	list->pushTestFunction(NO_MESG, map::testSwap1);
	list->pushTestFunction(NO_MESG, map::testSwap2);
	list->pushTestFunction(NO_MESG, map::testClear1);
	list->pushTestFunction(NO_MESG, map::testClear2);
}

void	map::addIterators(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayIterators);
	list->pushTestFunction(NO_MESG, map::testBegin);
	list->pushTestFunction(NO_MESG, map::testEnd);
	list->pushTestFunction(NO_MESG, map::testRbegin);
	list->pushTestFunction(NO_MESG, map::testRend);
	list->pushTestFunction(NO_MESG, map::testConstRend);
	list->pushTestFunction(NO_MESG, map::testPreIncrementation);
	list->pushTestFunction(NO_MESG, map::testPostIncrementation);
	list->pushTestFunction(NO_MESG, map::testPostDecrementation1);
	list->pushTestFunction(NO_MESG, map::testPostDecrementation2);
}

void	map::addObservers(Register *list) {
	list->pushTestFunction(NO_MESG, map::displayObservers);
	list->pushTestFunction(NO_MESG, map::testKeyComp);
	list->pushTestFunction(NO_MESG, map::testValueComp);
}

void	map::addOperations(Register *list) {
	list->pushTestFunction(NO_MESG, map::displayOperations);
	list->pushTestFunction(NO_MESG, map::testFind);
	list->pushTestFunction(NO_MESG, map::testCount);
	list->pushTestFunction(NO_MESG, map::testEqualRange);
}

void	addMapFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayMap);
	map::addConstructor(list);
	map::addCapacity(list);
	map::addModifiers(list);
	map::addIterators(list);
	map::addObservers(list);
	map::addOperations(list);
	list->pushTestFunction(NO_MESG, map::testPerf);
	list->pushTestFunction(NO_MESG, jumpNextLine);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	displayVector() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------ Vector tests ------------------------------ */" << std::endl;
	std::cout << std::endl;
}

void	vector::addConstructor(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR1, vector::testEmptyParamConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR2, vector::testValueConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR3, vector::testCopyConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR4, vector::testIteratorConstructor);
}

void	addIteratorsFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayIterators);
	list->pushTestFunction(TEST_BEGIN, vector::testBegin);
	list->pushTestFunction(TEST_END, vector::testEnd);
	list->pushTestFunction(TEST_RBEGIN, vector::testRbegin);
	list->pushTestFunction(TEST_CONST_RBEGIN, vector::testConstRbegin);
	list->pushTestFunction(TEST_CONST_REND, vector::testConstRend);
	list->pushTestFunction(TEST_ITERATOR_ADDIION1, vector::testAddition1);
	list->pushTestFunction(TEST_ITERATOR_ADDIION2, vector::testAddition2);
	list->pushTestFunction(TEST_ITERATOR_ADDIION3, vector::testAddition3);
	list->pushTestFunction(TEST_ITERATOR_SUBSTRATCION1, vector::testSubstarction1);
	list->pushTestFunction(TEST_ITERATOR_SUBSTRATCION2, vector::testSubstarction2);
	list->pushTestFunction(TEST_INCREMENTATION1, vector::testPreIncrementation);
	list->pushTestFunction(TEST_INCREMENTATION2, vector::testPostIncrementation);
	list->pushTestFunction(TEST_DECREMENTATION1, vector::testPostDecrementation1);
	list->pushTestFunction(TEST_DECREMENTATION2, vector::testPostDecrementation2);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON1, vector::testComparaison1);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON2, vector::testComparaison2);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON3, vector::testComparaison3);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON4, vector::testComparaison4);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON5, vector::testComparaison5);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON6, vector::testComparaison6);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON7, vector::testComparaison7);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON8, vector::testComparaison8);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON9, vector::testComparaison9);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON10, vector::testComparaison10);
	list->pushTestFunction(TEST_ITERATOR_DEREFERENCE, vector::testDerefence);
	list->pushTestFunction(TEST_ITERATOR_MULTI_PASS, vector::testMultiPass);
}

void	addCapacityFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayCapacity);
	list->pushTestFunction(TEST_SIZE, vector::testSize);
	list->pushTestFunction(TEST_MAX_SIZE, vector::testMaxSize);
	list->pushTestFunction(TEST_CAPACITY, vector::testCapacity);
	list->pushTestFunction(TEST_RESIZE1, vector::testResize1);
	list->pushTestFunction(TEST_RESIZE2, vector::testResize2);
	list->pushTestFunction(TEST_RESIZE3, vector::testResize3);
	list->pushTestFunction(TEST_RESIZE4, vector::testResize4);
	list->pushTestFunction(TEST_EMPTY1, vector::testEmpty1);
	list->pushTestFunction(TEST_EMPTY2, vector::testEmpty2);
	list->pushTestFunction(TEST_EMPTY1, vector::testReserve1);
	list->pushTestFunction(TEST_EMPTY2, vector::testReserve2);
}

void	addElementAcessFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayElementAcess);
	list->pushTestFunction(TEST_OPERATOR_ACESS,vector::testOperatorAcess);
	list->pushTestFunction(TEST_AT1 ,vector::testAt1);
	list->pushTestFunction(TEST_AT2,vector::testAt2);
	list->pushTestFunction(TEST_AT3,vector::testAt3);
	list->pushTestFunction(TEST_FRONT,vector::testFront);
	list->pushTestFunction(TEST_BACK,vector::testBack);
}

void	addModifiers(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayModifiers);
	list->pushTestFunction(TEST_ASSIGN1, vector::testAssign1);
	list->pushTestFunction(TEST_ASSIGN2, vector::testAssign2);
	list->pushTestFunction(TEST_ASSIGN3, vector::testAssign3);
	list->pushTestFunction(TEST_ASSIGN4, vector::testAssign4);
	list->pushTestFunction(TEST_PUSH_BACK1, vector::testPushBack1);
	list->pushTestFunction(TEST_POP_BACK1, vector::testPopBack1);
	list->pushTestFunction(TEST_POP_BACK2, vector::testPopBack2);
	list->pushTestFunction(TEST_INSERT1, vector::testInsert1);
	list->pushTestFunction(TEST_INSERT2, vector::testInsert2);
	list->pushTestFunction(TEST_INSERT3, vector::testInsert3);
	list->pushTestFunction(TEST_INSERT4, vector::testInsert4);
	list->pushTestFunction(TEST_INSERT5, vector::testInsert5);
	list->pushTestFunction(TEST_ERASE1, vector::testErase1);
	list->pushTestFunction(TEST_ERASE2, vector::testErase2);
	list->pushTestFunction(TEST_ERASE3, vector::testErase3);
	list->pushTestFunction(TEST_SWAP1, vector::testSwap1);
	list->pushTestFunction(TEST_SWAP2, vector::testSwap2);
	list->pushTestFunction(TEST_SWAP3, vector::testSwap3);
	list->pushTestFunction(TEST_CLEAR1, vector::testClear1);
	list->pushTestFunction(TEST_CLEAR2, vector::testClear2);
}

void	addNonMembers(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayNonMembers);
	list->pushTestFunction(TEST_COMPARISON1, vector::testComparaison1);
	list->pushTestFunction(TEST_COMPARISON2, vector::testComparaison2);
	list->pushTestFunction(TEST_COMPARISON3, vector::testComparaison3);
	list->pushTestFunction(TEST_SWAP4, vector::testSwap4);
}

void	addVectorFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayVector);
	vector::addConstructor(list);
	addIteratorsFunctions(list);
	addCapacityFunctions(list);
	addElementAcessFunctions(list);
	addModifiers(list);
	addNonMembers(list);
	list->pushTestFunction(NO_MESG, vector::testPerf);
	list->pushTestFunction(NO_MESG, jumpNextLine);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	displayVector() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------ Vector tests ------------------------------ */" << std::endl;
	std::cout << std::endl;
}

void	addConstrcutor(Register *list) {
	list->pushTestFunction(NO_MESG, displayConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR1, testEmptyParamConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR2, testValueConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR3, testCopyConstructor);
	list->pushTestFunction(TEST_CONSTRUCTOR4, testIteratorConstructor);
}

void	addIteratorsFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayIterators);
	list->pushTestFunction(TEST_BEGIN,testBegin);
	list->pushTestFunction(TEST_END,testEnd);
	list->pushTestFunction(TEST_RBEGIN,testRbegin);
	list->pushTestFunction(TEST_CONST_RBEGIN,testConstRbegin);
	list->pushTestFunction(TEST_CONST_REND,testConstRend);
	list->pushTestFunction(TEST_ITERATOR_ADDIION1,testAddition1);
	list->pushTestFunction(TEST_ITERATOR_ADDIION2,testAddition2);
	list->pushTestFunction(TEST_ITERATOR_ADDIION3,testAddition3);
	list->pushTestFunction(TEST_ITERATOR_SUBSTRATCION1,testSubstarction1);
	list->pushTestFunction(TEST_ITERATOR_SUBSTRATCION2,testSubstarction2);
	list->pushTestFunction(TEST_INCREMENTATION1,testPreIncrementation);
	list->pushTestFunction(TEST_INCREMENTATION2,testPostIncrementation);
	list->pushTestFunction(TEST_DECREMENTATION1,testPostDecrementation1);
	list->pushTestFunction(TEST_DECREMENTATION2,testPostDecrementation2);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON1,testComparaison1);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON2,testComparaison2);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON3,testComparaison3);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON4,testComparaison4);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON5,testComparaison5);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON6,testComparaison6);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON7,testComparaison7);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON8,testComparaison8);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON9,testComparaison9);
	list->pushTestFunction(TEST_ITERATOR_COMPARISON10,testComparaison10);
	list->pushTestFunction(TEST_ITERATOR_DEREFERENCE,testDerefence);
	list->pushTestFunction(TEST_ITERATOR_MULTI_PASS,testMultiPass);
}

void	addCapacityFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayCapacity);
	list->pushTestFunction(TEST_SIZE ,testSize);
	list->pushTestFunction(TEST_MAX_SIZE, testMaxSize);
	list->pushTestFunction(TEST_CAPACITY, testCapacity);
	list->pushTestFunction(TEST_RESIZE1, testResize1);
	list->pushTestFunction(TEST_RESIZE2, testResize2);
	list->pushTestFunction(TEST_RESIZE3, testResize3);
	list->pushTestFunction(TEST_RESIZE4, testResize4);
	list->pushTestFunction(TEST_EMPTY1, testEmpty1);
	list->pushTestFunction(TEST_EMPTY2, testEmpty2);
	list->pushTestFunction(TEST_EMPTY1, testReserve1);
	list->pushTestFunction(TEST_EMPTY2, testReserve2);
}

void	addElementAcessFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayElementAcess);
	list->pushTestFunction(TEST_OPERATOR_ACESS,testOperatorAcess);
	list->pushTestFunction(TEST_AT1 ,testAt1);
	list->pushTestFunction(TEST_AT2,testAt2);
	list->pushTestFunction(TEST_AT3,testAt3);
	list->pushTestFunction(TEST_FRONT,testFront);
	list->pushTestFunction(TEST_BACK,testBack);
}

void	addModifiers(Register *list) {
	list->pushTestFunction(NO_MESG, displayModifiers);
	list->pushTestFunction(TEST_ASSIGN1, testAssign1);
	list->pushTestFunction(TEST_ASSIGN2, testAssign2);
	list->pushTestFunction(TEST_ASSIGN3, testAssign3);
	list->pushTestFunction(TEST_ASSIGN4, testAssign4);
	list->pushTestFunction(TEST_PUSH_BACK1, testPushBack1);
	list->pushTestFunction(TEST_POP_BACK1, testPopBack1);
	list->pushTestFunction(TEST_POP_BACK2, testPopBack2);
	list->pushTestFunction(TEST_INSERT1, testInsert1);
	list->pushTestFunction(TEST_INSERT2, testInsert2);
	list->pushTestFunction(TEST_INSERT3, testInsert3);
	list->pushTestFunction(TEST_INSERT4, testInsert4);
	list->pushTestFunction(TEST_INSERT5, testInsert5);
	list->pushTestFunction(TEST_ERASE1, testErase1);
	list->pushTestFunction(TEST_ERASE2, testErase2);
	list->pushTestFunction(TEST_ERASE3, testErase3);
	list->pushTestFunction(TEST_SWAP1, testSwap1);
	list->pushTestFunction(TEST_SWAP2, testSwap2);
	list->pushTestFunction(TEST_SWAP3, testSwap3);
	list->pushTestFunction(TEST_CLEAR1, testClear1);
	list->pushTestFunction(TEST_CLEAR2, testClear2);
}

void	addNonMembers(Register *list) {
	list->pushTestFunction(NO_MESG, displayNonMembers);
	list->pushTestFunction(TEST_COMPARISON1, testComparaison1);
	list->pushTestFunction(TEST_COMPARISON2, testComparaison2);
	list->pushTestFunction(TEST_COMPARISON3, testComparaison3);
	list->pushTestFunction(TEST_SWAP4, testSwap4);
}

void	addVectorFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayVector);
	addConstrcutor(list);
	addIteratorsFunctions(list);
	addCapacityFunctions(list);
	addElementAcessFunctions(list);
	addModifiers(list);
	addNonMembers(list);
}

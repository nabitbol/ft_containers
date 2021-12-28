#include "ft_containers_tester.hpp"

void	displayVector() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------ Vector tests ------------------------------ */" << std::endl;
	std::cout << std::endl;
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
	list->pushTestFunction(TEST_AT1 ,testAt1);
	list->pushTestFunction(TEST_AT2,testAt2);
	list->pushTestFunction(TEST_AT3,testAt3);
	list->pushTestFunction(TEST_FRONT,testFront);
	list->pushTestFunction(TEST_BACK,testBack);
}

void	addVectorFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayVector);
	addCapacityFunctions(list);
	addElementAcessFunctions(list);
}

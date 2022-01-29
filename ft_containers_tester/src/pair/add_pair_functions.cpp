#include "ft_containers_tester.hpp"

void	displayPair() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------- Pair tests ------------------------------- */" << std::endl;
	std::cout << std::endl;
}

void	pair::addConstructor(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayConstructor);
	list->pushTestFunction(NO_MESG, pair::testEmptyParamConstructor);
	list->pushTestFunction(NO_MESG, pair::testValueConstructor);
	list->pushTestFunction(NO_MESG, pair::testCopyConstructor);
}

void	addPairFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayPair);
	pair::addConstructor(list);
}

#include "ft_containers_tester.hpp"

void	displayStack() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------ Stack tests ------------------------------- */" << std::endl;
	std::cout << std::endl;
}

void	addConstructor(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayConstructor);
	list->pushTestFunction(NO_MESG, stack::testEmptyParamConstructor);
}

void	addStackFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayStack);
	addConstructor(list);
}

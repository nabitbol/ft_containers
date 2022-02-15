#include "ft_containers_tester.hpp"

void	displayStack() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------ Stack tests ------------------------------- */" << std::endl;
	std::cout << std::endl;
}

void	stack::addConstructor(Register *list) {
	list->pushTestFunction(NO_MESG, vector::displayConstructor);
	list->pushTestFunction(NO_MESG, stack::testEmptyParamConstructor);
	list->pushTestFunction(NO_MESG, stack::testCopyConstructor);
}

void	stack::addMemberFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, stack::displayMemberFunctions);
	list->pushTestFunction(NO_MESG, stack::testEmpty1);
	list->pushTestFunction(NO_MESG, stack::testEmpty2);
	list->pushTestFunction(NO_MESG, stack::testEmpty3);
	list->pushTestFunction(NO_MESG, stack::testSize1);
	list->pushTestFunction(NO_MESG, stack::testSize2);
	list->pushTestFunction(NO_MESG, stack::testTop);
	list->pushTestFunction(NO_MESG, stack::testPush1);
	list->pushTestFunction(NO_MESG, stack::testPush2);
	list->pushTestFunction(NO_MESG, stack::testPop1);
	list->pushTestFunction(NO_MESG, stack::testPop2);
}

void	stack::addNonMemberFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, stack::displayMemberFunctions);
	list->pushTestFunction(NO_MESG, stack::testRop1);
	list->pushTestFunction(NO_MESG, stack::testRop2);
	list->pushTestFunction(NO_MESG, stack::testRop3);
}

void	addStackFunctions(Register *list) {
	list->pushTestFunction(NO_MESG, displayStack);
	stack::addConstructor(list);
	stack::addMemberFunctions(list);
	stack::addNonMemberFunctions(list);
	list->pushTestFunction(NO_MESG, jumpNextLine);
}

#include "ft_containers_tester.hpp"

void	displayBanner(void) {
	std::cout << std::endl;
	std::cout << "'########:'########:::::::::::'######:::'#######::'##::: ##:'########::::'###::::'####:'##::: ##:'########:'########:::::'########:'########::'######::'########:'########:'########::" << std::endl;
	std::cout << " ##.....::... ##..:::::::::::'##... ##:'##.... ##: ###:: ##:... ##..::::'## ##:::. ##:: ###:: ##: ##.....:: ##.... ##::::... ##..:: ##.....::'##... ##:... ##..:: ##.....:: ##.... ##:" << std::endl;
	std::cout << " ##:::::::::: ##::::::::::::: ##:::..:: ##:::: ##: ####: ##:::: ##:::::'##:. ##::: ##:: ####: ##: ##::::::: ##:::: ##::::::: ##:::: ##::::::: ##:::..::::: ##:::: ##::::::: ##:::: ##:" << std::endl;
	std::cout << " ######:::::: ##::::::::::::: ##::::::: ##:::: ##: ## ## ##:::: ##::::'##:::. ##:: ##:: ## ## ##: ######::: ########:::::::: ##:::: ######:::. ######::::: ##:::: ######::: ########::" << std::endl;
	std::cout << " ##...::::::: ##::::::::::::: ##::::::: ##:::: ##: ##. ####:::: ##:::: #########:: ##:: ##. ####: ##...:::: ##.. ##::::::::: ##:::: ##...:::::..... ##:::: ##:::: ##...:::: ##.. ##:::" << std::endl;
	std::cout << " ##:::::::::: ##::::::::::::: ##::: ##: ##:::: ##: ##:. ###:::: ##:::: ##.... ##:: ##:: ##:. ###: ##::::::: ##::. ##:::::::: ##:::: ##:::::::'##::: ##:::: ##:::: ##::::::: ##::. ##::" << std::endl;
	std::cout << " ##:::::::::: ##::::'#######:. ######::. #######:: ##::. ##:::: ##:::: ##:::: ##:'####: ##::. ##: ########: ##:::. ##::::::: ##:::: ########:. ######::::: ##:::: ########: ##:::. ##:" << std::endl;
	std::cout << "..:::::::::::..:::::.......:::......::::.......:::..::::..:::::..:::::..:::::..::....::..::::..::........::..:::::..::::::::..:::::........:::......::::::..:::::........::..:::::..::" << std::endl;
	std::cout << std::endl;
}

void	displayVector() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------ Vector tests ------------------------------ */" << std::endl;
	std::cout << std::endl;
}

void	displayStack() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------ Stack tests ------------------------------- */" << std::endl;
	std::cout << std::endl;
}

void	displayMap() {
	std::cout << std::endl;
	std::cout << "/* ------------------------------= Map tests ==------------------------------ */" << std::endl;
	std::cout << std::endl;
}

int	main(void) {
	displayBanner();
	Register list;

	list.pushTestFunction(NO_MESG, displayVector);
	list.pushTestFunction(NO_MESG, displayCapacity);
	list.pushTestFunction(TEST_SIZE ,testSize);
	list.pushTestFunction(TEST_MAX_SIZE, testMaxSize);
	list.pushTestFunction(TEST_CAPACITY, testCapacity);
	list.pushTestFunction(TEST_RESIZE1, testResize1);
	list.pushTestFunction(TEST_RESIZE2, testResize2);
	list.pushTestFunction(TEST_RESIZE3, testResize3);
	list.pushTestFunction(TEST_RESIZE4, testResize4);
	list.pushTestFunction(TEST_EMPTY, testEmpty);
	list.runAllTests();
	return (0);
}

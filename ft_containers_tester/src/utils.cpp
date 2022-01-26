#include "ft_containers_tester.hpp"

void	displayError(const std::string &tmp1, const std::string &tmp2, const std::string &test) {
		std::cerr << test << std::endl;
		std::cerr << "ft results : " "\033[0;31m" << tmp1 <<"\033[0m" << std::endl;
		std::cerr << "/* -------------------------------------------------------------------------- */" << std::endl;
		std::cerr << "std results : " << "\033[0;35m" <<tmp2 <<"\033[0m" << std::endl;
		std::cerr << std::endl;
}

void	displayCompareResult(const std::stringstream &result1, const std::stringstream &result2, const std::string &test) {
	std::string		tmp1(result1.str());
	std::string		tmp2(result2.str());
	
	if (tmp1.compare(tmp2) == 0) {
		std::cout << " \033[0;32m[OK]\033[0m " << std::flush;
	} else {
		std::cout << " \033[0;31m[KO]\033[0m " << std::flush;
		displayError(tmp1, tmp2, test);
	}
}

void	jumpNextLine() {
	std::cout << "\n" << std::flush;
}

void	displayTitle(std::string title) {
	std::cout.width(SETW);  std::cout << std::left << title;
}

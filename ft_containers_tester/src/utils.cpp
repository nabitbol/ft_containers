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

void	testPerformance(void function(void), void function2(void)) {
		const auto p1 = std::chrono::system_clock::now();
		function();
		const auto p2 = std::chrono::system_clock::now();
		

		const auto p3 = std::chrono::system_clock::now();
		function2();
		const auto p4 = std::chrono::system_clock::now();

		size_t time = ((p1.time_since_epoch().count() - p2.time_since_epoch().count()) / (p3.time_since_epoch().count() - p4.time_since_epoch().count()) );
		if (time > 20) {
			std::cout.width(30); std::cout << "\n\n\n----- To slow you are " << "\033[0;31m" << time << "\033[0m" << " time slower than the std -----" << std::flush;
		} else {
			std::cout.width(30); std::cout << "\n\n\n----- Good your " << "\033[0;32m" << time << "\033[0m" << " time slower than the std -----" << std::flush;
		}
}

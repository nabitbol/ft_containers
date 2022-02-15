#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	map::FTperf() {
	ft::map<std::string, int> a;
	ft::map<std::string, int> b;

	a["toto"] = 19;
	a["zr"] = 50;
	a["coco"] = 4;
	a["this"] = 0;
	a["find"] = -2;

	b["toto"] = 19;
	b["zr"] = 50;
	b["coco"] = 4;
	b["this"] = 0;
	b["find"] = -2;

	std::string string;

	a.swap(b);

	for(int i = 0; i < 50; i++) {
		string += static_cast<char>(i);
		a.insert(ft::pair<std::string, int>(string, i));
	}

	std::stringstream	result1;

	result1 = exec(a, getMapCapacities);
}

void	map::STDperf() {
	std::map<std::string, int> a;
	std::map<std::string, int> b;

	a["toto"] = 19;
	a["zr"] = 50;
	a["coco"] = 4;
	a["this"] = 0;
	a["find"] = -2;

	b["toto"] = 19;
	b["zr"] = 50;
	b["coco"] = 4;
	b["this"] = 0;
	b["find"] = -2;

	std::string string;

	a.swap(b);

	for(int i = 0; i < 50; i++) {
		string += static_cast<char>(i);
		a.insert(std::pair<std::string, int>(string, i));
	}

	std::stringstream	result1;

	result1 = exec(a, getMapCapacities);
}

void	map::testPerf() {
	testPerformance(map::FTperf, map::STDperf);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	vector::FTperf() {
	ft::vector<int> a;
	ft::vector<int> b;

	for (int i = 0; i < 10000000; i++) {
		a.push_back(i);
	}

	a.swap(b);

	std::stringstream	result1;

	result1 = exec(a, getVectorCapacities);
}

void	vector::STDperf() {
	std::vector<int> a;
	std::vector<int> b;

	for (int i = 0; i < 10000000; i++) {
		a.push_back(i);
	}

	a.swap(b);

	std::stringstream	result1;

	result1 = exec(a, getVectorCapacities);
}

void	vector::testPerf() {
	testPerformance(vector::FTperf, vector::STDperf);
}

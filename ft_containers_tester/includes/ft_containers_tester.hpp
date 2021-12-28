#ifndef		FT_CONTAINERS_HPP
# define	FT_CONTAINERS_HPP


/* -------------------------------------------------------------------------- */
/*                                your includes                               */
/* -------------------------------------------------------------------------- */

# include "../../includes/vector.hpp"

/* -------------------------------------------------------------------------- */
/*                               tester includes                              */
/* -------------------------------------------------------------------------- */

# include "./error_test_defines.hpp"
# include <vector>
# include <iostream>
# include <sstream>
# include <fstream>

/* --------------------------------- typedef -------------------------------- */

typedef	void	(*functionPtr)(void);

/* -------------------------------------------------------------------------- */
/*                               class regsiter                               */
/* -------------------------------------------------------------------------- */

class Register {

 private:
	std::vector<functionPtr> _testFunctions;
	std::vector<std::string> _testErrorMsg;

 public:
	Register();
	~Register();
	void	pushTestFunction(const std::string &str, const functionPtr &function);
	void	runAllTests();

};

/* ---------------------------------- utils --------------------------------- */


template <typename T>
std::stringstream		exec(const T &instance, std::stringstream function(const T &)) {
	return (function(instance));
}

void	displayCompareResult(const std::stringstream &result1, const std::stringstream &result2, const std::string &test);

template < typename T>
void	save(const T &instance, std::stringstream &tmp, int index) {
	tmp << instance[index];
	tmp << " ";
}

template < typename T>
void	iterate(const T &instance, std::stringstream &tmp, size_t size, void function(const T &, std::stringstream &, int)) {
	for (size_t i = 0; i < size; i++) {
		function(instance, tmp, i);
	}
}

/* -------------------------------------------------------------------------- */
/*                                   vector                                   */
/* -------------------------------------------------------------------------- */

void	addVectorFunctions(Register *list);

/* ----------------------------- capacity tests ----------------------------- */

void	displayCapacity();

void	testSize();
void	testMaxSize();
void	testCapacity();
void	testResize1();
void	testResize2();
void	testResize3();
void	testResize4();
void	testEmpty1();
void	testEmpty2();
void	testReserve1();
void	testReserve2();

/* --------------------------- Element acess tests -------------------------- */

void	displayElementAcess();

void	testAt1();
void	testAt2();
void	testAt3();
void	testFront();
void	testBack();
void	testOperatorAcess();

#endif

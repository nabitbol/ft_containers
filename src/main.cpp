#include <vector.hpp>
#include <vector>


using namespace NAMESPACE;

int	main(void) {

/* --------------------------------- vector --------------------------------- */

	//Call a non parameter(empty) vector constructor
	::vector<int> a;

	//Call a fill constructor
	::vector<int> b(4, 100);

	// //Call copy constructor
	::vector<int> c(b);

	// //Assignation
	a = b;

	std::cout << std::endl;

	// //Call size
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << c.size() << std::endl;

	std::cout << std::endl;

	// //Call max_size
	std::cout << a.max_size() << std::endl;
	std::cout << b.max_size() << std::endl;
	std::cout << c.max_size() << std::endl;

	std::cout << std::endl;

	// //Call resize
	a.resize(5, 400);
	b.resize(10, 70000);
	c.resize(9);

	std::cout << std::endl;

	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << c.size() << std::endl;

	std::cout << std::endl;

}

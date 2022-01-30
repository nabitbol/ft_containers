#include <vector.hpp>
#include "vector"
#include <map>
#include "map.hpp"

using namespace NAMESPACE;

template < typename T >
void	display(const T &instance, int index) {
	std::cout << instance[index];
	std::cout << ' ';
}

template < typename T >
void	iter(const T &instance, size_t size, void function(const T &, int)) {
	for (size_t i = 0; i < size; i++) {
		function(instance, i);
	}
	std::cout << std::endl;
}

int	main(void) {

/* --------------------------------- vector --------------------------------- */

	//Call a non parameter(empty) vector constructor
	::vector<int> a;

	//Call a fill constructor
	::vector<int> b(4, 100);

	//Call copy constructor
	::vector<int> c(b);

	//Assignation
	a = b;

	std::cout << std::endl;

	//Call size
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << c.size() << std::endl;

	std::cout << std::endl;

	//Call max_size
	std::cout << a.max_size() << std::endl;
	std::cout << b.max_size() << std::endl;
	std::cout << c.max_size() << std::endl;

	std::cout << std::endl;

	std::cout << a.capacity() << std::endl;
	std::cout << b.capacity() << std::endl;
	std::cout << c.capacity() << std::endl;

	std::cout << std::endl;

	::vector<int> ft_vector(b.begin(), b.end());
	iter< ::vector<int> >(c, c.size(), &display);

	//Call resize
	a.resize(5, 400);
	b.resize(10, 70000);
	c.resize(9);

	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << c.size() << std::endl;

	std::cout << std::endl;

	std::cout << a.capacity() << std::endl;
	std::cout << b.capacity() << std::endl;
	std::cout << c.capacity() << std::endl;	

	iter< ::vector<int> >(c, c.size(), &display);

	std::cout << std::endl;

	// iter< ::vector<int> >(a, a.size(), &display);
	// iter< ::vector<int> >(b, b.size(), &display);

	ft::pair<std::string, int> *ptr = new ft::pair<std::string, int>[8];

	ptr[0] = {"toto", 2};
	ptr[1] = {"coco", 3};
	ptr[2] = {"zr", 19};
	ptr[3] = {"atoi", 100};
	ptr[4] = {"prout", 0};
	ptr[5] = {"fuck", 10};
	ptr[6] = {"this", -1};
	ptr[7] = {"guy", 81};

	ft::map<const std::string, int> toto;

	toto.insert(reinterpret_cast<ft::pair<const std::string, int>*>(ptr), 8);
	std::cout << toto;

	std::cout << std::endl;

}

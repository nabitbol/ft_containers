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

	ft::map<const std::string, int> toto;
	std::map<const std::string, int> pop;

	toto.insert({"toto", 2});
	toto.insert({"zr", 19});
	toto.insert({"yoyo", 100});
	toto.insert({"coco", 3});
	toto.insert({"sout", 0});
	toto.insert({"og", 10});
	toto.insert({"this", -1});
	toto.insert({"go", 81});

	pop.insert({"toto", 2});
	pop.insert({"zr", 19});
	pop.insert({"yoyo", 100});
	pop.insert({"coco", 3});
	pop.insert({"sout", 0});
	pop.insert({"og", 10});
	pop.insert({"this", -1});
	pop.insert({"go", 81});

	ft::map<const std::string, int>::iterator itf = toto.begin();
	std::map<const std::string, int>::iterator it = pop.begin();
	std::cout << itf->first << std::endl;
	std::cout << it->first << std::endl;
	// std::cout << toto.toString().str();

	std::cout << std::endl;

}

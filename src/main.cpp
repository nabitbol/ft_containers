#include <vector.hpp>
#include <vector>


using namespace NAMESPACE;

int	main(void) {

/* --------------------------------- vector --------------------------------- */

	//Call a non parameter(empty) vector constructor
	::vector<int> a;

	//Call a fill constructor
	::vector<int> b(4, 100);

	//assignation
	a = b;

}

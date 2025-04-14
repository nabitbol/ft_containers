# ft_containers

A reimplementation of the containers from the STL  (standard template library) in C++ 98.

## Implemented Containers

This project currently includes the following container implementations:

* **`vector`:** A dynamic array that supports efficient random access and amortized constant-time insertion/deletion at the end. [leanr more](https://en.cppreference.com/w/cpp/container/vector)
* **`map`:** An associative container that stores key-value pairs, allowing efficient retrieval of values based on their unique keys. Implemented using a self-balancing binary search tree (likely a simplified version of a red-black tree or an AVL tree for C++98 compatibility).[leanr more](https://en.cppreference.com/w/cpp/container/map)
* **`stack`:** An adapter container that provides a Last-In, First-Out (LIFO) data structure, typically implemented on top of `vector` or `deque`. [leanr more](https://en.cppreference.com/w/cpp/container/stack)
* **`set`:** An associative container that stores unique elements in a sorted order. Implemented using a self-balancing binary search tree, similar to `map` but only storing keys. [leanr more](https://en.cppreference.com/w/cpp/container/set)


## Quick start

Clone the project and `cd` inside the cloned directory

```bash
$> make
```

```c++
#include <vector.hpp>

using namespace NAMESPACE;

int	main(void) {

/* --------------------------------- vector --------------------------------- */

	//Call a non parameter(empty) vector constructor
	ft::vector<int> a;

	//Call a fill constructor
	ft::vector<int> b(4, 100);

	//Call copy constructor
	ft::vector<int> c(b);

	//Assignation
	a = b;

	std::cout << std::endl;

	//Call size
	std::cout << a.size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << c.size() << std::endl;
```

# About

The project encompasses a tester I created myself. You can find it in `ft_container_tester` directory.
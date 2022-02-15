#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	stack::displayMemberFunctions() {
	std::cout << "\n" << std::endl;
	displayTitle("[member-functions]: ");
}

/* ----------------------------- empty functions ---------------------------- */

/*
** test1
*/
void	stack::testEmpty1() {
	ft::stack<int> a;
	std::stack<int> b;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test2
*/
void	stack::testEmpty2() {
	std::deque<int> mydeque (3,100);

	ft::stack<int, std::deque<int> > a(mydeque);
	std::stack<int, std::deque<int> > b(mydeque);

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test3
*/
void	stack::testEmpty3() {
	ft::stack<std::string> a;
	std::stack<std::string> b;

	a.push("toto");
	b.push("toto");

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getEmpty);
	result2 = exec(b, getEmpty);

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- size functions ----------------------------- */

/*
** test1
*/
void	stack::testSize1() {
	ft::stack<int> a;
	std::stack<int> b;

	for(int i = 0; i < 100; i++) {
		a.push(i);
		b.push(i);
	}

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSize);
	result2 = exec(b, getSize);

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test2
*/
void	stack::testSize2() {
	ft::stack<int> a;
	std::stack<int> b;

	for(int i = 0; i < 100; i++) {
		a.push(i);
		b.push(i);
	}

	for (int i = 0; i < 50 ; i++) {
		a.pop();
		b.pop();
	}

	std::stringstream	result1;
	std::stringstream	result2;

	result1 = exec(a, getSize);
	result2 = exec(b, getSize);

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------------ top functions ----------------------------- */

void	stack::testTop() {
	ft::stack<int> a;
	std::stack<int> b;

	a.push(10);
	a.push(20);

	b.push(10);
	b.push(20);

	a.top() -= 5;
	b.top() -= 5;

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "Size: " << a.size() << "Top: " << a.top() << std::endl;
	result2 << "Size: " << b.size() << "Top: " << b.top() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

/* -------------------------------- test push ------------------------------- */

/*
** test1
*/
void	stack::testPush1() {
	ft::stack<int> a;
	std::stack<int> b;

	for(int i = 0; i < 100; i++) {
		a.push(i);
		b.push(i);
	}

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "Size: " << a.size() << "Top: " << a.top() << std::endl;
	result2 << "Size: " << b.size() << "Top: " << b.top() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

/*
** test2
*/
void	stack::testPush2() {
	std::deque<int> mydeque(4, 40);

	ft::stack<int, std::deque<int> > a(mydeque);
	std::stack<int, std::deque<int> > b(mydeque);

	for(int i = 0; i < 100; i++) {
		a.push(i);
		b.push(i);
	}

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "Size: " << a.size() << "Top: " << a.top() << std::endl;
	result2 << "Size: " << b.size() << "Top: " << b.top() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}

/* -------------------------------- test pop -------------------------------- */

/*
** test1
*/
void	stack::testPop1() {
	ft::stack<int> a;
	std::stack<int> b;

	for(int i = 0; i < 100; i++) {
		a.push(i);
		b.push(i);
	}

	for (int i = 0; i < 50 ; i++) {
		a.pop();
		b.pop();
	}

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "Size: " << a.size() << "Top: " << a.top() << std::endl;
	result2 << "Size: " << b.size() << "Top: " << b.top() << std::endl;

	displayCompareResult(result1, result2, NO_MESG);
}


/*
** test2
*/
void	stack::testPop2() {
	ft::stack<int> a;
	std::stack<int> b;

	for (int i=0; i<5; ++i)
		a.push(i);
	for (int i=0; i<5; ++i) 
		b.push(i);

	std::stringstream	result1;
	std::stringstream	result2;	

	while (!a.empty()) {
		result1 << ' ' << a.top();
		a.pop();
	}

		while (!b.empty()) {
		result2 << ' ' << b.top();
		b.pop();
	}

	displayCompareResult(result1, result2, NO_MESG);
}

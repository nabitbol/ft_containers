#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	set::displayOperations() {
	std::cout << "\n" << std::endl;
	displayTitle("[operations]: ");
}

/* ----------------------------- find functions ----------------------------- */

void	set::testFind() {
	ft::set<std::string> a;
	std::set<std::string> b;

	a.insert("toto");
	a.insert("zr");
	a.insert("coco");
	a.insert("this");
	a.insert("find");

	b.insert("toto");
	b.insert("zr");
	b.insert("coco");
	b.insert("this");
	b.insert("find");

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "toto => " << *(a.find("toto")) << '\n';
	result1 << "zr => " << *(a.find("zr")) << '\n';
	result1 << "this => " << *(a.find("this")) << '\n';

	result2 << "toto => " << *(b.find("toto")) << '\n';
	result2 << "zr => " << *(b.find("zr")) << '\n';
	result2 << "this => " << *(b.find("this")) << '\n';

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- count functions ---------------------------- */

void	set::testCount() {
	ft::set<char> a;
	std::set<char> b;
	char c;

	a.insert('a');
	a.insert('c');
	a.insert('f');

	b.insert('a');
	b.insert('c');
	b.insert('f');

	std::stringstream	result1;
	std::stringstream	result2;

	for (c='a'; c<'h'; c++)
	{
	result1 << c;
	if (a.count(c)>0)
		result1 << " is an element of set.\n";
	else 
		result1 << " is not an element of set.\n";
	}

	for (c='a'; c<'h'; c++)
	{
	result2 << c;
	if (b.count(c)>0)
		result2 << " is an element of set.\n";
	else 
		result2 << " is not an element of set.\n";
	}

	displayCompareResult(result1, result2, NO_MESG);
}

/* -------------------------- lower bound functions ------------------------- */

void	set::testLowerUpperBound() {
	ft::set<char> a;
	std::set<char> b;

	ft::set<char>::iterator aitlow,aitup;
	std::set<char>::iterator bitlow,bitup;

	a.insert('a');
	a.insert('b');
	a.insert('c');
	a.insert('d');
	a.insert('e');

	b.insert('a');
	b.insert('b');
	b.insert('c');
	b.insert('d');
	b.insert('e');

	aitlow=a.lower_bound ('b');  // itlow points to b
	aitup=a.upper_bound ('d');   // itup points to e (not d!)

	a.erase(aitlow,aitup);        // erases [itlow,itup)


	bitlow=b.lower_bound ('b');  // itlow points to b
	bitup=b.upper_bound ('d');   // itup points to e (not d!)

	b.erase(bitlow,bitup);        // erases [itlow,itup)

	std::stringstream	result1;
	std::stringstream	result2;

	// print content:
	for (ft::set<char,int>::iterator it=a.begin(); it!=a.end(); ++it)
		result1 << *it << " => " << *it << '\n';

	for (std::set<char,int>::iterator it=b.begin(); it!=b.end(); ++it)
		result2 << *it << " => " << *it << '\n';

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------------- equal_range ------------------------------ */

void	set::testEqualRange() {
	ft::set<char> a;
	std::set<char> b;

	ft::set<char>::iterator aitlow,aitup;
	std::set<char>::iterator bitlow,bitup;

	a.insert('a');
	a.insert('b');
	a.insert('c');
	a.insert('d');
	a.insert('e');

	b.insert('a');
	b.insert('b');
	b.insert('c');
	b.insert('d');
	b.insert('e');


	std::stringstream	result1;
	std::stringstream	result2;

	// print content:
	ft::pair<ft::set<char>::iterator,ft::set<char>::iterator> aret;
	aret = a.equal_range('b');

	std::pair<std::set<char>::iterator,std::set<char>::iterator> bret;
	bret = b.equal_range('b');

	result1 << "lower bound points to: ";
	result1 << *(aret.first) << " => " << *(aret.first) << '\n';

	result1 << "upper bound points to: ";
	result1 << *(aret.second) << " => " << *(aret.second) << '\n';

	result2 << "lower bound points to: ";
	result2 << *(bret.first) << " => " << *(bret.first) << '\n';

	result2 << "upper bound points to: ";
	result2 << *(bret.second) << " => " << *(bret.second) << '\n';

	displayCompareResult(result1, result2, NO_MESG);
}

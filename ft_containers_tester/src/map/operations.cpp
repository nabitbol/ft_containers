#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	map::displayOperations() {
	std::cout << "\n" << std::endl;
	displayTitle("[operations]: ");
}

/* ----------------------------- find functions ----------------------------- */

void	map::testFind() {
	ft::map<std::string, int> a;
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

	std::stringstream	result1;
	std::stringstream	result2;

	result1 << "toto => " << a.find("toto")->second << '\n';
	result1 << "zr => " << a.find("zr")->second << '\n';
	result1 << "this => " << a.find("this")->second << '\n';

	result2 << "toto => " << b.find("toto")->second << '\n';
	result2 << "zr => " << b.find("zr")->second << '\n';
	result2 << "this => " << b.find("this")->second << '\n';

	displayCompareResult(result1, result2, NO_MESG);
}

/* ----------------------------- count functions ---------------------------- */

void	map::testCount() {
	ft::map<char,int> a;
	std::map<char,int> b;
	char c;

	a['a']=101;
	a['c']=202;
	a['f']=303;

	b['a']=101;
	b['c']=202;
	b['f']=303;

	std::stringstream	result1;
	std::stringstream	result2;

	for (c='a'; c<'h'; c++)
	{
	result1 << c;
	if (a.count(c)>0)
		result1 << " is an element of map.\n";
	else 
		result1 << " is not an element of map.\n";
	}

	for (c='a'; c<'h'; c++)
	{
	result2 << c;
	if (b.count(c)>0)
		result2 << " is an element of map.\n";
	else 
		result2 << " is not an element of map.\n";
	}

	displayCompareResult(result1, result2, NO_MESG);
}

/* -------------------------- lower bound functions ------------------------- */

void	map::testLowerUpperBound() {
	ft::map<char,int> a;
	std::map<char,int> b;

	ft::map<char,int>::iterator aitlow,aitup;
	std::map<char,int>::iterator bitlow,bitup;

	a['a']=20;
	a['b']=40;
	a['c']=60;
	a['d']=80;
	a['e']=100;

	b['a']=20;
	b['b']=40;
	b['c']=60;
	b['d']=80;
	b['e']=100;

	aitlow=a.lower_bound ('b');  // itlow points to b
	aitup=a.upper_bound ('d');   // itup points to e (not d!)

	a.erase(aitlow,aitup);        // erases [itlow,itup)


	bitlow=b.lower_bound ('b');  // itlow points to b
	bitup=b.upper_bound ('d');   // itup points to e (not d!)

	b.erase(bitlow,bitup);        // erases [itlow,itup)

	std::stringstream	result1;
	std::stringstream	result2;

	// print content:
	for (ft::map<char,int>::iterator it=a.begin(); it!=a.end(); ++it)
		result1 << it->first << " => " << it->second << '\n';

	for (std::map<char,int>::iterator it=b.begin(); it!=b.end(); ++it)
		result2 << it->first << " => " << it->second << '\n';

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------------- equal_range ------------------------------ */

void	map::testEqualRange() {
	ft::map<char,int> a;
	std::map<char,int> b;

	ft::map<char,int>::iterator aitlow,aitup;
	std::map<char,int>::iterator bitlow,bitup;

	a['a']=20;
	a['b']=40;
	a['c']=60;
	a['d']=80;
	a['e']=100;

	b['a']=20;
	b['b']=40;
	b['c']=60;
	b['d']=80;
	b['e']=100;

	std::stringstream	result1;
	std::stringstream	result2;

	// print content:
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> aret;
	aret = a.equal_range('b');

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> bret;
	bret = b.equal_range('b');

	result1 << "lower bound points to: ";
	result1 << aret.first->first << " => " << aret.first->second << '\n';

	result1 << "upper bound points to: ";
	result1 << aret.second->first << " => " << aret.second->second << '\n';

	result2 << "lower bound points to: ";
	result2 << bret.first->first << " => " << bret.first->second << '\n';

	result2 << "upper bound points to: ";
	result2 << bret.second->first << " => " << bret.second->second << '\n';

	displayCompareResult(result1, result2, NO_MESG);
}

#include "ft_containers_tester.hpp"
#include "error_test_defines_vector.hpp"

void	map::displayObservers() {
	std::cout << "\n" << std::endl;
	displayTitle("[observers]: ");
}

/* --------------------------- key_comp functions --------------------------- */

void	map::testKeyComp() {
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

	ft::map<std::string,int>::key_compare acomp = a.key_comp();
	std::map<std::string,int>::key_compare bcomp = b.key_comp();

	std::string ahighest = a.rbegin()->first;     // key value of last element
	std::string bhighest = b.rbegin()->first;     // key value of last element

	std::stringstream	result1;
	std::stringstream	result2;

	ft::map<std::string,int>::iterator ita = a.begin();
 	 do {
	result1 << ita->first << " => " << ita->second << '\n';
	} while ( acomp((*ita++).first, ahighest) );

	std::map<std::string,int>::iterator itb = b.begin();
 	 do {
	result2 << itb->first << " => " << itb->second << '\n';
	} while ( bcomp((*itb++).first, bhighest) );

	displayCompareResult(result1, result2, NO_MESG);
}

/* ------------------------- value_compare functions ------------------------ */

void	map::testValueComp() {
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

	ft::pair<std::string, int> ahighest = *a.rbegin();     // key value of last element
	std::pair<std::string, int> bhighest = *b.rbegin();     // key value of last element

	std::stringstream	result1;
	std::stringstream	result2;

	ft::map<std::string,int>::iterator ita = a.begin();
 	 do {
	result1 << ita->first << " => " << ita->second << '\n';
	} while ( a.value_comp()(*ita++, ahighest));

	std::map<std::string,int>::iterator itb = b.begin();
 	 do {
	result2 << itb->first << " => " << itb->second << '\n';
	} while ( b.value_comp()(*itb++, bhighest));

	displayCompareResult(result1, result2, NO_MESG);
}

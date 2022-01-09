#ifndef		ERROR_TEST_DEFINE_HPP
# define	ERROR_TEST_DEFINE_HPP

#define  NO_MESG	""

/* -------------------------------------------------------------------------- */
/*                                   Vector                                   */
/* -------------------------------------------------------------------------- */

#define  TEST_SIZE 	"/* ---------------------------- Test Vector Size ---------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.size();\n"

#define  TEST_MAX_SIZE  "/* -------------------------- Test Vector Max Size -------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.max_size();\n"

#define  TEST_CAPACITY  "/* ------------------------------ Test Capacity ----------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.capcity();\n"

#define  TEST_RESIZE1  "/* ------------------------------ Test Resize1 ------------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 600);\n"

#define  TEST_RESIZE2  "/* ------------------------------ Test Resize2 ------------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(10, 7000);\n"

#define  TEST_RESIZE3  "/* ------------------------------ Test Resize3 ------------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(9);\n"

#define  TEST_RESIZE4  "/* ------------------------------ Test Resize4 ------------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(3);\n"

#define  TEST_EMPTY1  "/* ------------------------------- Test Empty1 ------------------------------ */\n\n" \
					"std::vector<int> instance;\ninstance.empty();\n"

#define  TEST_EMPTY2  "/* ------------------------------- Test Empty2 ------------------------------ */\n\n" \
					"std::vector<int> instance(30, 2);\ninstance.empty();\n"

#define  TEST_RESERVE1 "/* ------------------------------ Test Reserve1 ----------------------------- */\n\n" \
					"std::vector<int> instance(10, 40);\ninstance.reserve(100);\n"

#define  TEST_RESERVE2 "/* ------------------------------ Test Reserve2 ----------------------------- */\n\n" \
					"std::vector<int> instance(10, 40);\ninstance.reserve(8);\n"

#define  TEST_OPERATOR_ACESS "/* --------------------------------- Test [] -------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nfor(unsigned i=0; i < instance.size(); i++);\ninstance[index];\n"

#define  TEST_AT1 "/* --------------------------------- Test At1 ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.at(3);\n"

#define  TEST_AT2 "/* --------------------------------- Test At2 ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nfor (unsigned i=0; i<instance.size(); i++)\na.at(i)=i;\n"

#define  TEST_AT3 "/* --------------------------------- Test At3 ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.at(5);\n"

#define  TEST_FRONT "/* ------------------------------- Test Front ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nfor (unsigned i=0; i<instance.size(); i++)\ninstance.front();\n"

#define  TEST_BACK "/* -------------------------------- Test Back -------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nfor (unsigned i=0; i<instance.size(); i++)\ninstance.back();\n"

#define  TEST_BEGIN "/* ------------------------------- Test Begin ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.begin();\n"

#define  TEST_RBEGIN "/* ------------------------------- Test Rbegin ------------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(6, 700);\nstd::vector<int>::reverse_iterator it = instance.rbegin();\n"

#define  TEST_CONST_RBEGIN "/* ---------------------------- Test Const Rbegin --------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(6, 700);\nstd::vector<int>::const_reverse_iterator it = instance.rbegin();\n"

#define  TEST_REND "/* -------------------------------- Test Rend ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(6, 700);\nstd::vector<int>::reverse_iterator it = instance.rend();\n"

#define  TEST_CONST_REND "/* ----------------------------- Test Const Rend ---------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(6, 700);\nstd::vector<int>::const_reverse_iterator it = instance.rend();\n"

#define  TEST_ITERATOR_ADDIION1 "/* ------------------------- Test Iterator Addition1 ------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.begin();\nit = it2 + 5;\n"

#define  TEST_ITERATOR_ADDIION2 "/* ------------------------- Test Iterator Addition2 ------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.begin();\nit = 5 + it2;\n"

#define  TEST_ITERATOR_ADDIION3 "/* ------------------------- Test Iterator Addition3 ------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"it += 5;\n"

#define  TEST_ITERATOR_SUBSTRATCION1 "/* ----------------------- Test Iterator Substraction1 ---------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.begin();\nit = it2 - 1;\n"

#define  TEST_ITERATOR_SUBSTRATCION2 "/* ----------------------- Test Iterator Substraction1 ---------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"it -= 1;\n"

#define  TEST_END "/* -------------------------------- Test End -------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.end();\n"

#define  TEST_INCREMENTATION1 "/* -------------------------- Test Incrementation1 -------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.begin();\nit++;\n"

#define  TEST_INCREMENTATION2 "/* -------------------------- Test Incrementation2 -------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.begin();\n++i;\n"

#define  TEST_DECREMENTATION1 "/* -------------------------- Test Decrementation1 -------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.end();\nit--;\n"

#define  TEST_DECREMENTATION2 "/* -------------------------- Test Decrementation2 -------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.end();\n--it;\n"

#define  TEST_ITERATOR_COMPARISON1 "/* ------------------------- Test Iterator Comparson1 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit < it2;\n"

#define  TEST_ITERATOR_COMPARISON2 "/* ------------------------- Test Iterator Comparson2 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit <= it2;\n"

#define  TEST_ITERATOR_COMPARISON3 "/* ------------------------- Test Iterator Comparson3 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.begin();\nit <= it2;\n"

#define  TEST_ITERATOR_COMPARISON4 "/* ------------------------- Test Iterator Comparson4 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit > it2;\n"

#define  TEST_ITERATOR_COMPARISON5 "/* ------------------------- Test Iterator Comparson5 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit >= it2;\n"

#define  TEST_ITERATOR_COMPARISON6 "/* ------------------------- Test Iterator Comparson6 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.begin();\nit >= it2;\n"

#define  TEST_ITERATOR_COMPARISON7 "/* ------------------------- Test Iterator Comparson7 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.begin();\nit == it2;\n"

#define  TEST_ITERATOR_COMPARISON8 "/* ------------------------- Test Iterator Comparson8 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit == it2;\n"

#define  TEST_ITERATOR_COMPARISON9 "/* ------------------------- Test Iterator Comparson9 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.begin();\nit != it2;\n"

#define  TEST_ITERATOR_COMPARISON10 "/* ------------------------- Test Iterator Comparson10 ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit != it2;\n"

#define  TEST_ITERATOR_DEREFERENCE "/* ------------------------ Test Iterator Dereference ----------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"it[5];\n"

#define  TEST_ITERATOR_MULTI_PASS "/* ------------------------ Test Iterator Multi Pass ------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit = it2;\nit2++;\n*it *it2\n;"

#endif

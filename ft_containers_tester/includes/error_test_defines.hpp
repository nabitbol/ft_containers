#ifndef		ERROR_TEST_DEFINE_HPP
# define	ERROR_TEST_DEFINE_HPP

#define  NO_MESG	""

/* -------------------------------------------------------------------------- */
/*                                   Vector                                   */
/* -------------------------------------------------------------------------- */

#define  TEST_CONSTRUCTOR1 "/* ---------------------------- Test Constructor1 --------------------------- */\n\n" \
					"std::vector<int> instance;\n"

#define  TEST_CONSTRUCTOR2 "/* ---------------------------- Test Constructor2 --------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance[1];\n"

#define  TEST_CONSTRUCTOR3 "/* ---------------------------- Test Constructor3 --------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int> instanceCopy(instance);\ninstanceCopy[1];\n"

#define  TEST_CONSTRUCTOR4 "/* ---------------------------- Test Constructor4 --------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.resize(5, 90);\nstd::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.end();\nit = it2;\nit2++;\n*it;\n*it2;\n" \
					"std::vector<int> newInstance(instance.begin(), it);\n" \
					"for (int i = 0; i < newInstance.size(); i++) { newInstance[i] };\n"

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
					"std::vector<int>::iterator it2 = instance.end();\nit = it2;\nit2++;\n*it;\n*it2;\n"

#define  TEST_ASSIGN1 "/* ------------------------------ Test Assign1 ------------------------------ */\n\n" \
					"std::vector<int> instance;\ninstance.assign(7, 100);\n"

#define  TEST_ASSIGN2 "/* ------------------------------ Test Assign2 ------------------------------ */\n\n" \
					"std::vector<int> instance(4,100);\ninstance.assign(3, 200);\n"

#define  TEST_ASSIGN3 "/* ------------------------------ Test Assign3 ------------------------------ */\n\n" \
					"std::vector<int> instance;\ninstance.assign(7, 200);\nstd::vector<int> instance2;\n" \
					"std::vector<int>::iterator it = instance.begin() + 1;\ninstance2.assign(it, instance.end() - 1)\n"

#define  TEST_ASSIGN4 "/* ------------------------------ Test Assign4 ------------------------------ */\n\n" \
					"std::vector<int> instance;\nint myints[] = {1776,7,4};\ninstance.assign(40, myints[1]);\ninstance.resize(20,20)\n"

#define  TEST_PUSH_BACK1 "/* ----------------------------- Test Push_back1 ---------------------------- */\n\n" \
					"std::vector<int> instance;\nnstance.push_back(20);\nnstance.push_back(30);\n"

#define  TEST_POP_BACK1 "/* ----------------------------- Test Pop_back1 ----------------------------- */\n\n" \
					"std::vector<int> instance;\nnstance.push_back(20);\nnstance.push_back(30);\n" \
					"while(!insatnce.empty)\n;	instance.pop_back();\n"

#define  TEST_POP_BACK2 "/* ----------------------------- Test Pop_back2 ----------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.pop_back();\n"

#define  TEST_INSERT1 "/* ------------------------------ Test Insert1 ----------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.begin() + 1;\n" \
					"instance.insert(it, 47);\n"

#define  TEST_INSERT2 "/* ------------------------------ Test Insert2 ----------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.end();\n" \
					"instance.insert(it, 22);\n"

#define  TEST_INSERT3 "/* ------------------------------ Test Insert3 ----------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\nstd::vector<int>::iterator it = instance.begin() + 1;\n" \
					"instance.insert(it, 2, 30);\n"

#define  TEST_INSERT4 "/* ------------------------------ Test Insert4 ----------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.reserve(8);\nstd::vector<int>::iterator it = instance.begin() + 1;\n" \
					"instance.insert(it, 2, 30);\n"

#define  TEST_INSERT5 "/* ------------------------------ Test Insert5 ----------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.reserve(8);\nstd::vector<int>::iterator it = instance.begin() + 2;\n" \
					"instance.insert(it, instance.begin(), instance.end());\n"

#define  TEST_ERASE1 "/* ------------------------------- Test Erase1 ------------------------------ */\n\n" \
					"std::vector<int> instance(4);\ninstance.push_back(100);\ninstance.push_back(28);\n" \
					"instance.push_back(30);\nnstance.push_back(49);\nstd::vector<int>::iterator it = instance.begin() + 2;\n" \
					"instance.erase(it);\n"

#define  TEST_ERASE2 "/* ------------------------------- Test Erase2 ------------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.push_back(400);\n" \
					"std::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.erase(it);\n"

#define  TEST_ERASE3 "/* ------------------------------- Test Erase3 ------------------------------ */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.push_back(400);\n" \
					"instance.push_back(40);\ninstance.push_back(64);\ninstance.push_back(29);\n" \
					"std::vector<int>::iterator it = instance.begin();\n" \
					"std::vector<int>::iterator it2 = instance.erase(it, (it + 4));\n"

#define  TEST_SWAP1 "/* ------------------------------- Test Swap1 ------------------------------- */\n\n" \
					"std::vector<int> instance(3, 100);\nstd::vector<int> instance2;\n" \
					"instance2.push_back(400);\ninstance2(64)\n;" \
					"instance2.push_back(40);\ninstance2(29)\n;" \
					"instance.swap(instance2);\n"

#define  TEST_SWAP2 "/* ------------------------------- Test Swap2 ------------------------------- */\n\n" \
					"std::vector<int> instance(3, 100);\nstd::vector<int> instance2;\n" \
					"instance.swap(instance2);\n"

#define  TEST_SWAP3 "/* ------------------------------- Test Swap3 ------------------------------- */\n\n" \
					"std::vector<int> instance(3, 100);\nstd::vector<int> instance2;\n" \
					"instance2.push_back(400);\ninstance2(64)\n;" \
					"instance.swap(instance2);\n"

#define  TEST_CLEAR1 "/* ------------------------------- Test Swap3 ------------------------------- */\n\n" \
					"std::vector<int> instance(3, 100);\ninstance.clear();\n"

#define  TEST_CLEAR2 "/* ------------------------------- Test Swap1 ------------------------------- */\n\n" \
					"std::vector<int> instance(3, 100);\nstd::vector<int> instance2;\n" \
					"instance2.push_back(400);\ninstance2(64)\n;" \
					"instance2.push_back(40);\ninstance2(29)\n;" \
					"instance.swap(instance2);\ninstance.clear();\n"

#define  TEST_COMPARISON1 "/* ---------------------------- Test Comparison1 ---------------------------- */\n\n" \
					"std::vector<int> instance(7, 100);\nstd::vector<int> instance2(7, 100);\n" \
					"instance == instance2;\ninstance != instance2;\ninstance > instance2;\n" \
					"instance >= instance2;\ninstance < instance2;\ninstance <= instance2;\n"

#define  TEST_COMPARISON2 "/* ---------------------------- Test Comparison2 ---------------------------- */\n\n" \
					"std::vector<int> instance(1, 100);\nstd::vector<int> instance2(7, 100);\n" \
					"instance == instance2;\ninstance != instance2;\ninstance > instance2;\n" \
					"instance >= instance2;\ninstance < instance2;\ninstance <= instance2;\n"

#define  TEST_COMPARISON3 "/* ---------------------------- Test Comparison3 ---------------------------- */\n\n" \
					"std::vector<int> instance(7, 50);\nstd::vector<int> instance2(7, 100);\n" \
					"instance == instance2;\ninstance != instance2;\ninstance > instance2;\n" \
					"instance >= instance2;\ninstance < instance2;\ninstance <= instance2;\n"

#define  TEST_SWAP4 "/* ------------------------------- Test Swap4 ------------------------------- */\n\n" \
					"std::vector<int> instance(3, 100);\nstd::vector<int> instance2;\n" \
					"instance2.push_back(400);\ninstance2(64)\n;" \
					"swap(instance, instance2);\n"

#endif

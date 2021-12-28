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

#define  TEST_AT1 "/* --------------------------------- Test At1 ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.at(3);\n"

#define  TEST_AT2 "/* --------------------------------- Test At2 ------------------------------- */\n\n" \
					"std::vector<int> instance(4, 100);\ninstance.at(3);\n"

#endif

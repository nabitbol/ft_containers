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

#endif

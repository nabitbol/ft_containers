# #############################################################################
#
# Sources lists
#
# #############################################################################

# CPP files
FILENAME_LIST_SRCS= \
	main.cpp \

# #############################################################################
#
# Compiler options
#
# #############################################################################

COMPILER_EXECUTABLE=clang++

COMPILER_LIBS= \

COMPILER_WARNING_FLAGS= \
	-Wall \
	-Wextra \
	-Werror \
	#-std=c++98 \

# #############################################################################
#
# Project configuration
#
# #############################################################################

# Targets
FILENAMELIST_TARGET= \
	ft_container \
	std_container

# Directories names
DIRNAME_BIN=bin
DIRNAME_OBJ=obj
DIRNAME_SRC=src
DIRNAME_INC=includes
DIRNAME_TEST=ft_containers_tester

# Directory paths
DIRPATH_OBJ=$(DIRNAME_BIN)/$(DIRNAME_OBJ)

# File path lists
FILEPATHLIST_SRCS=$(addprefix $(DIRNAME_SRC)/, $(FILENAME_LIST_SRCS))

# Merge all CPP lists in one
FILEPATHLIST_CPP= \
	$(FILEPATHLIST_SRCS) \

FILEPATHLIST_OPP_FT=$(subst \
		$(DIRNAME_SRC), \
		$(DIRPATH_OBJ)/ft, \
		$(FILEPATHLIST_CPP:.cpp=.opp) \
	)
FILEPATHLIST_OPP_STD=$(subst \
		$(DIRNAME_SRC), \
		$(DIRPATH_OBJ)/std, \
		$(FILEPATHLIST_CPP:.cpp=.opp) \
	)

# #############################################################################
#
# Rules
#
# #############################################################################

.DEFAULT_GOAL = all

# Build target
ft_container: $(FILEPATHLIST_OPP_FT)
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) TARGET --> $@ "
	@$(COMPILER_EXECUTABLE) -o $(DIRNAME_BIN)/$@ \
		$(COMPILER_LIBS) \
		$(COMPILER_WARNING_FLAGS) \
		$(FILEPATHLIST_OPP_FT) \
			&& printf "$(SUCCESS)\n"

# Build obj binaries
$(DIRPATH_OBJ)/ft/%.opp: $(DIRNAME_SRC)/%.cpp
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) $< "
	@$(COMPILER_EXECUTABLE) -c $< -o $@ -DNAMESPACE="ft" \
		-I $(DIRNAME_INC) \
		$(COMPILER_WARNING_FLAGS) \
			&& printf "$(SUCCESS)\n"

# Build target
std_container: $(FILEPATHLIST_OPP_STD)
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) TARGET --> $@ "
	@$(COMPILER_EXECUTABLE) -o $(DIRNAME_BIN)/$@ \
		$(COMPILER_LIBS) \
		$(COMPILER_WARNING_FLAGS) \
		$(FILEPATHLIST_OPP_STD) \
			&& printf "$(SUCCESS)\n"

# Build obj binaries
$(DIRPATH_OBJ)/std/%.opp: $(DIRNAME_SRC)/%.cpp
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) $< "
	@$(COMPILER_EXECUTABLE) -c $< -o $@ -DNAMESPACE="std" \
		-I $(DIRNAME_INC) \
		$(COMPILER_WARNING_FLAGS) \
			&& printf "$(SUCCESS)\n"

# Build all targets
all: $(FILENAMELIST_TARGET)

## Run tester
test:
	@make -sC $(DIRNAME_TEST) test

# Remove objects
clean:
	@make -sC $(DIRNAME_TEST) clean
	@rm -rf $(DIRPATH_OBJ)

# Remove every built binary
fclean:
	@make -sC $(DIRNAME_TEST) fclean
	@rm -rf $(DIRNAME_BIN)

# Remove and rebuild everything
re: fclean all

.PHONY: all clean fclean re

.ONESHELL:

# #############################################################################
#
# Makefile misc
#
# #############################################################################

# Colors
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[1;34m
NC=\033[0m

# Colored messages
SUCCESS=$(GREEN)SUCCESS$(NC)
COMPILING=$(BLUE)COMPILING$(NC)

# #############################################################################

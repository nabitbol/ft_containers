# ---------------------------------------------------------------------------- #
#                                   variables                                  #
# ---------------------------------------------------------------------------- #

NAME			=	ft_containers_tester

CXX				=	clang++

CXXFLAGS		=	-Wall -Wextra -Werror 

LDLIBS			=

SRC_DIR			=	src/

VECTOR_SRC_DIR	=	src/vector/

STACK_SRC_DIR	=	src/stack/

PAIR_SRC_DIR	=	src/pair/

MAP_SRC_DIR		=	src/map/

LOG_FILE		=	fails.log

ADD_INC_DIR		=	ft_container/includes/

TEST_INC_DIR	=	./includes/

OBJ_DIR			=	obj/

VECTOR_OBJ_DIR	=	obj_vector/

STACK_OBJ_DIR	=	obj_stack/

PAIR_OBJ_DIR	=	obj_pair/

MAP_OBJ_DIR		=	obj_map/

OBJ				=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

VECTOR_OBJ		=	$(addprefix $(VECTOR_OBJ_DIR), $(VECTOR_SRC_FILES:.cpp=.o))

STACK_OBJ		=	$(addprefix $(STACK_OBJ_DIR), $(STACK_SRC_FILES:.cpp=.o))

PAIR_OBJ		=	$(addprefix $(PAIR_OBJ_DIR), $(PAIR_SRC_FILES:.cpp=.o))

MAP_OBJ			=	$(addprefix $(MAP_OBJ_DIR), $(MAP_SRC_FILES:.cpp=.o))

COUNT			=	0

# ------------------------- Multiple lines variables ------------------------- #

define BRAND
\n
# ----------------------------- Creating $(NAME) ----------------------------- #
\n
endef

define DONE

\033[0;32m
'########:::'#######::'##::: ##:'########:
 ##.... ##:'##.... ##: ###:: ##: ##.....::
 ##:::: ##: ##:::: ##: ####: ##: ##:::::::
 ##:::: ##: ##:::: ##: ## ## ##: ######:::
 ##:::: ##: ##:::: ##: ##. ####: ##...::::
 ##:::: ##: ##:::: ##: ##:. ###: ##:::::::
 ########::. #######:: ##::. ##: ########:
........::::.......:::..::::..::........::
\033[0m

endef

# ---------------------------------------------------------------------------- #
#                                    souces                                    #
# ---------------------------------------------------------------------------- #

SRC_FILES		= main.cpp \
			utils.cpp \
			register.class.cpp

VECTOR_SRC_FILES = add_vector_functions.cpp  \
				constructor.cpp \
				iterators.cpp \
				capacity.cpp \
				element_access.cpp \
				modifiers.cpp \
				non_members.cpp

STACK_SRC_FILES = add_stack_functions.cpp \
				constructor.cpp \

PAIR_SRC_FILES = add_pair_functions.cpp \
				constructor.cpp \

MAP_SRC_FILES = add_map_functions.cpp \
				constructor.cpp \

# ---------------------------------------------------------------------------- #
#                        dynamic variables using sources                       #
# ---------------------------------------------------------------------------- #

FILES_COUNT		:= $(words $(SRC_FILES) $(VECTOR_SRC_FILES) $(STACK_SRC_FILES) $(PAIR_SRC_FILES) $(MAP_SRC_FILES))

# ---------------------------------------------------------------------------- #
#                                    roules                                    #
# ---------------------------------------------------------------------------- #

export DONE
export BRAND

.DEFAULT_GOAL = help

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) -c -o $@ $< -I $(TEST_INC_DIR) -I $(ADD_INC_DIR) $(CXXFLAGS)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo [$(COUNT)/$(FILES_COUNT)] compiling $^ to $@

$(VECTOR_OBJ_DIR)%.o: $(VECTOR_SRC_DIR)%.cpp
	@mkdir -p $(VECTOR_OBJ_DIR)
	@$(CXX) -c -o $@ $< -I $(TEST_INC_DIR) -I $(ADD_INC_DIR) $(CXXFLAGS)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo [$(COUNT)/$(FILES_COUNT)] compiling $^ to $@

$(STACK_OBJ_DIR)%.o: $(STACK_SRC_DIR)%.cpp
	@mkdir -p $(STACK_OBJ_DIR)
	@$(CXX) -c -o $@ $< -I $(TEST_INC_DIR) -I $(ADD_INC_DIR) $(CXXFLAGS)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo [$(COUNT)/$(FILES_COUNT)] compiling $^ to $@

$(PAIR_OBJ_DIR)%.o: $(PAIR_SRC_DIR)%.cpp
	@mkdir -p $(PAIR_OBJ_DIR)
	@$(CXX) -c -o $@ $< -I $(TEST_INC_DIR) -I $(ADD_INC_DIR) $(CXXFLAGS)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo [$(COUNT)/$(FILES_COUNT)] compiling $^ to $@

$(MAP_OBJ_DIR)%.o: $(MAP_SRC_DIR)%.cpp
	@mkdir -p $(MAP_OBJ_DIR)
	@$(CXX) -c -o $@ $< -I $(TEST_INC_DIR) -I $(ADD_INC_DIR) $(CXXFLAGS)
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo [$(COUNT)/$(FILES_COUNT)] compiling $^ to $@


$(NAME): $(OBJ) $(VECTOR_OBJ) $(STACK_OBJ) $(PAIR_OBJ) $(MAP_OBJ)
	@$(CXX) -o $(NAME) $(OBJ) $(VECTOR_OBJ) $(STACK_OBJ) $(PAIR_OBJ) $(MAP_OBJ $(CXXFLAGS)

print_brand:
	@echo "$${BRAND}"

print_done:
	@echo "$${DONE}"

all: print_brand $(NAME) print_done ## Create the executable

# Command help shows all makefile roules (thanks to Grafikart for his tutorial https://grafikart.fr/tutoriels/makefile-953)
help:
	@grep -E '(^[a-zA-Z_-]+:.*?##.*$$)|(^##)' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-10s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

test: re ## Generate tester and run it
	@./$(NAME)

clean: ## Delete all obj
	@rm -rf $(LOG_FILE)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(VECTOR_OBJ_DIR)
	@rm -rf $(STACK_OBJ_DIR)
	@rm -rf $(PAIR_OBJ_DIR)
	@rm -rf $(MAP_OBJ_DIR)

fclean: clean ## Delete all obj and the executable
	@rm -f $(NAME)

re: fclean all ## Delete using fclean and recompile using all

.PHONY: all clean fclean re

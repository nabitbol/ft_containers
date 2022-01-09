# ---------------------------------------------------------------------------- #
#                                   variables                                  #
# ---------------------------------------------------------------------------- #

NAME			=	ft_containers_tester

CXX				=	clang++

CXXFLAGS		=	-Wall -Wextra -Werror 

LDLIBS			=

SRC_DIR			=	src/

VECTOR_SRC_DIR	=	src/vector/

LOG_FILE		=	fails.log

ADD_INC_DIR		=	ft_container/includes/

TEST_INC_DIR	=	./includes/

OBJ_DIR			=	obj/

VECTOR_OBJ_DIR	=	obj_vector/

OBJ				=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

VECTOR_OBJ		=	$(addprefix $(VECTOR_OBJ_DIR), $(VECTOR_SRC_FILES:.cpp=.o))

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

define CLEAN

\033[0;34m
:'######::'##:::::::'########::::'###::::'##::: ##:'########:'########::
'##... ##: ##::::::: ##.....::::'## ##::: ###:: ##: ##.....:: ##.... ##:
 ##:::..:: ##::::::: ##::::::::'##:. ##:: ####: ##: ##::::::: ##:::: ##:
 ##::::::: ##::::::: ######:::'##:::. ##: ## ## ##: ######::: ##:::: ##:
 ##::::::: ##::::::: ##...:::: #########: ##. ####: ##...:::: ##:::: ##:
 ##::: ##: ##::::::: ##::::::: ##.... ##: ##:. ###: ##::::::: ##:::: ##:
. ######:: ########: ########: ##:::: ##: ##::. ##: ########: ########::
:......:::........::........::..:::::..::..::::..::........::........:::
\033[0m

endef

# ---------------------------------------------------------------------------- #
#                                    souces                                    #
# ---------------------------------------------------------------------------- #

SRC_FILES		= main.cpp \
			utils.cpp \
			register.class.cpp

VECTOR_SRC_FILES = add_vector_functions.cpp  \
				iterators.cpp \
				capacity.cpp \
				element_access.cpp

# ---------------------------------------------------------------------------- #
#                        dynamic variables using sources                       #
# ---------------------------------------------------------------------------- #

FILES_COUNT		:= $(words $(SRC_FILES) $(VECTOR_SRC_FILES))

# ---------------------------------------------------------------------------- #
#                                    roules                                    #
# ---------------------------------------------------------------------------- #

export DONE
export BRAND
export CLEAN

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

$(NAME): $(OBJ) $(VECTOR_OBJ)
	@$(CXX) -o $(NAME) $(OBJ) $(VECTOR_OBJ) $(CXXFLAGS)

print_brand:
	@echo "$${BRAND}"

print_done:
	@echo "$${DONE}"

print_clean:
	@echo "$${CLEAN}"

all: print_brand $(NAME) print_done ## Create the executable

# Command help shows all makefile roules (thanks to Grafikart for his tutorial https://grafikart.fr/tutoriels/makefile-953)
help:
	@grep -E '(^[a-zA-Z_-]+:.*?##.*$$)|(^##)' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-10s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

test: re ## Generate tester and run it
	@./$(NAME)

clean: print_clean ## Delete all obj
	@rm -rf $(LOG_FILE)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(VECTOR_OBJ_DIR)

fclean: clean ## Delete all obj and the executable
	@rm -f $(NAME)

re: fclean all ## Delete using fclean and recompile using all

.PHONY: all clean fclean re

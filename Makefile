# ---------------------------------------------------------------------------- #
#                                   variables                                  #
# ---------------------------------------------------------------------------- #

NAME			=	ft_container

NAME1			=	std_container

CXX				=	clang++

CXXFLAGS		=	-Wall -Wextra -Werror #-std=c++98

LDLIBS			=

TEST_DIR		=	ft_containers_tester/

SRC_DIR			=	src/

INC_DIR			=	includes/

FT_OBJ_DIR		=	obj_ft/

STD_OBJ_DIR		=	obj_std/

FT_OBJ			=	$(addprefix $(FT_OBJ_DIR), $(SRC_FILES:.cpp=.o))

STD_OBJ			=	$(addprefix $(STD_OBJ_DIR), $(SRC_FILES:.cpp=.o))

COUNT			=	0

COUNT1			=	0

# ------------------------- Multiple lines variables ------------------------- #

define BRAND_FT
\n
# ----------------------------- Creating $(NAME) ----------------------------- #
\n
endef

define BRAND_STD
\n
# ----------------------------- Creating $(NAME1) ----------------------------- #
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

SRC_FILES		= main.cpp

# ---------------------------------------------------------------------------- #
#                        dynamic variables using sources                       #
# ---------------------------------------------------------------------------- #

FILES_COUNT		:= $(words $(SRC_FILES))

# ---------------------------------------------------------------------------- #
#                                    roules                                    #
# ---------------------------------------------------------------------------- #

export DONE
export BRAND_STD
export BRAND_FT
export CLEAN

.DEFAULT_GOAL = all

$(STD_OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "$${BRAND_STD}"
	@mkdir -p $(STD_OBJ_DIR)
	@$(CXX) -c -o $@ $< -I $(INC_DIR) $(CXXFLAGS) -DNAMESPACE="std"
	@$(eval COUNT1=$(shell echo $$(($(COUNT1)+1))))
	@echo [$(COUNT1)/$(FILES_COUNT)] compiling $^ to $@
	@echo "$${DONE}"

$(FT_OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "$${BRAND_FT}"
	@mkdir -p $(FT_OBJ_DIR)
	@$(CXX) -c -o $@ $< -I $(INC_DIR) $(CXXFLAGS) -DNAMESPACE="ft"
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo [$(COUNT)/$(FILES_COUNT)] compiling $^ to $@
	@echo "$${DONE}"

$(NAME1): $(STD_OBJ)
	@$(CXX) -o $(NAME1) $(STD_OBJ) $(CXXFLAGS)

$(NAME): $(FT_OBJ)
	@$(CXX) -o $(NAME) $(FT_OBJ) $(CXXFLAGS)

print_clean:
	@echo "$${CLEAN}"

all: $(NAME1) $(NAME) ## Create the executable

# Command help shows all makefile roules (thanks to Grafikart for his tutorial https://grafikart.fr/tutoriels/makefile-953)
help:
	@grep -E '(^[a-zA-Z_-]+:.*?##.*$$)|(^##)' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[32m%-10s\033[0m %s\n", $$1, $$2}' | sed -e 's/\[32m##/[33m/'

test:	## Run tests
	@make -sC $(TEST_DIR) test

clean: print_clean ## Delete all obj
	@make -sC $(TEST_DIR) clean
	@rm -rf $(STD_OBJ_DIR)
	@rm -rf $(FT_OBJ_DIR)

fclean: clean ## Delete all obj and the executable
	@make -sC $(TEST_DIR) fclean
	@rm -f $(NAME1)
	@rm -f $(NAME)

re: fclean all ## Delete using fclean and recompile using all

.PHONY: all clean fclean re


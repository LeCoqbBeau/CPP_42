NAME = megaphone

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = megaphone.cpp

OBJ_DIR = obj/
OBJ_NAME = $(SRC:.cpp=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:%.cpp
	@mkdir -p $(dir $@)
	@echo $< $@
	@c++ $(CPP_FLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F)

$(NAME): $(OBJ)
	@c++ $(CPP_FLAGS) -o $(NAME) $(OBJ)
	@echo "\033[1;32m Executable" $(NAME) "created"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31m Deleted all object files"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all

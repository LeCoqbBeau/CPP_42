NAME = PmergeMe

INCLUDES = inc/

CFLAGS = -I$(INCLUDES) -Wall -Werror -Wextra -std=c++98 -g
CC = c++

SRC_DIR = src/
SRC_NAME =	main.cpp \
			PmergeMe.cpp \

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F) "\033[0;0m"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[1;32m Executable" $(NAME) "created" "\033[0;0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31m Deleted all object files" "\033[0;0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)" "\033[0;0m"

all: $(NAME)

re: fclean all

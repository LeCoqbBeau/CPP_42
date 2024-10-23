NAME = intern

INCLUDES = inc/

CFLAGS = -I$(INCLUDES) -Wall -Werror -Wextra -g --std=c++98
CXX = c++

SRC_DIR = src/
SRC_NAME =	main.cpp \
			Bureaucrat.cpp \
			Intern.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.cpp=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F)


$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[1;32m Executable" $(NAME) "created"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31m Deleted all object files"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all

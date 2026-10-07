.PHONY: all clean fclean re val

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g #-Wno-shadow #-Wshadow 
VAL=valgrind --leak-check=full

OBJS_DIR=build
SRCS:=main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	Intern.cpp
OBJS:=$(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))
NAME=bureaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

val: $(NAME)
	$(VAL) ./$(NAME)

clean:
	rm -rf $(OBJS_DIR)
	rm -f *_home_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all




.PHONY: all clean fclean re

CC=c++
CFLAGS= -g -Wall -Wextra -Werror -std=c++98 -pedantic  
VAL=valgrind --leak-check=full

OBJS_DIR=build
SRCS:=main.cpp 
OBJS:=$(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))
NAME=easyfind

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

fclean: clean
	rm -f $(NAME)

re: fclean all

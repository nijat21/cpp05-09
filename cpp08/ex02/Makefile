.PHONY: all clean fclean re

CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98 -g  
VAL=valgrind --leak-check=full

OBJS_DIR=build
SRCS:=main.cpp Span.cpp
OBJS:=$(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))
NAME=span

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

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
SRCS = src/cub3d.c
OBJS_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)
NAME = cub3d

# Default rule
all: $(NAME)

# Linking the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compiling source files into object files
$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Clean object files
clean:
	rm -rf $(OBJS_DIR)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re

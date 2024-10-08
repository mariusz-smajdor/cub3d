# Variables
NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
LIBS = -lm

RAYS_SRCS = rays/calculate_ray_len.c rays/calculate_straight_ray_len.c rays/calculate_ray_0_90_len.c \
			rays/calculate_ray_90_180_len.c rays/calculate_ray_180_270_len.c rays/calculate_ray_270_360_len.c

SRCS_DIR = srcs
SRCS = cub3d.c utils.c $(RAYS_SRCS) 

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

# Default rule
all: $(NAME)

# Linking the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

# Compiling source files into object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re

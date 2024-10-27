# Variables
NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
LIBS = -lm -L libs/minilibx -lmlx -lXext -lX11

RAYS_SRCS = rays/caste_rays.c rays/caste_straight_ray.c rays/caste_0_90_angle_ray.c \
			rays/caste_90_180_angle_ray.c rays/caste_180_270_angle_ray.c rays/caste_270_360_angle_ray.c

SRCS_DIR = srcs
SRCS = cub3d.c utils.c $(RAYS_SRCS) 

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
MINILIBX_DIR = libs/minilibx

# Default rule
all: $(NAME) $(MINILIBX_DIR)

$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi

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

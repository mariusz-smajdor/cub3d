# Variables
NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes
LIBS = -lm -L libs/minilibx -lmlx -lXext -lX11

RAYS_SRCS = rays/cast_rays.c rays/cast_straight_ray.c rays/cast_0_90_angle_ray.c \
			rays/cast_90_180_angle_ray.c rays/cast_180_270_angle_ray.c rays/cast_270_360_angle_ray.c
INIT_SRCS = init/init_game.c
MAP_SRCS = map/parse_map.c map/parse_textures.c map/validate_map.c map/validate_utils.c
UTILS_SRCS = utils/check_extension.c utils/error_funcs.c utils/fix_spaces.c utils/free_utils.c \
			utils/len_to_space.c utils/ray_init.c utils/debug.c

SRCS_DIR = srcs
SRCS = cub3d.c $(RAYS_SRCS) $(INIT_SRCS) $(MAP_SRCS) $(UTILS_SRCS)

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
	make -C libs/my_lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) libs/my_lib/my_lib.a

# Compiling source files into object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	make clean -C libs/my_lib
	rm -f $(OBJS)

# Clean object files and the executable
fclean: clean
	make fclean -C libs/my_lib
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re

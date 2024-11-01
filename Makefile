# Variables
NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes

RAYS_SRCS = $(wildcard srcs/rays/caste_*.c)
SRCS = $(wildcard srcs/*.c) $(RAYS_SRCS)

OBJS = $(SRCS:.c=.o)

LIB_DIRS = libs/minilibx
LIBS = m mlx Xext X11
LDFLAGS_LIBS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(LIBS))

MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
MINILIBX_DIR = libs/minilibx

# Default rule
all: $(MINILIBX_DIR) $(LIBS) $(NAME) 

$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi

$(LIBS):
	$(foreach dir, $(LIB_DIRS), make -C $(dir);)
# Linking the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS_LIBS) -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re

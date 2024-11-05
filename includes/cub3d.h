#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h> // Can remove it later since we will use libft
# include "../libs/minilibx/mlx.h"
# include "../libs/my_lib/includes/get_next_line.h"
# include "../libs/my_lib/includes/libft.h"
# include "../libs/my_lib/includes/printf.h"

# define FOV 100
# define WIN_WIDTH 1440
# define WIN_HEIGHT 900

# define WALL_NORTH 1
# define WALL_EAST 2
# define WALL_SOUTH 3
# define WALL_WEST 4

typedef struct s_ray
{
	double	x;
	double	y;
	double	unit;
	double	hypotenuse;
	int 	wall_side;
	double	angle_radians;
	double	sin_angle;
	double	cos_angle;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	int 	angle;
}	t_player;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_txt
{
	t_img	*NO;
	t_img	*SO;
	t_img	*WE;
	t_img	*EA;
	int		F;
	int		C;
}	t_txt;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_ray		**rays;
	t_player	*player;
	t_txt		*txt;
}	t_game;

// RAYS
void	cast_rays(t_game *game);
void	cast_straight_ray(t_game *game, int ray_index, int angle);
void	cast_0_90_angle_ray(t_game *game, int ray_index, int angle);
void	cast_90_180_angle_ray(t_game *game, int ray_index, int angle);
void	cast_180_270_angle_ray(t_game *game, int ray_index, int angle);
void	cast_270_360_angle_ray(t_game *game, int ray_index, int angle);

void	initiate_ray(t_game *game, int ray_index, int angle);
void	cast_rays(t_game *game);

// INIT
void	init_game(t_game *game, char *map_path);
void	parse_map(t_game *game, char *path);
t_txt	*parse_textures(t_game *game, char **map, int *i);

// VALIDATE
bool	is_valid_char(char c);
int		count_rows(char **arr);
int		count_cols(char **arr);
bool	open_horizontal(char **map);
bool	open_vertical(char **map);
bool	is_valid(char **map);

// UTILS
bool	check_extension(char *file, char *ext);
void	print_error(char *msg);
char	*fix_spaces(char *str);
void	free_arr(char **arr);
void	free_txt(t_game *game, t_txt *txt);
int		len_to_space(char *s);

// DEBUG
void	debug_rays(t_ray **rays);
void	debug_player(t_player player);
void	debug_map(t_game game);

#endif

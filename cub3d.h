/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/30 14:06:13 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // printf to remove
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "mlx.h"

# define MOVE_SPEED 0.08
# define ROTATE_SPEED 0.05

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

typedef struct s_image {
    void    *ptr;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
	int		floor_rgb[3];
	int		ceil_rgb[3];
} t_image;

typedef struct wall
{
	short	side;
	short	start;
	short	end;
	short	height;
} t_wall;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	plane_offset;
	double	length;
	short	map_x;
	short	map_y;
	short	step_x;
	short	step_y;
} t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map;     
	t_player	*player;    
	t_ray		*ray;
	t_wall		*wall;
	t_image		*image;
} t_data;

void	parse_map(t_data *data);
void	start_game(t_data *data);
int		cast_rays(t_data *data);
void	free_map(char **map);

// draw
void	draw_wall(t_data *data, short x);
void 	draw_background(t_image *image);

// events
int		handle_key_events(int keycode, t_data *data);
int		close_game(t_data *data);

#endif
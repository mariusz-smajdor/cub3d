/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/28 17:05:48 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // printf to remove
# include <math.h>
# include <limits.h>
# include "libft.h"
# include "mlx.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

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
} t_data;

void	parse_map(t_data *data);
void	start_game(t_data *data);
int		cast_rays(t_data *data);
void	draw_wall(t_data *data, short x);

#endif
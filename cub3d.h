/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/28 15:19:03 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> // printf to remove
# include <math.h>
# include <limits.h>
# include "libft.h"
# include "mlx.h"

# define WIN_WIDTH 1940 //1280
# define WIN_HEIGHT 1280 //720

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	plane_offset;
	double	ray_length;
	double	map_x;
	double	map_y;
	short	step_x;
	short	step_y;
	short	wall_side;
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
	char		**map;     
	t_player	*player;    
	t_ray		*ray; 
} t_data;

void	parse_map(t_data *data);
void	cast_rays(t_data *data);

#endif
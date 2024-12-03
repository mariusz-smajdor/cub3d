/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:28:53 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/03 15:31:07 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_square(t_data *data, int x, int y, int color)
{
	int	scale;
	int	i;
	int	j;

	i = 0;
	scale = MINIMAP_SCALE;
	if (color == PLAYER_COLOR)
		scale *= 0.7;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			put_pixel(data->minimap, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	map_texture(t_data *data, t_image *texture)
{
	t_player	*player;
	t_ray		*ray;
	t_wall		*wall;
	float		wall_x;

	player = data->player;
	ray = data->ray;
	wall = data->wall;
	if (wall->side == NORTH || wall->side == SOUTH)
		wall_x = player->pos_x + ray->length * ray->dir_x;
	else
		wall_x = player->pos_y + ray->length * ray->dir_y;
	wall_x -= floor(wall_x);
	texture->x = (int)(wall_x * texture->width);
	if ((wall->side == SOUTH || wall->side == WEST) && texture->x > 0)
		texture->x = texture->width - texture->x - 1;
	texture->pos = (wall->start - WIN_HEIGHT
			/ 2 + wall->height / 2) * texture->step;
}

void	get_distance_fog(t_image *image, int x, int y, bool is_ceil)
{
	float	distance;

	distance = (float)y / WIN_HEIGHT;
	if (is_ceil)
	{
		distance = 1 - distance;
		put_pixel(image, x, y,
			((int)(image->ceil_rgb[0] * distance) << 16)
			| ((int)(image->ceil_rgb[1] * distance) << 8)
			| (int)(image->ceil_rgb[2] * distance));
	}
	else
		put_pixel(image, x, y,
			((int)(image->floor_rgb[0] * distance) << 16)
			| ((int)(image->floor_rgb[1] * distance) << 8)
			| (int)(image->floor_rgb[2] * distance));
}

void	init_wall(t_data *data)
{
	t_wall	*wall;

	wall = data->wall;
	wall->height = WIN_HEIGHT / data->ray->length;
	wall->start = (WIN_HEIGHT - wall->height) / 2;
	if (wall->height > WIN_HEIGHT)
		wall->start -= wall->start;
	wall->end = WIN_HEIGHT - wall->start;
}

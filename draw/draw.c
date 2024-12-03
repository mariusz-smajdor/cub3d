/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:03 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/03 14:58:41 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				put_square(data, j * MINIMAP_SCALE,
					i * MINIMAP_SCALE, 0x00786A6A);
			else
				put_square(data, j * MINIMAP_SCALE,
					i * MINIMAP_SCALE, 0x00DADAFC);
			j++;
		}
		i++;
	}
	put_square(data,
		data->player->pos_x * MINIMAP_SCALE - MINIMAP_SCALE / 3,
		data->player->pos_y * MINIMAP_SCALE - MINIMAP_SCALE / 3,
		PLAYER_COLOR);
}

void	draw_background(t_image *image)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				get_distance_fog(image, x, y, true);
			else
				get_distance_fog(image, x, y, false);
			x++;
		}
		y++;
	}
}

static t_image *get_wall_texture(t_data *data)
{
	if (data->wall->side == NORTH)
		return (&data->texture[0]);
	else if (data->wall->side == SOUTH)
		return (&data->texture[1]);
	else if (data->wall->side == WEST)
		return (&data->texture[2]);
	else if (data->wall->side == EAST)
		return (&data->texture[3]);
	return (NULL);
}

void	draw_wall(t_data *data, short x)
{
	t_image	*texture;
	int		color;

	texture = get_wall_texture(data);
	init_wall(data);
	texture->step = (float)texture->height / data->wall->height;
	map_texture(data, texture);
	while (data->wall->start < data->wall->end)
	{
		texture->y = (int)texture->pos & (texture->height - 1);
		texture->pos += texture->step;
		color = *(int *)(texture->addr
				+ (texture->y * texture->line_length
					+ texture->x * (texture->bits_per_pixel / 8)));
		put_pixel(data->image, x, data->wall->start, color);
		data->wall->start++;
	}
}

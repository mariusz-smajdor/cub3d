/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:03 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/30 15:01:36 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	get_distance_fog(t_image *image, int x, int y, bool is_ceil)
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

static void	init_wall(t_data *data)
{
	t_wall	*wall;

	wall = data->wall;
	wall->height = WIN_HEIGHT / data->ray->length;
	if (wall->height > WIN_HEIGHT)
		wall->height = WIN_HEIGHT;
	wall->start = (WIN_HEIGHT - wall->height) / 2;
	wall->end = WIN_HEIGHT - wall->start;
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

void	draw_wall(t_data *data, short x)
{
	int	color;

	color = 0x00A2CFFE;
	if (data->wall->side == 1)
		color = 0x006BB6FF;
	if (data->wall->side == 2)
		color = 0x003A8DFF;
	if (data->wall->side == 3)
		color = 0x001F4E8C;
	init_wall(data);
	while (data->wall->start < data->wall->end)
	{
		put_pixel(data->image, x, data->wall->start, color);
		data->wall->start++;
	}
}

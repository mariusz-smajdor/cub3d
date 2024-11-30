/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:03 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/30 17:58:05 by msmajdor         ###   ########.fr       */
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
		data->player->pos_x * MINIMAP_SCALE - MINIMAP_SCALE / 2,
		data->player->pos_y * MINIMAP_SCALE - MINIMAP_SCALE / 2,
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

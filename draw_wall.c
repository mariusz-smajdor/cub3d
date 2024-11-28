/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:03 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/28 16:50:07 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_wall(t_data *data, short x)
{
	init_wall(data);
	while (data->wall->start < data->wall->end)
	{
		mlx_pixel_put(data->mlx, data->mlx_win, x, data->wall->start, 0x0000AAFF);
		data->wall->start++;
	}
}

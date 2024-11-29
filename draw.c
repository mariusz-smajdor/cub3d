/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:12:03 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/29 15:48:15 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void put_pixel_to_image(t_image *image, int x, int y, int color)
{
    char *dst;

    if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
        return;
    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
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

void draw_background(t_image *image)
{
    int x, y;
    int *pixel;

    for (y = 0; y < WIN_HEIGHT; y++)
    {
        for (x = 0; x < WIN_WIDTH; x++)
        {
            pixel = (int *)(image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8)));
			if (y < WIN_HEIGHT / 2)
                *pixel = image->ceiling_color;
            else
                *pixel = image->floor_color;
        }
    }
}

void draw_wall(t_data *data, short x)
{
    init_wall(data);
    while (data->wall->start < data->wall->end)
    {
        put_pixel_to_image(data->image, x, data->wall->start, 0x0000AAFF);
        data->wall->start++;
    }
}

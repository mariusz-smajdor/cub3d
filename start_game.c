/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:04:16 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/03 14:56:21 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture(t_data *data, t_image *texture)
{
	texture->ptr = mlx_xpm_file_to_image(data->mlx,
			texture->path,
			&texture->width,
			&texture->height);
	texture->addr = mlx_get_data_addr(texture->ptr,
			&texture->bits_per_pixel,
			&texture->line_length,
			&texture->endian);
}

static void	load_image(t_data *data, t_image *image, int width, int height)
{
	image->ptr = mlx_new_image(data->mlx, width, height);
	image->addr = mlx_get_data_addr(image->ptr,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
}

static void	load_images(t_data *data)
{
	int	i;

	load_image(data, data->image, WIN_WIDTH, WIN_HEIGHT);
	load_image(data, data->minimap,
		data->map_width * MINIMAP_SCALE,
		data->map_height * MINIMAP_SCALE);
	i = 0;
	while (i < 4)
	{
		load_texture(data, &data->texture[i]);
		i++;
	}
}

static int	render(t_data *data)
{
	draw_background(data->image);
	draw_minimap(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->image->ptr,
		0, 0);
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->minimap->ptr,
		10, 10);
	return (0);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	load_images(data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key_events, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_events, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, close_game, data);
	mlx_loop(data->mlx);
}

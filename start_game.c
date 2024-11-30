/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:04:16 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/29 15:47:14 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_image(t_image *image, void *mlx)
{
	image->ptr = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	image->addr = mlx_get_data_addr(image->ptr,
			&image->bits_per_pixel,
			&image->line_length,
			&image->endian);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_image(data->image, data->mlx);
	mlx_loop_hook(data->mlx, cast_rays, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key_events, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, close_game, data);
	mlx_loop(data->mlx);
}

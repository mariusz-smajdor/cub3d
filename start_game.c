/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:04:16 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/30 15:52:59 by msmajdor         ###   ########.fr       */
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

static int	handle_mouse_events(int x, int y, t_data *data)
{
	t_player	*player;
	t_wall		*wall;

	player = data->player;
	wall = data->wall;
	if (wall->side == 'N' || wall->side == 'S')
	{
		if (x > WIN_WIDTH * 0.8)
			rotate(player, MOUSE_RIGHT);
		else if (x < WIN_WIDTH * 0.2)
			rotate(player, MOUSE_LEFT);
	}
	else
	{
		if (x > (WIN_WIDTH * 0.8))
			rotate(player, MOUSE_RIGHT);
		else if (x < WIN_WIDTH * 0.2)
			rotate(player, MOUSE_LEFT);
	}
	return (y);
}

static int	handle_key_events(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_game(data);
	else if (keycode == W_KEY
		|| keycode == S_KEY
		|| keycode == A_KEY
		|| keycode == D_KEY)
		move(data, keycode);
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		rotate(data->player, keycode);
	return (0);
}

void	start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	init_image(data->image, data->mlx);
	mlx_loop_hook(data->mlx, cast_rays, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key_events, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, handle_mouse_events, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, close_game, data);
	mlx_loop(data->mlx);
}

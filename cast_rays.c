/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:07:42 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/30 14:55:32 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	apply_dda(t_ray *ray, char **map, short *side)
{
	while (map[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_x > ray->side_y)
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			if (ray->dir_y < 0)
				*side = NORTH;
			else
				*side = SOUTH;
		}
		else
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			if (ray->dir_x < 0)
				*side = WEST;
			else
				*side = EAST;
		}
	}
}

static void	init_step(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_y;
	}
}

static void	init_delta(t_ray *ray)
{	
	if (ray->dir_x == 0)
		ray->delta_x = INT_MAX;
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_y = INT_MAX;
	else
		ray->delta_y = fabs(1 / ray->dir_y);
}

static void	init_ray(t_data *data, short x)
{
	t_player	*player;
	t_ray		*ray;

	player = data->player;
	ray = data->ray;
	ray->map_x = player->pos_x;
	ray->map_y = player->pos_y;
	ray->plane_offset = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->plane_offset;
	ray->dir_y = player->dir_y + player->plane_y * ray->plane_offset;
	init_delta(data->ray);
	init_step(data->ray, data->player);
}

int	cast_rays(t_data *data)
{
	t_ray	*ray;
	short	i;

	ray = data->ray;
	i = 0;
	draw_background(data->image);
	while (i < WIN_WIDTH)
	{
		init_ray(data, i);
		apply_dda(ray, data->map, &data->wall->side);
		if (data->wall->side > 1)
			ray->length = ray->side_x - ray->delta_x;
		else
			ray->length = ray->side_y - ray->delta_y;
		draw_wall(data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image->ptr, 0, 0);
	return (0);
}

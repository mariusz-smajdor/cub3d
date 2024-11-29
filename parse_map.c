/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:08:55 by msmajdor          #+#    #+#             */
/*   Updated: 2024/11/29 15:33:45 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *player, char direction)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	if (direction == 'N')
		player->dir_y = -1;
	else if (direction == 'S')
		player->dir_y = 1;
	else if (direction == 'W')
		player->dir_x = -1;
	else if (direction == 'E')
		player->dir_x = 1;
	if (direction == 'N')
		player->plane_x = 0.66;
	else if (direction == 'S')
		player->plane_x = -0.66;
	else if (direction == 'W')
		player->plane_y = 0.66;
	else if (direction == 'E')
		player->plane_y = -0.66;
}

static void	find_player(t_data *data)
{
	short	x;
	short	y;

	y = -1;
	while (++y, y < 6)
	{
		x = -1;
		while (++x, x < 6)
		{
			if (data->map[y][x] == 'N'
			|| data->map[y][x] == 'S'
			|| data->map[y][x] == 'W'
			|| data->map[y][x] == 'E')
			{
				data->player->pos_x = x + 0.5;
				data->player->pos_y = y + 0.5;
				init_player(data->player, data->map[y][x]);
			}
		}
	}
}

static void	init_data(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	data->ray = malloc(sizeof(t_ray));
	data->wall = malloc(sizeof(t_wall));
	data->image = malloc(sizeof(t_image));
	data->image->floor_color = 0x000000;
	data->image->ceiling_color = 0x00FF0000;
	find_player(data);
}

void	parse_map(t_data *data)
{	
	data->map = malloc(sizeof(char *) * 7);
	data->map[0] = ft_strdup("111111");
	data->map[1] = ft_strdup("100001");
	data->map[2] = ft_strdup("100S01");
	data->map[3] = ft_strdup("100001");
	data->map[4] = ft_strdup("100001");
	data->map[5] = ft_strdup("111111");
	data->map[6] = NULL;
	init_data(data);
}

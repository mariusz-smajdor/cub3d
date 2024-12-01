/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:08:55 by msmajdor          #+#    #+#             */
/*   Updated: 2024/12/01 17:32:40 by msmajdor         ###   ########.fr       */
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
		player->plane_x = 0.75;
	else if (direction == 'S')
		player->plane_x = -0.75;
	else if (direction == 'W')
		player->plane_y = 0.75;
	else if (direction == 'E')
		player->plane_y = -0.75;
}

static void	find_player(t_data *data)
{
	short	x;
	short	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
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
			x++;
		}
		y++;
	}
	data->map_width = x;
	data->map_height = y;
}

static void	init_data(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	data->ray = malloc(sizeof(t_ray));
	data->wall = malloc(sizeof(t_wall));
	data->image = malloc(sizeof(t_image));
	data->image->floor_rgb[0] = 0x59;
	data->image->floor_rgb[1] = 0x71;
	data->image->floor_rgb[2] = 0x81;
	data->image->ceil_rgb[0] = 0x87;
	data->image->ceil_rgb[1] = 0xCE;
	data->image->ceil_rgb[2] = 0xEB;
	data->minimap = malloc(sizeof(t_image));
	find_player(data);
}

void	parse_map(t_data *data)
{
	data->map = malloc(sizeof(char *) * 16);
	data->map[0] = ft_strdup("11111111111111111111");
	data->map[1] = ft_strdup("10000000001000000001");
	data->map[2] = ft_strdup("10111111001011111001");
	data->map[3] = ft_strdup("10100001000000001001");
	data->map[4] = ft_strdup("10101111101111101001");
	data->map[5] = ft_strdup("10100000000000100001");
	data->map[6] = ft_strdup("10101100S01110111101");
	data->map[7] = ft_strdup("10100000000000000001");
	data->map[8] = ft_strdup("10111110111111111001");
	data->map[9] = ft_strdup("10000010100000001001");
	data->map[10] = ft_strdup("10111010101111101001");
	data->map[11] = ft_strdup("10001000001000100001");
	data->map[12] = ft_strdup("10101111111110111101");
	data->map[13] = ft_strdup("10000000000000000001");
	data->map[14] = ft_strdup("11111111111111111111");
	data->map[15] = NULL;
	init_data(data);
}

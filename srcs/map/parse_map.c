/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:34:04 by mwiacek           #+#    #+#             */
/*   Updated: 2024/11/05 21:24:04 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*read_map(char *path)
{
	char	*line;
	char	*map;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Wrong map path\n");
	line = get_next_line(fd);
	if (!line)
		print_error("Map file is empty!\n");
	map = ft_strdup("");
	if (!map)
		return (NULL);
	while (line)
	{
		map = ft_strjoin_free(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (free(line), map);
}

static void	process_map(t_game *game, char *map)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split(map, '\n');
	game->txt = parse_textures(game, res, &i);
	if (!game->txt)
	{
		free_arr(res);
		print_error("Wrong textures\n");
	}
	game->map = res + i;
}

static void	fill_1s(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[i])
	{
		j = 0;
		k = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ' && map[i][j])
			j++;
		while (map[i][k] == ' ' && k > j)
			k--;
		while (map[i][j] && j < k)
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	parse_map(t_game *game, char *path)
{
	char	*map;

	if (!check_extension(path, ".cub"))
		print_error("Wrong map extension\n");
	map = read_map(path);
	if (!map)
		print_error("Reading map file failed\n");
	process_map(game, map);
	fill_1s(game->map);
	if (!is_valid(game->map))
		print_error("Map is invalid\n");
	free(map);
}

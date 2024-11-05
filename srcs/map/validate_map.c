/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:39:01 by mwiacek           #+#    #+#             */
/*   Updated: 2024/10/03 13:18:18 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	has_correct_symbols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (!map[i][j])
			return (false);
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	has_one_player(char **map)
{
	int		i;
	int		j;
	bool	is_player;

	i = 0;
	is_player = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'W')
			{
				if (is_player)
					return (false);
				is_player = true;
			}
			j++;
		}
		i++;
	}
	return (true);
}

static bool	has_borders(char **map)
{
	if (open_horizontal(map))
		return (false);
	if (open_vertical(map))
		return (false);
	return (true);
}

bool	is_valid(char **map)
{
	if (!has_correct_symbols(map))
		return (false);
	if (!has_one_player(map))
		return (false);
	if (!has_borders(map))
		return (false);
	return (true);
}

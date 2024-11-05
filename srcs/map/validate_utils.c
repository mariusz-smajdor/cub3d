/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:16:00 by mwiacek           #+#    #+#             */
/*   Updated: 2024/10/03 13:18:29 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N'
		|| c == 'E' || c == 'S' || c == 'W' || c == ' ');
}

int	count_rows(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	count_cols(char **arr)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			j++;
		}
		if (j > res)
			res = j;
		i++;
	}
	return (res);
}

bool	open_horizontal(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1' || map[i][len] != '1')
			return (true);
		i++;
	}
	return (false);
}

bool	open_vertical(char **map)
{
	int	f_row;
	int	l_row;
	int	cols;
	int	cur_col;

	cols = count_cols(map);
	cur_col = 0;
	while (cur_col < cols)
	{
		f_row = 0;
		l_row = count_rows(map) - 1;
		while (map[f_row][cur_col] == ' ')
			f_row++;
		if (map[f_row][cur_col] != '1')
			return (true);
		while ((map[l_row][cur_col] == ' ' || map[l_row][cur_col] == '\0')
			&& l_row >= 0)
			l_row--;
		if (map[l_row][cur_col] != '1')
			return (true);
		cur_col++;
	}
	return (false);
}

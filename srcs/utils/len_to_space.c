/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_to_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:40:06 by mwiacek           #+#    #+#             */
/*   Updated: 2024/09/18 14:45:51 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	len_to_space(char *s)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != ' ')
		count++;
	return (count);
}

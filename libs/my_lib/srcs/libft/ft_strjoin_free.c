/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:15:12 by mwiacek           #+#    #+#             */
/*   Updated: 2024/10/03 13:15:15 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
	{
		result = ft_strdup(s2);
		free(s2);
		return (result);
	}
	if (!s2)
		return (s1);
	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

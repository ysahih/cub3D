/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_one_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:19 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**ft_alloc(int i)
{
	char	**str;

	str = malloc((i + 1) * sizeof(char *));
	if (!str)
	{
		free(str);
		ft_error("allocation failed");
	}
	str[i] = 0;
	return (str);
}

char	**str_count_one(char **str, const char *s, char c)
{
	int	i ;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			s++;
		}
		while (*s && *s != c)
			s++;
		count = 0;
		while (*s && *s == c)
		{
			count++;
			if (count > 1)
				i++;
			s++;
		}
	}
	str = ft_alloc(i);
	return (str);
}

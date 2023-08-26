/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:52:15 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_player_pos_x(char **map2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'N' ||
			map2d[i][j] == 'E' ||
			map2d[i][j] == 'S' ||
			map2d[i][j] == 'W')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_player_pos_y(char **map2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map2d[i])
	{
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == 'N' ||
			map2d[i][j] == 'E' ||
			map2d[i][j] == 'S' ||
			map2d[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_player_angle1(int *i, int *j, char **map2d)
{
	while (map2d[*i])
	{
		*j = 0;
		while (map2d[*i][*j])
		{
			if (map2d[*i][*j] == 'N' ||
			map2d[*i][*j] == 'E' ||
			map2d[*i][*j] == 'S' ||
			map2d[*i][*j] == 'W')
				break ;
			(*j)++;
		}
		if (map2d[*i][*j] == 'N' ||
			map2d[*i][*j] == 'E' ||
			map2d[*i][*j] == 'S' ||
			map2d[*i][*j] == 'W')
			break ;
		(*i)++;
	}
}

float	ft_player_angle(char **map2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_player_angle1(&i, &j, map2d);
	if (map2d[i][j] == 'N')
		return (-M_PI / 2);
	if (map2d[i][j] == 'W')
		return (M_PI);
	if (map2d[i][j] == 'S')
		return (M_PI / 2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_to_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:16:06 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_transform_to_spaces(t_data *info, int i)
{
	int	x;

	x = 0;
	while (info->map2d[i][x])
	{
		info->map2d[i][x] = ' ';
		x++;
	}
}

void	ft_arguments_to_space(t_data *info)
{
	int	i;

	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "NO ", 3) == 0
			|| ft_strncmp(info->map2d[i], "SO ", 3) == 0
			|| ft_strncmp(info->map2d[i], "WE ", 3) == 0 
			|| ft_strncmp(info->map2d[i], "EA ", 3) == 0 
			|| ft_strncmp(info->map2d[i], "F ", 2) == 0
			|| ft_strncmp(info->map2d[i], "C ", 2) == 0)
			ft_transform_to_spaces(info, i);
		i++;
	}
}

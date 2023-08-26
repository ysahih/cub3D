/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:41:41 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	wall(t_data *info, int x, int y)
{
	x /= SIZE;
	y /= SIZE;
	if (x >= info->width || y >= info->height || x < 0 || y < 0)
		return (1);
	if (info->map2d[y][x] == '1')
		return (1);
	return (0);
}

int	wall_1(t_data *info, int x, int y)
{
	int	tmp_x;
	int	tmp_y;
	int	tmp_x_1 ;
	int	tmp_y_1 ;

	tmp_x = (x + 3) / SIZE;
	tmp_y = (y + 3) / SIZE;
	tmp_x_1 = (x - 3) / SIZE;
	tmp_y_1 = (y - 3) / SIZE;
	x /= SIZE;
	y /= SIZE;
	if ((x >= info->width || y >= info->height || x < 0 || y < 0)
		|| (tmp_x >= info->width || tmp_y >= info->height 
			|| tmp_x < 0 || tmp_y < 0))
		return (1);
	if (info->map2d[y][x] == '1' 
		|| info->map2d[tmp_y][tmp_x] == '1'
		|| info->map2d[tmp_y][x] == '1'
		|| info->map2d[y][tmp_x] == '1'
		|| info->map2d[tmp_y_1][tmp_x] == '1'
		|| info->map2d[tmp_y][tmp_x_1] == '1')
		return (1);
	return (0);
}

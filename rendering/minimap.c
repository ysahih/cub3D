/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:50:21 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/26 18:13:42 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	draw_direction(t_data *info)
{
	int	x;
	int	y;
	int	a;
	int	b;
	int	i;

	i = 0; 
	y = (M_HEIGHT / 2) + 20;
	x = (M_WIDTH / 2) + 30;
	while (i < 20)
	{
		a = i * cos(info->angle);
		b = i * sin(info->angle);
		mlx_put_pixel(info->mlx.image, x + a, y + b, 0xFFF);
		i++;
	}
}

void	draw_circle(t_data *info)
{
	int	center_x;
	int	center_y;
	int	radius;
	int	x;
	int	y;

	center_x = M_WIDTH / 2 + 30;
	center_y = M_HEIGHT / 2 + 20;
	radius = 5;
	x = center_x - radius;
	while (x <= center_x + radius)
	{
		y = center_y - radius;
		while (y <= center_y + radius)
		{
			if (pow((x - center_x), 2)
				+ pow((y - center_y), 2) <= pow(radius, 2))
				mlx_put_pixel(info->mlx.image, x, y, 0xFFF);
			y++;
		}
		x++;
	}
}

void	render_player(t_data *info)
{
	t_ray	*tmp;
	int		i;

	i = 0;
	draw_direction(info);
	draw_circle(info);
}

bool	check_walls(t_data *info, int i, int j)
{
	if (i > 0 && i / SIZE < info->height && j > 0 && j / SIZE < info->width)
		if (info->map2d[i / SIZE][j / SIZE] == '1')
			return (true);
	return (false);
}

void	render_minimap(t_data *info)
{
	int		i;
	int		j;
	int		x;
	int		y;

	y = M_HEIGHT;
	i = info->player_pos.y + (M_HEIGHT / 2);
	while (y > 0)
	{
		j = info->player_pos.x + (M_WIDTH / 2);
		x = M_WIDTH;
		while (x > 0)
		{
			if (check_walls(info, i, j))
				mlx_put_pixel(info->mlx.image, 30 + x, 20 + y, 0xFFFFF);
			j--;
			x--;
		}
		i--;
		y--;
	}
	render_player(info);
}

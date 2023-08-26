/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:41:34 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/26 17:42:02 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_ray	*first_hohit(t_data *info, float angle)
{
	t_ray	*ray;
	float	x;
	float	y;

	ray = malloc(sizeof(t_ray));
	if(!ray)
		ft_error("allocation failed");
	if (angle < -M_PI|| (angle >= 0 && angle <= M_PI))
	{
		y = floor(info->player_pos.y / SIZE) * SIZE + SIZE;
		x = down_first_x(info, angle, y);
	}
	if (angle >= M_PI || (angle < 0 && angle > -M_PI))
	{
		y = floor(info->player_pos.y / SIZE) * SIZE;
		x = up_first_x(info, angle, y);
	}
	ray->x = x;
	ray->y = y;
	return (ray);
}

t_ray	*horizontal(t_data *info, float angle)
{
	t_ray	*ray;
	float	x;
	float	y;

	ray = first_hohit(info, angle);
	while (wall(info, ray->x, ray->y) == 0
		&& ((angle >= 0 && angle <= M_PI) || angle < -M_PI))
	{
		ray->y += SIZE;
		ray->x = down_secnd_x(ray, angle);
	}
	while (wall(info, ray->x, ray->y - SIZE) == 0
		&& ((angle < 0 && angle >- M_PI) || angle > M_PI))
	{
		ray->y -= SIZE;
		ray->x = up_secnd_x(ray, angle);
	}
	ray->next = NULL;
	return (ray);
}
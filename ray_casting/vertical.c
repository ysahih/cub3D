/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:43:57 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/26 17:49:11 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_ray	*first_vehit(t_data *info, float angle)
{
	float	x;
	float	y;
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		ft_error("allocation failed");
	if (angle >= -M_PI / 2 && angle <= M_PI / 2)
	{
		x = floor(info->player_pos.x / SIZE) * SIZE + SIZE ;
		y = first_y(info, angle, x);
	}
	if (angle <= -M_PI || angle >= M_PI ||
		(angle >= -M_PI && angle < -M_PI / 2)
		|| (angle <= M_PI && angle > M_PI / 2))
	{
		x = floor(info->player_pos.x / SIZE) * SIZE;
		y = left_first_y(info, angle, x);
	}
	ray->x = x;
	ray->y = y;
	return (ray);
}

t_ray	*vertical(t_data *info, float angle)
{
	float	x;
	float	y;
	t_ray	*ray;

	ray = first_vehit(info, angle);
	while ((angle >= -M_PI / 2 && angle <= M_PI / 2)
		&& wall(info, ray->x, ray->y) == 0)
	{
		ray->x += SIZE;
		ray->y = left_secnd_y(ray, angle);
	}
	while ((angle <= -M_PI || angle >= M_PI
			|| (angle >= -M_PI && angle < -M_PI / 2)
			|| (angle <= M_PI && angle > M_PI / 2)) 
		&& wall(info, ray->x - SIZE, ray->y) == 0)
	{
		ray->x -= SIZE;
		ray->y = right_secnd_y(ray, angle);
	}
	ray->next = (NULL);
	return (ray);
}

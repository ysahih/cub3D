/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:42:46 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/26 17:43:06 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

float	down_first_x(t_data *info, float angle, float y)
{
	float	distance;
	float	o;

	distance = y - info->player_pos.y;
	o = distance / tan(angle);
	return (o + info->player_pos.x);
}

float	up_first_x(t_data *info, float angle, float y)
{
	float	distance;
	float	o;

	distance = (info->player_pos.y - y);
	o = distance / tan(angle);
	return (info->player_pos.x - o);
}

float	down_secnd_x(t_ray *ray, float angle)
{
	float	o;

	o = SIZE / tan(angle);
	return (ray->x + o);
}

float	up_secnd_x(t_ray *ray, float angle)
{
	float	o;

	o = SIZE / tan(angle);
	return (ray->x - o);
}
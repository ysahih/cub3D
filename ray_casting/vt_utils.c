/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:44:12 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

float	first_y(t_data *info, float angle, float x)
{
	float	distance;
	float	o;

	distance = x - info->player_pos.x;
	o = tan(angle) * distance;
	return (info->player_pos.y + o);
}

float	left_first_y(t_data *info, float angle, float x)
{
	float	distance;
	float	o;

	distance = info->player_pos.x - x;
	o = distance * tan(angle);
	return (info->player_pos.y - o);
}

float	left_secnd_y(t_ray *ray, float angle)
{
	float	o;

	o = SIZE * tan(angle);
	return (o + ray->y);
}

float	right_secnd_y(t_ray *ray, float angle)
{
	float	o;

	o = SIZE * tan(angle);
	return (ray->y - o);
}

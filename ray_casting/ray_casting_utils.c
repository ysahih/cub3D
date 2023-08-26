/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:48:10 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	add_rays(t_ray **rays, t_ray *new_ray)
{
	t_ray	*last_ray;

	if (!rays)
		return ;
	if (*rays == NULL)
	{
		*rays = new_ray;
		return ;
	}
	last_ray = ft_lstlast(*rays);
	last_ray->next = new_ray;
}

float	ft_distance(t_data *info, float x, float y)
{
	return (sqrt(pow(info->player_pos.x - x, 2)
			+ pow(info->player_pos.y - y, 2)));
}

void	collect_ray(t_data **info, t_ray *new_ray, float angle, char c)
{
	new_ray->distance = ft_distance(*info, new_ray->x, new_ray->y);
	new_ray->angle = angle;
	new_ray->type = c;
	add_rays((&(*info)->ray), new_ray);
}

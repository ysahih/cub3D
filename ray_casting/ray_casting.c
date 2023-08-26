/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:45:15 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/26 17:47:52 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

t_ray	*ft_lstlast(t_ray *rays)
{
	if (!rays)
		return (0);
	while (rays->next)
		rays = rays->next;
	return (rays);
}

void	cast_rays(t_data *info, float start_angle, float end_angle)
{
	t_ray	*horizontal_ray;
	t_ray	*vertical_ray;

	while (start_angle <= end_angle)
	{
		vertical_ray = vertical(info, start_angle);
		horizontal_ray = horizontal(info, start_angle);
		if (ft_distance(info, horizontal_ray->x, horizontal_ray->y)
			> ft_distance(info, vertical_ray->x, vertical_ray->y))
		{
			collect_ray(&info, vertical_ray, start_angle, 'V');
			free(horizontal_ray);
		}
		else
		{
			collect_ray(&info, horizontal_ray, start_angle, 'H');
			free(vertical_ray);
		}
		start_angle += 0.001;
	}
}

void	ray(void *inf)
{
	t_data	*info;
	float	start_angle;
	float	end_angle;

	info = inf;
	info->ray = NULL;
	start_angle = info->angle - (30 * M_PI / 180);
	end_angle = info->angle + (30 * M_PI / 180);
	cast_rays(info, start_angle, end_angle);
}

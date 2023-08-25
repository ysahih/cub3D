#include "../cube3d.h"

t_ray	*ft_lstlast(t_ray *rays)
{
	if (!rays)
		return (0);
	while (rays->next)
		rays = rays->next;
	return (rays);
}

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
	new_ray->distance = ft_distance(*info, new_ray->x, new_ray->y) ;
	new_ray->angle = angle;
	new_ray->type = c;
	add_rays((&(*info)->ray), new_ray);
}

void	ray(void *inf)
{
	t_data	*info;
	t_ray	*horizontal_ray;
	t_ray	*vertical_ray;
	float	start_angle;
	float	end_angle;

	info = inf;
	info->ray = NULL;
	start_angle = info->angle - (30 * M_PI / 180);
	end_angle = info->angle + (30 * M_PI / 180);
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

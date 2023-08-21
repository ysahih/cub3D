#include "cube3d.h"

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

float ft_distance(t_data *info, float x, float y)
{
	return(sqrt(pow(info->player_pos.x - x, 2) + pow(info->player_pos.y - y, 2)));
}

void	ray(void *inf)
{
	t_data	*info;
	t_ray	*horizontal_ray;
	t_ray	*vertical_ray;

	info = inf;
	float	start_angle = info->angle - (30 * M_PI / 180);
	float	end_angle = info->angle + (30 * M_PI / 180);
	// int i = 0
	info->ray = NULL;
	while (start_angle <= end_angle)
	{
		vertical_ray = vertical(info, start_angle);
		horizontal_ray = horizontal(info, start_angle);
		if(ft_distance(info, horizontal_ray->x, horizontal_ray->y) > ft_distance(info, vertical_ray->x, vertical_ray->y))
		{
			vertical_ray->distance = ft_distance(info, vertical_ray->x, vertical_ray->y) ;
			vertical_ray->angle = start_angle;
			vertical_ray->type = 'V';
			add_rays(&info->ray, vertical_ray);
			free(horizontal_ray);

		}
		else
		{
			horizontal_ray->distance = ft_distance(info, horizontal_ray->x, horizontal_ray->y);
			horizontal_ray->angle = start_angle;
			horizontal_ray->type = 'H';
			add_rays(&info->ray, horizontal_ray);
			free(vertical_ray);
		}
		start_angle += 0.001;
	}
}

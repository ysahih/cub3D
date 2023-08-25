#include "../cube3d.h"

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

t_ray	*first_vehit(t_data *info, float angle)
{
	float	x;
	float	y;
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if(!ray)
		ft_error();
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
	ray->next = NULL;
	return (ray);
}

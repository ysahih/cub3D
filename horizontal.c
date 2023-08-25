#include "cube3d.h"

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

float	down_secnd_x(t_ray *ray, float angle, float y)
{
	float	o;

	o = SIZE / tan(angle);
	return (ray->x + o);
}

float	up_secnd_x(t_ray *ray, float angle, float y)
{
	float	o;

	o = SIZE / tan(angle);
	return (ray->x - o);
}

t_ray	*first_hohit(t_data *info, float angle)
{
	t_ray	*ray;
	float	x;
	float	y;

	ray = malloc(sizeof(t_ray));
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
		ray->x = down_secnd_x(ray, angle, ray->y);
	}
	while (wall(info, ray->x, ray->y - SIZE) == 0
		&& ((angle < 0 && angle >- M_PI) || angle > M_PI))
	{
		ray->y -= SIZE;
		ray->x = up_secnd_x(ray, angle, ray->y);
	}
	ray->next = NULL;
	return (ray);
}
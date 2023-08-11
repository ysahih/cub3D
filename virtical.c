#include "cube3d.h"

float	first_y(t_data *info, float angel, float x)
{
	float	distance;

	distance = x - info->player_pos.x;
	float	opp;
	opp = tan(angel) * distance;
	return (info->player_pos.y + opp);
}

float	left_first_y(t_data *info, float angel, float x)
{
	float	distance;
	distance = info->player_pos.x - x;
	float	opp;
	opp = distance * tan(angel);
	return (info->player_pos.y - opp);
}

float left_secnd_y(t_ray *ray, float angel, float y)
{
	float o = 32 * tan(angel);
	return(o + ray->y);
}
float right_secnd_y(t_ray *ray, float angel, float y)
{
	float o = 32 * tan(angel);
	return(ray->y - o);
}


t_ray	*virtical(t_data *info, float angel)
{
	float	x = 0;;
	float	y;
	
	t_ray *ray = malloc(sizeof(t_ray));

	if (angel >= - M_PI / 2 && angel <= M_PI / 2)
	{

		x = floor(info->player_pos.x / 32) * 32 + 32;
		y = first_y(info, angel, x);
		ray->x = x;
		ray->y = y;
	}
	if (angel <= -M_PI || angel >= M_PI || (angel >= -M_PI && angel < -M_PI / 2) || (angel <= M_PI && angel > M_PI / 2))
	{
		// printf("%f\n", angel);
		// puts("here");
		x = floor(info->player_pos.x / 32) * 32;
		y = left_first_y(info, angel, x);
		ray->x = x;
		ray->y = y;
	}
	
	while((angel >= - M_PI / 2 && angel <= M_PI / 2) && wall(info, ray->x, ray->y) == 0)
	{
		ray->x += 32;
		ray->y = left_secnd_y(ray, angel, ray->x);
	}
	while(( angel <= -M_PI || angel >= M_PI ||  (angel >= -M_PI && angel < -M_PI / 2) || (angel <= M_PI && angel > M_PI / 2)) && wall(info, ray->x - 32, ray->y) == 0)
	{
		// write(2,"test\n", 5);
		ray->x -= 32;
		ray->y = right_secnd_y(ray, angel, ray->x);
	}
	ray->next = NULL;
	return (ray);

}
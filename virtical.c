#include "cube3d.h"

float	first_y(t_data *info, float x)
{
	// printf("%f\n", info->angel);
	float	distance;

	distance = x - info->player_pos.x;
	float	opp;
	opp = tan(info->angel) * distance;
	return (info->player_pos.y + opp);
}

float	left_first_y(t_data *info, float x)
{
	float	distance;

	distance = info->player_pos.x - x;
	float	opp;
	opp = distance * tan(info->angel);
	return (info->player_pos.y - opp);
}

void	virtical(t_data *info)
{
	float	x;
	float	y;

	if (info->angel > - M_PI / 2 && info->angel < M_PI / 2)
	{
		x = floor(info->player_pos.x / 32) * 32 + 32;
		y = first_y(info, x);
		info->ray.vx = x;
		info->ray.vy = y;
	}
	if ((info->angel > -M_PI && info->angel < -M_PI / 2) || (info->angel < M_PI && info->angel > M_PI / 2))
	{
		x = floor(info->player_pos.x / 32) * 32;
		y = left_first_y(info, x);
		info->ray.vx = x;
		info->ray.vy = y;
	}
	// printf("x = %f y = %f \n", info->ray.vx/32, info->ray.vy/32);
}
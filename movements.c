#include "cube3d.h"

void click_up_down(t_data *info)
{
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_UP))
	{
		if(wall_1(info, info->player_pos.x + (info->move_speed) * cos(info->angle),info->player_pos.y + (info->move_speed) * sin(info->angle)) == 0)
		{
			info->player_pos.x = info->player_pos.x + (info->move_speed) * cos(info->angle);
			info->player_pos.y = info->player_pos.y + (info->move_speed) * sin(info->angle);
		}
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_DOWN))
	{
		if(wall_1(info, info->player_pos.x - (info->move_speed) * cos(info->angle), info->player_pos.y - (info->move_speed) * sin(info->angle)) == 0)
		{
			info->player_pos.x = info->player_pos.x - (info->move_speed) * cos(info->angle);
			info->player_pos.y = info->player_pos.y - (info->move_speed) * sin(info->angle);
		}
	}
}

void click_left_right(t_data *info)
{
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_LEFT))
	{
		float angle;
		angle = fmod(info->angle , (2 * M_PI));
		if (angle < -M_PI)
			info->angle += 2 * M_PI;
		info->angle = info->angle - (info->rotate_speed);
	}

	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_RIGHT))
	{
		float angle;
		angle = fmod(info->angle , (2 * M_PI));
		if (angle > M_PI)
			info->angle -= 2 * M_PI;
		info->angle = info->angle + (info->rotate_speed);
	}
}

void click_a_d(t_data *info)
{
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_A))
	{
		if(wall_1(info, info->player_pos.x + (info->move_speed) * cos(info->angle - M_PI/2),info->player_pos.y + (info->move_speed) * sin(info->angle - M_PI/2)) == 0)
		{
			info->player_pos.x = info->player_pos.x + (info->move_speed) * cos(info->angle - M_PI/2);
			info->player_pos.y = info->player_pos.y + (info->move_speed) * sin(info->angle - M_PI/2);
		}
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_D))
	{
		if(wall_1(info, info->player_pos.x + (info->move_speed) * cos(info->angle + M_PI/2),info->player_pos.y + (info->move_speed) * sin(info->angle + M_PI/2)) == 0)
		{
			info->player_pos.x = info->player_pos.x + (info->move_speed) * cos(info->angle + M_PI/2);
			info->player_pos.y = info->player_pos.y + (info->move_speed) * sin(info->angle + M_PI/2);
		}
	}
}

void click(void *inf)
{
	t_data *info = inf;

	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_ESCAPE))
		exit(0);
	click_up_down(info);
	click_left_right(info);
	click_a_d(info);
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:39:36 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/25 18:38:43 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	click_up_down(t_data *info)
{
	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_W))
	{
		if (wall_1(info, info->player_pos.x + (info->move_speed)
				* cos(info->angle), info->player_pos.y
				+ (info->move_speed) * sin(info->angle)) == 0)
		{
			info->player_pos.x = info->player_pos.x
				+ (info->move_speed) * cos(info->angle);
			info->player_pos.y = info->player_pos.y
				+ (info->move_speed) * sin(info->angle);
		}
	}
	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_S))
	{
		if (wall_1(info, info->player_pos.x - (info->move_speed)
				* cos(info->angle), info->player_pos.y
				- (info->move_speed) * sin(info->angle)) == 0)
		{
			info->player_pos.x = info->player_pos.x
				- (info->move_speed) * cos(info->angle);
			info->player_pos.y = info->player_pos.y
				- (info->move_speed) * sin(info->angle);
		}
	}
}

void	click_left_right(t_data *info)
{
	float	angle;

	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_LEFT))
	{
		angle = fmod(info->angle, (2 * M_PI));
		if (angle < -M_PI)
			info->angle += 2 * M_PI;
		info->angle = info->angle - (info->rotate_speed);
	}
	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_RIGHT))
	{
		angle = fmod(info->angle, (2 * M_PI));
		if (angle > M_PI)
			info->angle -= 2 * M_PI;
		info->angle = info->angle + (info->rotate_speed);
	}
}

void	click_a_d(t_data *info)
{
	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_A))
	{
		if (wall_1(info, info->player_pos.x
				+ (info->move_speed) * cos(info->angle - M_PI / 2),
				info->player_pos.y + (info->move_speed)
				* sin(info->angle - M_PI / 2)) == 0)
		{
			info->player_pos.x = info->player_pos.x
				+ (info->move_speed) * cos(info->angle - M_PI / 2);
			info->player_pos.y = info->player_pos.y
				+ (info->move_speed) * sin(info->angle - M_PI / 2);
		}
	}
	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_D))
	{
		if (wall_1(info, info->player_pos.x + (info->move_speed)
				* cos(info->angle + M_PI / 2), info->player_pos.y
				+ (info->move_speed) * sin(info->angle + M_PI / 2)) == 0)
		{
			info->player_pos.x = info->player_pos.x
				+ (info->move_speed) * cos(info->angle + M_PI / 2);
			info->player_pos.y = info->player_pos.y
				+ (info->move_speed) * sin(info->angle + M_PI / 2);
		}
	}
}

void	mouse_click(t_data *info)
{
	int		x;
	int		y;
	float	angle;

	mlx_get_mouse_pos(info->mlx.mlx, &x, &y);
	mlx_set_mouse_pos(info->mlx.mlx, WIDTH / 2 ,HEIGHT / 2);
	if (x > WIDTH / 2)
	{
		angle = fmod(info->angle, (2 * M_PI));
		if (angle > M_PI)
			info->angle -= 2 * M_PI;
		info->angle = info->angle + (info->rotate_speed);
	}
	else if (x < WIDTH / 2)
	{
		angle = fmod(info->angle, (2 * M_PI));
		if (angle < -M_PI)
			info->angle += 2 * M_PI;
		info->angle = info->angle - (info->rotate_speed);
	}
}

void	click(void *inf)
{
	t_data	*info;

	info = inf;
	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_ESCAPE))
		exit(0);
	click_up_down(info);
	click_left_right(info);
	click_a_d(info);
	mouse_click(info);
}
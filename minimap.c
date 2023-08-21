#include "cube3d.h"

void	draw_direction(t_data *info, t_ray *ray)
{
	int		x = (M_WIDTH/2) + 30;
	int		y = (M_HEIGHT/2) + 20;
	int a;
	int b;
	float angle = ray->angle;
	for (int i = 0; i < 25; i++)
	{
		a = i * cos(angle);
		b = i * sin(angle);
		mlx_put_pixel(info->mlx.image, x + a, y + b, 0x87CEEB);
	}
}

void	render_player(t_data *info)
{
	t_ray *tmp = info->ray;
	int	i = 0;
	draw_direction(info, tmp);
	while (tmp->next)
	{
		if (i == RAYS / 2)
			draw_direction(info, tmp);
		tmp = tmp->next;
		i++;
	}
	draw_direction(info, tmp);
}

bool	check_walls(t_data *info, int i, int j)
{
	if (i > 0 && i/SIZE < info->height && j > 0 && j/SIZE < info->width)
		if (info->map2d[i/SIZE][j/SIZE] == '1')
			return (true);
	return (false);
}

void    render_minimap(t_data *info)
{

	int	start_x = 30;
	int	start_y = 20;
	
	t_pos p;
	p.y = info->player_pos.y;
	p.x = info->player_pos.x;

	int	i = p.y + (M_HEIGHT / 2);

	for (int y = M_HEIGHT; y> 0; y--)
	{
		int	j = p.x + (M_WIDTH / 2);
		for (int x=M_WIDTH;x> 0; x--)
		{
			if (check_walls(info, i, j))
				mlx_put_pixel(info->mlx.image, 30 + x, 20 + y, 0xFFFFFF);
			else
				mlx_put_pixel(info->mlx.image, 30 + x, 20 + y, 0xFF0000);
			j--;
		}
		i--;
	}
	render_player(info);
}
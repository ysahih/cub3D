#include "cube3d.h"

void	draw_direction(t_data *info, t_ray *ray)
{
	int		x = (M_WIDTH/2) + 30;
	int		y = (M_HEIGHT/2) + 20;
	int a;
	int b;
	float angle = ray->angle;
	for (int i = 0; i < 20; i++)
	{
		a = i * cos(angle);
		b = i * sin(angle);
		mlx_put_pixel(info->mlx.image, x + a, y + b, 0xFFF);
	}
}

void	draw_circle(t_data *info)
{
	int center_x = M_WIDTH / 2 + 30;
	int center_y = M_HEIGHT / 2 + 20;
	int		distance;
	int	i;
	int	j;
	float	angle = 0;

	int	radius = 5;

	int x, y;

    for (x = center_x - radius; x <= center_x + radius; x++) {
        for (y = center_y - radius; y <= center_y + radius; y++) {
            int dx = x - center_x;
            int dy = y - center_y;
            if (dx * dx + dy * dy <= radius * radius) {
				mlx_put_pixel(info->mlx.image, x, y, 0xFFF);
            }
        }
    }
}

void	render_player(t_data *info)
{
	t_ray *tmp = info->ray;
	int	i = 0;
	// draw_direction(info, tmp);
	while (tmp->next)
	{
		if (i == RAYS / 2)
			draw_direction(info, tmp);
		tmp = tmp->next;
		i++;
	}
	// draw_direction(info, tmp);
	draw_circle(info);
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
				mlx_put_pixel(info->mlx.image, 30 + x, 20 + y, 0xFFFFF);
			// else
			// 	mlx_put_pixel(info->mlx.image, 30 + x, 20 + y, 0xFF0000);
			j--;
		}
		i--;
	}
	render_player(info);
}
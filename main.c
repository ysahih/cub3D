 #include "cube3d.h"

t_data	open_window(char **map)
{
	t_data	info;

	info.mlx.mlx = mlx_init(WIDTH, HEIGHT, "test", NULL);
	info.mlx.image = mlx_new_image(info.mlx.mlx, WIDTH, HEIGHT);
	info.move_speed = 2;
	info.rotate_speed = 0.05;
	info.map2d = map;
	return (info);
}

void	get_data(t_data *info)
{
	info->player_pos.x = (ft_player_pos_x(info->map2d) * SIZE + SIZE/2);
	info->player_pos.y = (ft_player_pos_y(info->map2d) * SIZE + SIZE/2);
	info->angle = ft_player_angle(info->map2d);
	info->height = ft_len(info->map2d);
	info->width = ft_strlen(info->map2d[0]);
}

int main(int ac, char **av)
{
	t_data	info;
	char	**map;

	map = ft_read_map2d(av[1]);
	info = open_window(map);
	ft_parsing(&info);
	get_textures(&info);
	get_data(&info);
	display_map(&info);
}
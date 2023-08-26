/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:53:20 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/26 17:53:21 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "cube3d.h"

void	open_window(t_data *info , char **map)
{
	info->mlx.mlx = mlx_init(WIDTH, HEIGHT, "test", NULL);
	if (!info->mlx.mlx)
		ft_error("mlx init failed");
	info->mlx.image = mlx_new_image(info->mlx.mlx, WIDTH, HEIGHT);
	if (!info->mlx.image)
		ft_error("mlx new image failed");
	info->move_speed = 2;
	info->rotate_speed = 0.05;
	info->map2d = map;
}

void	get_data(t_data *info)
{
	info->player_pos.x = (ft_player_pos_x(info->map2d) * SIZE + SIZE/2);
	info->player_pos.y = (ft_player_pos_y(info->map2d) * SIZE + SIZE/2);
	info->angle = ft_player_angle(info->map2d);
	info->height = ft_len(info->map2d);
	info->width = ft_strlen(info->map2d[0]);
}

void ft_free(t_data *info) {
    int i = 0;
    
    // Free the map2d array
    while (info->map2d && info->map2d[i]) {
        free(info->map2d[i]);
        i++;
    }
    free(info->map2d);
    info->map2d = NULL; // Set the pointer to NULL
    
    // Reset i
    i = 0;
    
    // Free the map2d1 array
    while (info->map2d1 && info->map2d1[i]) {
        free(info->map2d1[i]);
        i++;
    }
    free(info->map2d1);
    info->map2d1 = NULL; // Set the pointer to NULL
}

// void f_()
// {
// 	system("leaks a.out");
// }

int main(int ac, char **av)
{
	t_data	info;
	char	**map;

	map = ft_read_map2d(av[1],&info);
	open_window(&info, map);
	ft_parsing(&info);
	get_textures(&info);
	get_data(&info);
	display_map(&info);
}

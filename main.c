 #include "cube3d.h"



static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_word(const char *s, char c)
{
	char	*str;
	int		len;

	len = word_len(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (0);
	}
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}

static char	**str_count(char **str, const char *s, char c)
{
	int	i ;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			s++;
		}
		while (*s && *s != c)
		s++;
		while (*s && *s == c)
		{
			s++;
		}
	}
	str = malloc((i + 1) * sizeof(char *));
	if (!str)
	{
		free(str);
		return (0);
	}
	str[i] = 0;
	return (str);
}

char **ft_read_map2d(char *av)
{
    char	**map2d;
	char	*map;
	char	*str;
	int		fd;

	int	i = 0;
	int j = 0;
	fd = open((const char *)av, O_RDONLY);
	if (fd == -1)
	{
		write(1, "cound not find the map\n", 23);
		exit(-1);
	}
	str = NULL;
	map = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		i++;
		map = ft_strjoin(map, str);
		free(str);
	}
	map2d = ft_split(map, '\n');
	j = ft_strlen(map2d[0]);
	free(map);

	return (map2d);
}

int ft_heightlen(char **map2d)
{
	int i, j, max;
	i = j = max = 0;
	while(map2d[i])
	{
		if(ft_strlen(map2d[i]) > max)
		 max = ft_strlen(map2d[i]);
		i++;
	}
	return max;
}


// void draw_player(t_data *info, int color, int p_or_der)
// {
// 	int x, y;
// 	x = y = 0;
// 	while(x < 4)
// 	{
// 		y = 0;
// 		while(y < 4)
// 		{
// 			if(p_or_der == 1)
// 				mlx_put_pixel(info->mlx.image, (info->player_pos.x + x)* MINI, (info->player_pos.y + y) * MINI, color);
// 			// else
// 			// 	mlx_put_pixel(info->mlx.image, info->der_pos.x + x, info->der_pos.y + y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }



int wall(t_data *info, int x, int y)
{
	
	x /= SIZE;
	y /= SIZE;
	if (x >= info->width || y >= info->height || x < 0 || y < 0)
		return (1);
	
	if(info->map2d[y][x] == '1')
			return 1;
	return 0;
}


void click(void *inf)
{
	t_data *info = inf;
	int	new_x;
	int	new_y;

	if (mlx_is_key_down(info->mlx.mlx, MLX_KEY_ESCAPE))
		exit(0);
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_UP))
	{
		if(wall(info, info->player_pos.x + (info->move_speed) * cos(info->angle),info->player_pos.y + (info->move_speed) * sin(info->angle)) == 0)
		{
			info->player_pos.x = info->player_pos.x + (info->move_speed) * cos(info->angle);
			info->player_pos.y = info->player_pos.y + (info->move_speed) * sin(info->angle);
		}
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_A))
	{
		if(wall(info, info->player_pos.x + (info->move_speed) * cos(info->angle - M_PI/2),info->player_pos.y + (info->move_speed) * sin(info->angle - M_PI/2)) == 0)
		{
			info->player_pos.x = info->player_pos.x + (info->move_speed) * cos(info->angle - M_PI/2);
			info->player_pos.y = info->player_pos.y + (info->move_speed) * sin(info->angle - M_PI/2);
		}
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_D))
	{
		if(wall(info, info->player_pos.x + (info->move_speed) * cos(info->angle + M_PI/2),info->player_pos.y + (info->move_speed) * sin(info->angle + M_PI/2)) == 0)
		{
			info->player_pos.x = info->player_pos.x + (info->move_speed) * cos(info->angle + M_PI/2);
			info->player_pos.y = info->player_pos.y + (info->move_speed) * sin(info->angle + M_PI/2);
		}
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_DOWN))
	{
		if(wall(info, info->player_pos.x - (info->move_speed) * cos(info->angle), info->player_pos.y - (info->move_speed) * sin(info->angle)) == 0)
		{
			info->player_pos.x = info->player_pos.x - (info->move_speed) * cos(info->angle);
			info->player_pos.y = info->player_pos.y - (info->move_speed) * sin(info->angle);
		}
	}

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

void ft_mlx_put_block(t_data *info ,int i ,int j, int color)
{
	int a = 0;
	int b = 0;
	while(a < SIZE)
	{
		b = 0;
		while(b < SIZE)
		{
			// if(info->map2d[i][j] == '1')
				mlx_put_pixel(info->mlx.image, (j * SIZE) + a, (i * SIZE) + b, color);
			// else
			// 	mlx_put_pixel(info->mlx.image, (j * SIZE) + a, (i * SIZE) + b, 0x000fFF);
			b++;
		}
		a++;
	}
}




void rerender(void *inf)
{
	t_data *info = inf;
	t_ray *ray;
	float x = 0;
	int y = 0;
	// int k = HEIGHT / 2;

	unsigned int	c_color = RGB(info->sources.c_r, info->sources.c_g, info->sources.c_b);
	unsigned int	f_color = RGB(info->sources.f_r, info->sources.f_g, info->sources.f_b);
	while(y < HEIGHT / 2)
	{
		x = 0;
		while(x < WIDTH)
		{
			mlx_put_pixel(info->mlx.image, x, y, c_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			mlx_put_pixel(info->mlx.image, x, y, f_color);
			x++;
		}
		y++;
	}
	x = 0;
	t_ray *tmp = info->ray;
	while (tmp)
	{
		float block = WIDTH / RAYS;
		draw_walls(tmp, info, x * block);
		tmp = tmp->next;
		x++;
	}
	render_minimap(info);
}

int ft_player_pos_x(char **map2d)
{
	int i = 0;
	int j = 0;

	while(map2d[i])
	{
		j = 0;
		while(map2d[i][j])
		{
			if(map2d[i][j] == 'N' ||
			map2d[i][j] == 'E' ||
			map2d[i][j] == 'S'||
			map2d[i][j] == 'W')
				return j;
			j++;
		}
		i++;
	}
	return 0;
}
int ft_player_pos_y(char **map2d)
{
	int i = 0;
	int j = 0;

	while(map2d[i])
	{
		j = 0;
		while(map2d[i][j])
		{
			if(map2d[i][j] == 'N' ||
			map2d[i][j] == 'E' ||
			map2d[i][j] == 'S'||
			map2d[i][j] == 'W')
				return i;
			j++;
		}
		i++;
	}
	return 0;
}

float ft_player_angle(char **map2d)
{
	int i = 0;
	int j = 0;
	while(map2d[i])
	{
		j = 0;
		while(map2d[i][j])
		{
			if(map2d[i][j] == 'N' ||
			map2d[i][j] == 'E' ||
			map2d[i][j] == 'S'||
			map2d[i][j] == 'W')
				break;
			j++;
		}
		if(map2d[i][j] == 'N' ||
			map2d[i][j] == 'E' ||
			map2d[i][j] == 'S'||
			map2d[i][j] == 'W')
				break;
		i++;
	}

	if(map2d[i][j] == 'N')
		return (-M_PI / 2);
	if(map2d[i][j] == 'W')
		return (M_PI);
	if(map2d[i][j] == 'S')
		return (-3 * M_PI / 2);
	return 0;
}



void display_map(t_data *info)
{
	mlx_image_to_window(info->mlx.mlx, info->mlx.image, 0, 0);
	mlx_loop_hook(info->mlx.mlx, click, info);
	mlx_loop_hook(info->mlx.mlx, ray, info);
	mlx_loop_hook(info->mlx.mlx, rerender, info);
	mlx_loop(info->mlx.mlx);
}

t_data	get_info(char **map)
{

	t_data info;

	info.mlx.mlx = mlx_init(WIDTH, HEIGHT, "test", NULL);
	info.mlx.image = mlx_new_image(info.mlx.mlx, WIDTH, HEIGHT);
	info.move_speed = 2;
	info.rotate_speed = 0.05;

	info.map2d = map;

	return info;
}

mlx_image_t	*load_png(t_data *info, char *s)
{
	mlx_texture_t	*txt;
	mlx_image_t	*image;

	txt = mlx_load_png(s);
	image = mlx_texture_to_image(info->mlx.mlx, txt);
	return (image);
}

void	get_textures(t_data *info)
{
	info->mlx.ea_image = load_png(info, info->sources.ea);
	info->mlx.so_image = load_png(info, info->sources.so);
	info->mlx.we_image = load_png(info, info->sources.we);
	info->mlx.no_image = load_png(info, info->sources.no);
}

int main (int ac, char **av)
{
	t_data	info;
	t_data	info_tmp;
    char	**map2d;
    char	**map2d_tmp;
	int		height;
	int		width;

    map2d = ft_read_map2d(av[1]);
	info = get_info(map2d);
	ft_parsing(&info);
	get_textures(&info);
	info.player_pos.x = (ft_player_pos_x(info.map2d) * SIZE + SIZE/2) ;
	info.player_pos.y = (ft_player_pos_y(info.map2d) * SIZE + SIZE/2) ;
	info.angle = ft_player_angle(info.map2d);
	info.height = ft_len(info.map2d);
	info.width = ft_strlen(info.map2d[0]);
	// printf("-%s-\n", info.sources.no );
	display_map(&info);
    
}
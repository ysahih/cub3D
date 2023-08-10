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

char **ft_read_map2d(char *av, int	*height, int *width)
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
	// printf("%d, %d\n", i, j);
	*height = i;
	*width = j;
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



// void ft_draw_32(char **map2d, t_data *info, int i, int j, int color)
// {
// 	if(color == 0)
// 		mlx_put_image_to_window(info->mlx.mlx, info->mlx.mlx_win, info->mlx.white,  j * SIZE,i * SIZE);
// 	else
// 		mlx_put_image_to_window(info->mlx.mlx, info->mlx.mlx_win, info->mlx.darkBlue,  j * SIZE, i * SIZE);

// }

// void ft_draw_p(char **map2d, void *mlx, void *mlx_win, int i, int j, int color)
// {
// 	int x, y;
// 	x = y = 0;
// 	while(x < 4)
// 	{
// 		y = 0;
// 		while(y < 4)
// 		{
// 			mlx_pixel_put(mlx, mlx_win, j * SIZE + x + 15, i * SIZE + y + 15, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void draw_player(t_data *info, int color, int p_or_der)
{
	int x, y;
	x = y = 0;
	while(x < 4)
	{
		y = 0;
		while(y < 4)
		{
			if(p_or_der == 1)
				mlx_put_pixel(info->mlx.image, info->player_pos.x + x, info->player_pos.y + y, color);
			else
				mlx_put_pixel(info->mlx.image, info->der_pos.x + x, info->der_pos.y + y, color);
			y++;
		}
		x++;
	}
}



int wall(t_data *info, int x, int y)
{
	// printf("(i = %d, j = %d)\n", y/SIZE,x/SIZE);
	
	x /= SIZE;
	y /= SIZE;
	if (x >= info->width || y >= info->height || x < 0 || y < 0)
		return (1);
	
	if(info->map2d[y][x] == '1')
			return 1;
	return 0;
}
int wall_up(t_data *info, int x, int y)
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
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_UP))
	{
		if(wall(info, info->player_pos.x + (info->move_speed) * cos(info->angel),info->player_pos.y + (info->move_speed) * sin(info->angel)) == 0)
		{
			info->player_pos.x = info->player_pos.x + (info->move_speed) * cos(info->angel);
			info->player_pos.y = info->player_pos.y + (info->move_speed) * sin(info->angel);
		}
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_DOWN))
	{
		if(wall(info, info->player_pos.x - (info->move_speed) * cos(info->angel), info->player_pos.y - (info->move_speed) * sin(info->angel)) == 0)
		{
			info->player_pos.x = info->player_pos.x - (info->move_speed) * cos(info->angel);
			info->player_pos.y = info->player_pos.y - (info->move_speed) * sin(info->angel);
		}
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_LEFT))
	{
		float angel;
		angel = fmod(info->angel , (2 * M_PI));
		if (angel < -M_PI)
			info->angel += 2 * M_PI;
		info->angel = info->angel - (info->rotate_speed);


		// // info->angel = fmod(info->angel , (2 * M_PI));
		// if(info->angel > M_PI)
		// 	info->angel = info->angel - M_PI;
		// if(info->angel <  M_PI)
		// 	info->angel = info->angel +  M_PI;
	}
	if(mlx_is_key_down(info->mlx.mlx, MLX_KEY_RIGHT))
	{
		float angel;
		angel = fmod(info->angel , (2 * M_PI));
		if (angel > M_PI)
			info->angel -= 2 * M_PI;
		info->angel = info->angel + (info->rotate_speed);
	}
}

void ft_mlx_put_block(t_data *info ,int i ,int j)
{
	int a = 0;
	int b = 0;
	while(a < 32)
	{
		b = 0;
		while(b < 32)
		{
			if(info->map2d[i][j] == '1')
				mlx_put_pixel(info->mlx.image, (j * 32) + a, (i * 32) + b, 0xFF00f0);
			else
				mlx_put_pixel(info->mlx.image, (j * 32) + a, (i * 32) + b, 0x000fFF);
			b++;
		}
		a++;
	}
}

// float	get_ray_distance(t_data *info)
// {
// 	float a = (info->ray.x - info->player_pos.x) * (info->ray.x - info->player_pos.x);
// 	float b = (info->ray.y - info->player_pos.y) * (info->ray.y - info->player_pos.y);
// 	return(sqrtf(a + b));
// }




// void	draw_ray(t_data *info)
// {
// 	int	distance = fabs(get_ray_distance(info));
// 	printf("%d\n", (distance));
// 	// float	x = info->player_pos.x;
// 	// float	y = info->player_pos.y;

// 	// for (int i = 0; i < distance; i++)
// 	// {
// 	// 	x += fabs(i * cos(info->angel));
// 	// 	y += fabs(i * sin(info->angel));
// 	// 	// printf("%f-%f\n", x/SIZE, y/SIZE);
// 	// 	mlx_put_pixel(info->mlx.image, x, y, 0xFFFFF);
// 	// }
// }

void rerender(void *inf)
{
	t_data *info = inf;
	int i = 0;
	int j = 0;

	while(info->map2d[i])
	{
		j = 0;
		while(info->map2d[i][j])
		{
			ft_mlx_put_block(info, i, j);
			j++;
		}
		i++;
	}
	info->der_pos.x = info->player_pos.x + 20 * cos(info->angel);
	info->der_pos.y = info->player_pos.y + 20 * sin(info->angel);
	draw_player(info, 0x99FF90, 1);
	draw_player(info, 0xFA8072, 0);

	mlx_put_pixel(info->mlx.image, info->ray.x, info->ray.y, 0x99FF90);
	mlx_put_pixel(info->mlx.image, info->ray.x + 1, info->ray.y, 0x99FF90);
	mlx_put_pixel(info->mlx.image, info->ray.x + 2, info->ray.y, 0x99FF90);
	mlx_put_pixel(info->mlx.image, info->ray.x, info->ray.y + 1, 0x99FF90);
	mlx_put_pixel(info->mlx.image, info->ray.x, info->ray.y + 2, 0x99FF90);
	// draw_ray(info->player_pos.x, info->player_pos.y, info->ray.x, info->ray.y, info);
	//temporory algorithm to draw one ray
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

float ft_player_angel(char **map2d)
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

float	down_first_x(t_data *info, float y)
{
	float	distance;

	printf("%f\n", info->angel);
	distance = y - info->player_pos.y;
	float o = distance / tan(info->angel);
	return (o + info->player_pos.x);

	return (0);
}

float	up_first_x(t_data *info, float y)
{
	float	distance;

	printf("%f\n", info->angel);

	distance = (info->player_pos.y - y);
	float o = distance / tan(info->angel);
		return (info->player_pos.x - o);
}

float	down_secnd_x(t_data *info, float y)
{
	float o = 32 / tan(info->angel);
	return(o + info->ray.hx);
}

float up_secnd_x(t_data *info, float y)
{
	float o = 32 / tan(info->angel);
	printf(" o = %f\n", o);
	return(info->ray.hx - o);
}

float ft_distance(t_data *info, float x, float y)
{
	return(sqrt(pow(info->player_pos.x - x, 2) + pow(info->player_pos.y - y, 2)));
}
/*         waaaaaaaaaaa      */
void ray(void *inf)
{
	t_data *info = inf;
	float	x;
	float	y;

	virtical(info);
	if ((info->angel > 0 && info->angel < M_PI))
	{
		y = floor(info->player_pos.y / 32) * 32 + 32;
		x = down_first_x(info, y);
		info->ray.hx = x;
		info->ray.hy = y;
	}
	if ((info->angel < 0 && info->angel > -M_PI))
	{
		y = floor(info->player_pos.y / 32) * 32;
		x = up_first_x(info, y);
		info->ray.hx = x;
		info->ray.hy = y;
	}

	printf("x = %d y = %f \n", (int)(info->ray.hx/32), info->ray.hy/32);
	
	while(wall(info, info->ray.hx, info->ray.hy) == 0 && info->angel > 0 && info->angel < M_PI)
	{
			info->ray.hy += 32;
			info->ray.hx = down_secnd_x(info, info->ray.hy);
	}
	while(wall(info, info->ray.hx, info->ray.hy - 32) == 0 && info->angel < 0 && info->angel >- M_PI)
	{
			info->ray.hy -= 32;
			info->ray.hx = up_secnd_x(info, info->ray.hy);
	}

	if(ft_distance(info, info->ray.hx, info->ray.hy) > ft_distance(info, info->ray.vx, info->ray.vy))
	{
		info->ray.x = info->ray.vx;
		info->ray.y = info->ray.vy;
	}
	else
	{
		info->ray.x = info->ray.hx;
		info->ray.y = info->ray.hy;
	}

}

// void ft_first_poit(t_data *info, t_ray *first_point)
// {
// 	first_point->y = floor(info->player_pos.y / 32) * 32 + 32;
// 	float adjusent = first_point->hy - info->player_pos.y;
// 	float opposite =  adjusent /tan(info->angel) ;
// 	first_point->x = info->player_pos.x + opposite;
// 	mlx_put_pixel(info->mlx.image,first_point->hx, first_point->hy, 0xFFFF6B);
// }



int check_y(int y,int x, char **map2d)
{
	int i = 0;
	while(map2d[y][i])
		i++;
	if(i >= x)
	{
		return 1;
	}
	return 0;
}


int there_is_wall(t_data *info, t_ray first_point)
{
	int x = first_point.hx / 32;
	int y = first_point.hx / 32;
	printf("xx = %d y = %d\n", x, y);

	if(info->map2d[x][y] == '1')
		return 0;
	else
		return 0;
	return 1;
}

void display_map(t_data *info)
{

	info->mlx.mlx = mlx_init(1200, 1000, "test", NULL);
	info->mlx.image = mlx_new_image(info->mlx.mlx, 1200, 1000);
	mlx_image_to_window(info->mlx.mlx, info->mlx.image, 0, 0);
	mlx_loop_hook(info->mlx.mlx, click, info);
	mlx_loop_hook(info->mlx.mlx, rerender, info);
	mlx_loop_hook(info->mlx.mlx, ray, info);
	mlx_loop(info->mlx.mlx);
	mlx_terminate(info->mlx.mlx);
}

t_data	get_info(char **map, int height, int width)
{
	t_data info;

	info.move_speed = 1;
	info.rotate_speed = 0.06;
	info.player_pos.x = ft_player_pos_x(map) * SIZE + 15;
	info.player_pos.y = ft_player_pos_y(map) * SIZE + 15;
	info.angel = ft_player_angel(map);
	info.width = width;
	info.height = height;
	info.map2d = map;

	return info;
}

int main (int ac, char **av)
{
    char **map2d;
	t_data	*info;
	int		height;
	int		width;


    map2d = ft_read_map2d(av[1], &height, &width);
	info = malloc(sizeof(t_data));
	*info = get_info(map2d, height, width);
	display_map(info);
    
}
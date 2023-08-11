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


void	draw_ray(t_data *info)
{
	float	x;
	float	y;
	float angel = info->ray->angel;

	//    if (angel < -M_PI)
    //     angel += 2 * M_PI;
    // else if (angel > M_PI)
	// 	angel -= 2 * M_PI;
	for (int i = 0; i<info->ray->distance; i++){
		x = i * cos(angel);
		y = i * sin(angel);
		mlx_put_pixel(info->mlx.image,info->player_pos.x + x ,info->player_pos.y + y , 0x99FF90);
	}
}
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
	
	t_ray *rays = info->ray;
	while (info->ray)
	{
		draw_ray(info);
		info->ray = info->ray->next;
	}

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

float	down_first_x(t_data *info, float angel, float y)
{
	float	distance;

	// printf("%f\n", info->angel);
	distance = y - info->player_pos.y;
	float o = distance / tan(angel);
	return (o + info->player_pos.x);

	return (0);
}

float	up_first_x(t_data *info, float angel, float y)
{
	float	distance;

	// printf("%f\n", angel);

	distance = (info->player_pos.y - y);
	float o = distance / tan(angel);
		return (info->player_pos.x - o);
}


float	down_secnd_x(t_ray *ray, float angel, float y)
{
	float o = 32 / tan(angel);
	return(ray->x + o);
}

float up_secnd_x(t_ray *ray, float angel, float y)
{
	float o = 32 / tan(angel);
	// printf(" o = %f\n", o);
	return(ray->x - o);
}

float ft_distance(t_data *info, float x, float y)
{
	// printf("%f  %f\n", x, y);
	// if (x == 0 || y == 0)
	// 	return (0);
	return(sqrt(pow(info->player_pos.x - x, 2) + pow(info->player_pos.y - y, 2)));
}
/*         waaaaaaaaaaa      */

t_ray	*horizontal(t_data *info, float angel)
{
	float	x;
	float	y;
	t_ray *ray = malloc(sizeof(t_ray));

	if ((angel >= 0 && angel <= M_PI))
	{
		y = floor(info->player_pos.y / 32) * 32 + 32;
		x = down_first_x(info, angel, y);
		ray->x = x;
		ray->y = y;
	}
	if ((angel < 0 && angel > -M_PI))
	{
		y = floor(info->player_pos.y / 32) * 32;
		x = up_first_x(info, angel, y);
		ray->x = x;
		ray->y = y;
	}

	// printf("x = %d y = %f \n", (int)(info->ray.hx/32), info->ray.hy/32);
	
	while(wall(info, ray->x, ray->y) == 0 && angel >= 0 && angel <= M_PI)
	{
			ray->y += 32;
			ray->x = down_secnd_x(ray, angel, ray->y);
	}
	while(wall(info, ray->x, ray->y - 32) == 0 && angel < 0 && angel >- M_PI)
	{
			ray->y-= 32;
			ray->x = up_secnd_x(ray, angel, ray->y);
	}

	ray->next = NULL;
	return (ray);
}

t_ray	*ft_lstlast(t_ray *rays)
{
	if (!rays)
		return (0);
	while (rays->next)
		rays = rays->next;
	return (rays);
}

void	add_rays(t_ray **rays, t_ray *new_ray)
{
	t_ray *last_ray;
	// puts("here");
	if (!rays)
		return ;
	if (*rays == NULL)
	{
		*rays = new_ray;
		return ;
	}
	last_ray = ft_lstlast(*rays);
	last_ray->next = new_ray;
}

void ray(void *inf)
{
	t_data *info = inf;

	float	start_angel = info->angel - (30 * M_PI / 180);
	float	end_angel = info->angel + (30 * M_PI / 180);

	// Adjust start_angle to be within the range -π to π
	// float tmp = start_angel;
    // if (tmp < -M_PI)
    //     tmp += 2 * M_PI;
    // else if (start_angel > M_PI)
    //     start_angel -= 2 * M_PI;

    // Adjust end_angle to be within the range -π to π
    // if (end_angel < -M_PI)
    //     end_angel += 2 * M_PI;
    //  if (end_angel > M_PI)
    //     end_angel -= 2 * M_PI;
	// if (fmod(start_angel , (2 * M_PI) > M_PI))
	// 	start_angel += 2 * M_PI;
	// if (fmod(end_angel , (2 * M_PI) > M_PI))
	// 	end_angel -= 2 * M_PI;

		// printf("<<<<<<<<%f  >>\n", end_angel);
		// printf("%f  >>>>>\n", start_angel);
	info->ray = NULL;
	while (start_angel <= end_angel)
	{
		t_ray	*virtical_ray;
		t_ray	*horizontal_ray;
		virtical_ray = virtical(info, start_angel);
		horizontal_ray = horizontal(info, start_angel);
		if(ft_distance(info, horizontal_ray->x, horizontal_ray->y) > ft_distance(info, virtical_ray->x, virtical_ray->y))
		{
			virtical_ray->distance = ft_distance(info, virtical_ray->x, virtical_ray->y);
			virtical_ray->angel = start_angel;
			add_rays(&info->ray, virtical_ray);
			free(horizontal_ray);
		}
		else
		{
			horizontal_ray->distance = ft_distance(info, horizontal_ray->x, horizontal_ray->y);
			horizontal_ray->angel = start_angel;
			add_rays(&info->ray, horizontal_ray);
			free(virtical_ray);
		}
		start_angel += 0.01;
		
	}
}

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


void display_map(t_data *info)
{

	info->mlx.mlx = mlx_init(1200, 1000, "test", NULL);
	info->mlx.image = mlx_new_image(info->mlx.mlx, 1200, 1000);
	mlx_image_to_window(info->mlx.mlx, info->mlx.image, 0, 0);
	mlx_loop_hook(info->mlx.mlx, click, info);
	mlx_loop_hook(info->mlx.mlx, ray, info);
	mlx_loop_hook(info->mlx.mlx, rerender, info);
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
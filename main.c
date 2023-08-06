#include "cube3d.h"
#include <mlx.h>

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
		map = ft_strjoin(map, str);
		free(str);
	}
	map2d = ft_split(map, '\n');
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

void ft_draw_32(char **map2d, t_vars *p_pos, int i, int j, int color)
{
	if(color == 0)
		mlx_put_image_to_window(p_pos->mlx, p_pos->mlx_win,p_pos->white,  j * 32,i * 32);
	else
		mlx_put_image_to_window(p_pos->mlx, p_pos->mlx_win,p_pos->dackBlue,  j * 32, i * 32);

}

void ft_draw_p(char **map2d, void *mlx, void *mlx_win, int i, int j, int color)
{
	int x, y;
	x = y = 0;
	while(x < 4)
	{
		y = 0;
		while(y < 4)
		{
			mlx_pixel_put(mlx, mlx_win, j * 32 + x +15, i * 32 + y + 15, color);
			y++;
		}
		x++;
	}
}
void ft_draw_der(char **map2d, void *mlx, void *mlx_win, int i, int j, int color)
{
	int x, y;
	x = y = 0;
	while(x < 4)
	{
		y = 0;
		while(y < 4)
		{
			mlx_pixel_put(mlx, mlx_win, i + x, j + y, color);
			y++;
		}
		x++;
	}
}

int wall(t_vars *p_pos, int x, int y)
{
	printf("i = %d, j = %d\n", y/32,x/32);
	if(p_pos->map2d[y/32][x/32] == '1')
		return 1;
	return 0;
}

int click(int keycode, t_vars *p_pos)
{
	if(keycode == KEY_UP)
	{
		if(wall(p_pos,p_pos->xp + (p_pos->move_speed) * cos(p_pos->angelP),p_pos->yp + (p_pos->move_speed) * sin(p_pos->angelP)) == 0)
		{
			p_pos->xp = p_pos->xp + (p_pos->move_speed) * cos(p_pos->angelP);
			p_pos->yp = p_pos->yp + (p_pos->move_speed) * sin(p_pos->angelP);
		}
	}
	if(keycode == KEY_DOWN)
	{
		if(wall(p_pos, p_pos->xp - (p_pos->move_speed) * cos(p_pos->angelP), p_pos->yp - (p_pos->move_speed) * sin(p_pos->angelP)) == 0)
		{
			p_pos->xp = p_pos->xp - (p_pos->move_speed) * cos(p_pos->angelP);
			p_pos->yp = p_pos->yp - (p_pos->move_speed) * sin(p_pos->angelP);
		}
	}
	if(keycode == KEY_LEFT)
	{
		p_pos->angelP = p_pos->angelP - (p_pos->rotate_speed);
	}
	if(keycode == KEY_RIGHT)
	{
		p_pos->angelP = p_pos->angelP + (p_pos->rotate_speed);

	}
	return 0;
}

int rerender(t_vars *p_pos)
{

	int i = 0;
	int j = 0;
	mlx_clear_window(p_pos->mlx, p_pos->mlx_win);
	while(p_pos->map2d[i])
    {
        j = 0;
        while(p_pos->map2d[i][j])
        {
            if(p_pos->map2d[i][j] == '0' || p_pos->map2d[i][j] == 'N' ||
			p_pos->map2d[i][j] == 'E' ||
			p_pos->map2d[i][j] == 'S'||
			p_pos->map2d[i][j] == 'W')
			{
				ft_draw_32(p_pos->map2d, p_pos, i, j, 0);
			}
			else if(p_pos->map2d[i][j] == '1')
			{
				ft_draw_32(p_pos->map2d, p_pos, i, j, 1);
			}
            j++;
        }
        i++;
    }
	p_pos->x_der = p_pos->xp + 80 * cos(p_pos->angelP);
	p_pos->y_der = p_pos->yp + 80 * sin(p_pos->angelP);
	ft_draw_der(p_pos->map2d, p_pos->mlx, p_pos->mlx_win, p_pos->xp, p_pos->yp, 0xFF0F0F);
	ft_draw_der(p_pos->map2d, p_pos->mlx, p_pos->mlx_win, p_pos->x_der, p_pos->y_der, 0xFA8072);
	return(0);
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
		return (- 3 * M_PI / 2);
	return 0;
}

void display_map(char **map2d)
{
	int i = 0;
	int j = 0;
	int i_tmp = 0;
	int j_tmp = 0;
	int x, y;
	int q, w;
	t_vars p_pos;
	p_pos.move_speed = 3;
	p_pos.rotate_speed = 0.15;
	p_pos.xp = ft_player_pos_x(map2d) * 32 + 15;
	p_pos.yp = ft_player_pos_y(map2d) * 32 + 15;
	p_pos.angelP = ft_player_angel(map2d);
	
	p_pos.map2d = map2d;
	p_pos.mlx = mlx_init();
	p_pos.dackBlue = mlx_xpm_file_to_image(p_pos.mlx,"darckBlue.xpm",&x, &y);
	p_pos.white = mlx_xpm_file_to_image(p_pos.mlx,"Sources/white_image.xpm",&q, &w);
	p_pos.mlx_win = mlx_new_window(p_pos.mlx, 1200, 1000,"te");

	mlx_hook(p_pos.mlx_win,2, 0, click, &p_pos);
	mlx_loop_hook(p_pos.mlx, rerender, &p_pos);

	mlx_loop(p_pos.mlx);
}



int main (int ac, char **av){
    char **map2d;
    char *map;

    map2d = ft_read_map2d(av[1]);
    int i = 0;
    int j = 0;
    // if(check_map(map))
    //    return(perror("error"),1);
	display_map(map2d);
    
}
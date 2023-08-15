#ifndef CUBE3D_H
# define CUBE3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 #include "/Users/ysahih/Desktop/MLX42/include/MLX42/MLX42.h"

#define RGBA(r, g, b, a) (r << 24 | g << 16 | b << 8 | a)

#define SIZE 32 
#define	RAYS 1048
#define WIDTH 1048
#define HEIGHT 720
#define MINI 0.5

typedef struct	s_pos
{
	float	x;
	float	y;
} t_pos;
typedef struct  s_mlx
{
	mlx_texture_t *txt;
	mlx_image_t	*txt_image;
	mlx_image_t	*image;
	mlx_t		*mlx;
} t_mlx;

typedef struct s_ray
{
	float			distance;
	float		 	angle;

	float			x;
	float			y;
	
	char			t;
	int				nb;
	struct s_ray	*next;
} t_ray;
typedef struct s_data
{
	char 			**map2d;
	t_ray			*ray;
	t_mlx			mlx;
	t_pos			der_pos;
	t_pos			player_pos;
	int				width; // row
	int				height; // col
	float 			move_speed;
	float 			rotate_speed;
	float 			angle;
}   t_data;

//utils
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin_one(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

//ray casting
void	ray(void *inf);
t_ray	*vertical(t_data *info, float angle);
t_ray	*horizontal(t_data *info, float angle);

//ray casting utils
int 	wall(t_data *info, int x, int y);
void	draw_ray(t_data *info);

//minimap
void	render_minimap(t_data *info);
void	draw_player(t_data *info, int color,int i);
//walls
void    draw_walls(t_ray *ray, t_data *info, float x);

#endif
#ifndef CUBE3D_H
# define CUBE3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 #include "/Users/isbarka/Desktop/MLX42/include/MLX42/MLX42.h"


#define RGB(r, g, b) (r << 16 | g << 8 | b)

#define SIZE 32
#define KEY_UP 13
#define KEY_DOWN 1
#define KEY_LEFT 0
#define KEY_RIGHT 2


typedef struct	s_pos
{
	float	x;
	float	y;
} t_pos;
typedef struct  s_mlx
{
	char 	*adrs;
	mlx_t 	*mlx;
	mlx_image_t	*image;
	int		len;
	int		block;
	int		endian;

} t_mlx;

typedef struct s_ray
{
	
	float x;
	float y;
} t_ray;

typedef struct s_data
{
	int		width; // row
	int		height; // col
	// int		addrs;
	t_pos	player_pos;
	t_pos	der_pos;
	float 	move_speed;
	float 	rotate_speed;
	float 	angel;
	char 	**map2d;
	t_mlx	mlx;
	t_ray	ray;
}   t_data;




void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin_one(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
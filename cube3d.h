#ifndef CUBE3D_H
# define CUBE3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
 #include "/Users/isbarka/Desktop/MLX42/include/MLX42/MLX42.h"

#define RGBA(r, g, b, a) (r << 24 | g << 16 | b << 8 | a)


#define SIZE 32 
#define	RAYS 1048
#define WIDTH 1048
#define HEIGHT 800

#define M_WIDTH	200
#define M_HEIGHT 130 


typedef struct	s_pos
{
	float	x;
	float	y;
} t_pos;
typedef struct  s_mlx
{
	mlx_texture_t *txt;
	mlx_image_t	*no_image;
	mlx_image_t	*so_image;
	mlx_image_t	*ea_image;
	mlx_image_t	*we_image;
	mlx_image_t	*image;
	mlx_t		*mlx;
} t_mlx;

typedef struct s_ray
{
	float			distance;
	float		 	angle;
	float			x;
	float			y;
	char			type;
	struct s_ray	*next;
} t_ray;

typedef struct s_sources
{
	char *no;
	char *so;
	char *we;
	char *ea;
	int f_r;
	int f_g;
	int f_b;
	int c_r;
	int c_g;
	int c_b;

} t_sources;

typedef struct s_data
{
	unsigned int	*texture;
	char 			**map2d;
	t_ray			*ray;
	t_mlx			mlx;
	t_pos			der_pos;
	t_pos			player_pos;
	int				width; // row
	int				height; // col
	float 			move_speed;
	t_sources		sources;
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

//textures
unsigned int *store_colors(uint8_t *img);

//minimap
void	render_minimap(t_data *info);
void	draw_player(t_data *info, int color,int i);
//walls
void    draw_walls(t_ray *ray, t_data *info, float x);
unsigned int	get_color(mlx_image_t *image, int img_y, int img_x);

//parsing
typedef struct s_letters
{
	int n;
	int s;
	int e;
	int w;
	int zero;
	int one;
}   t_letters;


typedef struct s_check
{
	int tmp_i;
    int tmp_j;
    int check[4];
}   t_check;

void ft_parsing(t_data *info);
void ft_parsing_tmp(t_data *info);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
size_t	ft_len(char **s);
void ft_error();
void check_av(char *av);
void check_map(char *map);
char	**ft_split_one(const char *s, char c);
void check_empty_line(char **map2d1);
char *ft_so(t_data *info);
char *ft_we(t_data *info);
char *ft_ea(t_data *info);
char *ft_no(t_data *info);
char *ft_f(t_data *info);
char *ft_c(t_data *info);
void check_two_camas(char *str);
char *first_cama(char *str);
void ft_check_rgb(char *str, char c, t_data *info);
void check_arguments(t_data *info);
void ft_transform_to_spaces(t_data *info, int i);
void ft_arguments_to_space(t_data *info);
void check_under_map(t_data *info, int i);
void argument_under_map(t_data *info);
void add_spaces(t_data *info, int longest);
void ft_rect(t_data *info);
void ft_check_two(int i, int j,  t_data *info, t_letters *letters);
void ft_check_one(int i, int j,  t_data *info, t_letters *letters);
void    ft_init_zero(t_letters *letters, int *i, int *j);
void ft_check_letters(t_data *info);
void ft_check_character3(t_check *check);
void ft_check_character2(t_data *info, int i, int j, t_check *check);
void ft_check_character1(t_data *info, int i, int j, t_check *check);
void ft_check_character(t_data *info, int i, int j);
void check_inside(t_data *info);
int check_all_spaces(char *str);
int ft_lines_to_alloc(char **map2d);
void remove_space_lines(t_data *info);
void check_av(char *av);
void check_map(char *map);
void check_empty_line1(char **map2d1, int i, int first_line_index, int last_line_index);
void check_empty_line(char **map2d1);
void ft_parsing(t_data *info);



#endif
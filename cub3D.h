
#ifndef cub3D_H
# define cub3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

# include "/Users/ysahih/Desktop/MLX42/include/MLX42/MLX42.h"

#define RGBA(r, g, b, a) (r << 24 | g << 16 | b << 8 | 255)


# define SIZE 32 
# define RAYS 1048
# define WIDTH 1048
# define HEIGHT 800

# define M_WIDTH 200
# define M_HEIGHT 130 


typedef struct s_wall
{
	unsigned int	color;
	int				wall_height;
	int				h;
	int				middle;
	float			y;
	int				img_y;
	int				img_x;
	int				hold;
	int				i;

}	t_wall;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_mlx
{
	mlx_texture_t	*txt;
	mlx_image_t		*no_image;
	mlx_image_t		*txt_image;
	mlx_image_t		*so_image;
	mlx_image_t		*ea_image;
	mlx_image_t		*we_image;
	mlx_image_t		*image;
	mlx_t			*mlx;
}	t_mlx;


typedef struct s_ray
{
	float			distance;
	float			angle;
	float			x;
	float			y;
	char			type;
	struct s_ray	*next;
}	t_ray;

typedef struct s_sources
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;

}	t_sources;

typedef struct s_data
{
	unsigned int	*texture;
	char			**map2d;
	char			**map2d1;
	t_ray			*ray;
	t_mlx			mlx;
	t_pos			der_pos;
	t_pos			player_pos;
	int				height;
	int				width;
	float			move_speed;
	t_sources		sources;
	float			rotate_speed;
	float			angle;
}	t_data;

typedef struct s_letters
{
	int	n;
	int	s;
	int	e;
	int	w;
	int	zero;
	int	one;
}	t_letters;


typedef struct s_check
{
	int	tmp_i;
	int	tmp_j;
	int	check[4];
}	t_check;

//utils
char 	**ft_read_map2d(char *av, t_data *info);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin_one(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

//movements
void 	click(void *inf);
//movements utils
int wall_1(t_data *info, int x, int y);

//store up
float ft_player_angle(char **map2d);
int ft_player_pos_y(char **map2d);
int ft_player_pos_x(char **map2d);
void ft_player_angle1(int *i, int *j, char **map2d);
//ray casting
void	ray(void *inf);
void	collect_ray(t_data **info, t_ray *new_ray, float angle, char c);

t_ray	*vertical(t_data *info, float angle);
t_ray	*first_vehit(t_data *info, float angle);
t_ray	*horizontal(t_data *info, float angle);
t_ray	*first_hohit(t_data *info, float angle);



//ray casting utils
int 	wall(t_data *info, int x, int y);
float	up_secnd_x(t_ray *ray, float angle);
float	down_secnd_x(t_ray *ray, float angle);
float	down_first_x(t_data *info, float angle, float y);
float	up_first_x(t_data *info, float angle, float y);
float	ft_distance(t_data *info, float x, float y);
float	right_secnd_y(t_ray *ray, float angle);
float	left_secnd_y(t_ray *ray, float angle);
float	left_first_y(t_data *info, float angle, float x);
float	first_y(t_data *info, float angle, float x);
void	add_rays(t_ray **rays, t_ray *new_ray);
t_ray	*ft_lstlast(t_ray *rays);

//display
void	display_map(t_data *info);
void	rerender(void *inf);
void	render_ceiling(mlx_image_t *image, unsigned int color);
void	render_floor(mlx_image_t *image, unsigned int color);
void	render_walls(t_data *info);
void	render_minimap(t_data *info);
void	render_player(t_data *info);
void	render_walls(t_data *info);
void	draw_walls(t_data *info, t_ray *ray, float x);
void	draw_direction(t_data *info);
void	draw_player(t_data *info, int color,int i);
void	draw_circle(t_data *info);
//minimap
void	draw_ray(t_data *info);

//textures
unsigned int			get_color(mlx_image_t *image, int img_y, int img_x);
mlx_image_t	*get_image(t_data *info, t_ray *ray);
mlx_image_t	*load_png(t_data *info, char *s);
float	image_offset(mlx_image_t *image, t_ray *ray);
void	get_textures(t_data *info);

//parsing
void 			ft_parsing(t_data *info);
void 			ft_parsing_tmp(t_data *info);

int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
size_t			ft_len(char **s);
void			ft_error(const char *str);
void 			check_av(char *av);
void 			check_map(char *map);
char			**ft_split_one(const char *s, char c);
void 			check_empty_line(char **map2d1);
char 			*ft_so(t_data *info);
char 			*ft_we(t_data *info);
char 			*ft_ea(t_data *info);
char 			*ft_no(t_data *info);
void			ft_so_one(t_data *info);
void			ft_we_one(t_data *info);
void			ft_ea_one(t_data *info);
void			ft_no_one(t_data *info);
char 			*ft_f(t_data *info);
char 			*ft_c(t_data *info);
void 			check_two_camas(char *str);
char 			*first_cama(char *str);
void 			ft_check_rgb(char *str, char c, t_data *info);
void 			check_arguments(t_data *info);
void 			ft_transform_to_spaces(t_data *info, int i);
void 			ft_arguments_to_space(t_data *info);
void 			check_under_map(t_data *info, int i);
void 			argument_under_map(t_data *info);
void 			add_spaces(t_data *info, int longest);
void 			ft_rect(t_data *info);
void 			ft_check_two(int i, int j,  t_data *info, t_letters *letters);
void 			ft_check_one(int i, int j,  t_data *info, t_letters *letters);
void 			   ft_init_zero(t_letters *letters, int *i, int *j);
void 			ft_check_letters(t_data *info);
void 			ft_check_character3(t_check *check);
void 			ft_check_character2(t_data *info, int i, int j, t_check *check);
void 			ft_check_character1(t_data *info, int i, int j, t_check *check);
void 			ft_check_character(t_data *info, int i, int j);
void 			check_inside(t_data *info);
int 			check_all_spaces(char *str);
int				ft_lines_to_alloc(char **map2d);
void 			remove_space_lines(t_data *info);
void 			check_av(char *av);
void 			check_map(char *map);
void 			check_empty_line1(char **map2d1, int i, int first_line_index, int last_line_index);
void 			check_empty_line(char **map2d1);
void 			ft_parsing(t_data *info);
bool			check_walls(t_data *info, int i, int j);
void			ft_f_one(t_data *info);
void			ft_c_one(t_data *info);
int 			check_under_line(char **map2d1, int i);
char	**ft_alloc(int i);
char	**str_count_one(char **str, const char *s, char c);


#endif
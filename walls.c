#include "cube3d.h"

unsigned int	get_color(mlx_image_t *image, int img_y, int img_x)
{
	unsigned int color;

	int	index = (img_y * image->width + img_x) * 4;
	if (index + 3 >= image->height * image->width * 4)
		return (0);
	unsigned int r = image->pixels[index];
	unsigned int g = image->pixels[index + 1];
	unsigned int b = image->pixels[index + 2];
	unsigned int a = image->pixels[index + 3];
    color = RGBA(r, g, b, a);
    return color;
}

float	image_offset(t_data *info, t_ray *ray)
{
	float	img_x;
	if (ray->type == 'V')
		img_x =	fmod(ray->y, SIZE);
	else
		img_x =	fmod(ray->x, SIZE);
	img_x /= SIZE;
	img_x *= info->mlx.txt_image->width;
	return (img_x);
}

mlx_image_t	*load_textures(t_data *info, char *s)
{
	mlx_texture_t	*txt;
	mlx_image_t		*image;

	printf("%s\n", s);
	txt = mlx_load_png(s);
	// TODO : protect
	image = mlx_texture_to_image(info->mlx.mlx, txt);
	return (image);
}

void	draw_walls(t_ray *ray, t_data *info, float x)
{
	unsigned int color;
	int wall_height;
	int h;
	int middle;
	float y;
	int		img_y;
	int	img_x;
	mlx_image_t *image;
	
	if (ray->type == 'H')
		image = load_textures(info, info->sources.no);
	else
		image = load_textures(info, info->sources.we);

	int	hold = 0;
	middle = HEIGHT / 2;
	wall_height = (HEIGHT * 20) / (ray->distance * cos(ray->angle - info->angle));
	h = wall_height;
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	img_x = image_offset(info, ray);
	y = middle - wall_height / 2;
	for (int i = 0; i < wall_height; i++){
		if (wall_height == HEIGHT)
			hold = (h - HEIGHT) / 2;
		img_y = ((i * info->mlx.txt_image->height)/ h + (hold * info->mlx.txt_image->height)/ h);
		color = get_color(image,img_y, img_x);
		mlx_put_pixel(info->mlx.image, x, y + i, color);
	}
}
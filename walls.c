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

float	image_offset(mlx_image_t *image, t_ray *ray)
{
	float	img_x;
	if (ray->type == 'V')
		img_x =	fmod(ray->y, SIZE);
	else
		img_x =	fmod(ray->x, SIZE);
	img_x /= SIZE;
	img_x *= image->width;
	return (img_x);
}

mlx_image_t	*get_image(t_data *info, t_ray *ray)
{
	mlx_image_t	*image;

	if (ray->type == 'V')
	{
		if (ray->angle > -M_PI/2 && ray->angle < M_PI/2)
			image = info->mlx.ea_image;
		if (ray->angle <= -M_PI || ray->angle >= M_PI || (ray->angle >= -M_PI && ray->angle < -M_PI / 2) || (ray->angle <= M_PI && ray->angle > M_PI / 2))
			image = info->mlx.we_image;
	} 
	if (ray->type == 'H')
	{
	 	if (ray->angle < -M_PI|| (ray->angle >= 0 && ray->angle <= M_PI))
			image = info->mlx.no_image;
		if (ray->angle >= M_PI || (ray->angle < 0 && ray->angle > -M_PI))
			image = info->mlx.so_image;
	}
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
	mlx_image_t	*image;

	image = get_image(info, ray);
	int	hold = 0;
	middle = HEIGHT / 2;
	wall_height = (HEIGHT * 20) / (ray->distance * cos(ray->angle - info->angle));
	h = wall_height;
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	img_x = image_offset(image, ray);
	y = middle - wall_height / 2;
	for (int i = 0; i < wall_height; i++){
		if (wall_height == HEIGHT)
			hold = (h - HEIGHT) / 2;
		img_y = ((i * image->height)/ h + (hold * image->height)/ h);
		color = get_color(image,img_y, img_x);
		mlx_put_pixel(info->mlx.image, x, y + i, color);
	}
}
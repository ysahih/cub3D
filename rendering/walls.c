#include "../cube3d.h"

unsigned int	get_color(mlx_image_t *image, int img_y, int img_x)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
	int				index;

	index = (img_y * image->width + img_x) * 4;
	if (index + 3 >= image->height * image->width * 4)
		return (0);
	r = image->pixels[index];
	g = image->pixels[index + 1];
	b = image->pixels[index + 2];
	a = image->pixels[index + 3];
	return (RGBA(r, g, b, a));
}

float	image_offset(mlx_image_t *image, t_ray *ray)
{
	float	img_x;

	if (ray->type == 'V')
		img_x = fmod(ray->y, SIZE);
	else
		img_x = fmod(ray->x, SIZE);
	img_x /= SIZE;
	img_x *= image->width;
	return (img_x);
}

mlx_image_t	*get_image(t_data *info, t_ray *ray)
{
	mlx_image_t	*image;

	if (ray->type == 'V')
	{
		if (ray->angle > -M_PI / 2 && ray->angle < M_PI / 2)
			image = info->mlx.ea_image;
		if (ray->angle <= -M_PI || ray->angle >= M_PI
			|| (ray->angle >= -M_PI && ray->angle < -M_PI / 2)
			|| (ray->angle <= M_PI && ray->angle > M_PI / 2))
			image = info->mlx.we_image;
	}
	if (ray->type == 'H')
	{
		if (ray->angle < -M_PI || (ray->angle >= 0 && ray->angle <= M_PI))
			image = info->mlx.no_image;
		if (ray->angle >= M_PI || (ray->angle < 0 && ray->angle > -M_PI))
			image = info->mlx.so_image;
	}
	return (image);
}

void	draw(t_data *info, mlx_image_t *image, int wall_height, int img_x)
{
	static int	x;
	int			img_y;
	int			i;
	int			h;
	int			hold;

	i = -1;
	if (x == WIDTH)
		x = 0;
	h = wall_height;
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	while (++i < wall_height)
	{
		if (wall_height == HEIGHT)
			hold = (h - HEIGHT) / 2;
		img_y = ((i * image->height) / h
				+ (hold * image->height) / h);
		mlx_put_pixel(info->mlx.image, x, \
			((HEIGHT / 2 - wall_height / 2) + i),
			get_color(image, img_y, img_x));
	}
	x++;
}

void	render_walls(t_data *info)
{
	mlx_image_t	*image;
	t_ray		*ray;
	int			wall_height;
	int			img_x;

	ray = info->ray;
	while (ray)
	{
		image = get_image(info, ray);
		wall_height = (HEIGHT * 20)
			/ (ray->distance * cos(ray->angle - info->angle));
		img_x = image_offset(image, ray);
		draw(info, image, wall_height, img_x);
		ray = ray->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:14:02 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/27 01:06:34 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
	return (rgba(r, g, b, a));
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

void	draw_walls(t_data *info, t_ray *ray, float x)
{
	t_wall	wall;

	wall.i = -1;
	wall.hold = 0;
	wall.middle = HEIGHT / 2;
	info->mlx.txt_image = get_image(info, ray);
	wall.wall_height = (HEIGHT * 10)
		/ (ray->distance * cos(ray->angle - info->angle));
	wall.h = wall.wall_height;
	if (wall.wall_height > HEIGHT)
		wall.wall_height = HEIGHT;
	wall.img_x = image_offset(info->mlx.txt_image, ray);
	wall.y = wall.middle - wall.wall_height / 2;
	while (++wall.i < wall.wall_height)
	{
		if (wall.wall_height == HEIGHT)
			wall.hold = (wall.h - HEIGHT) / 2;
		wall.img_y = ((wall.i * info->mlx.txt_image->height) / wall.h
				+ (wall.hold * info->mlx.txt_image->height) / wall.h);
		wall.color = get_color(info->mlx.txt_image, wall.img_y, wall.img_x);
		mlx_put_pixel(info->mlx.image, x, wall.y + wall.i, wall.color);
	}
}

void	render_walls(t_data *info)
{
	int		x;
	t_ray	*tmp;

	x = 0;
	while (info->ray)
	{
		tmp = info->ray;
		draw_walls(info, info->ray, x);
		info->ray = info->ray->next;
		free(tmp);
		x++;
	}
}

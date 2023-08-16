#include "cube3d.h"


/*  after rendreing floor and ceiling,//

we have to store how many rays are casted
to get the value of drawing walls increment (width / nb of rays casted);
after getting the value we render walls depending on how many rays 
to render the walls we calculate the size of the wall and its start point; */

unsigned int	get_color(t_data *info, t_ray *ray,int offset_y)
{
	unsigned int color;
	float	img_x;
	// static int x1 = 0;
	if (ray->t == 'V')
		img_x =	fmod(ray->y, SIZE);
	else
		img_x =	fmod(ray->x, SIZE);
	img_x /= SIZE;
	img_x *= info->mlx.txt_image->width;
	int	index = (offset_y * info->mlx.txt_image->width + (int)img_x) * 4;

	if (index + 3 >= info->mlx.txt_image->height * info->mlx.txt_image->width * 4)
		return (0);
	unsigned int r = info->mlx.txt_image->pixels[index];
	unsigned int g = info->mlx.txt_image->pixels[index + 1];
	unsigned int b = info->mlx.txt_image->pixels[index + 2];
	unsigned int a = info->mlx.txt_image->pixels[index + 3];
    color = RGBA(r, g, b, a);
    return color;
}



void	draw_walls(t_ray *ray, t_data *info, float x)
{
	int wall_height;
	float middle;
	float y;
	unsigned int color;
	int		offset_y;

	middle = HEIGHT / 2;
	wall_height = HEIGHT * SIZE / ray->distance;
	// * cos(ray->angle - info->angle);
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	
	y = middle - wall_height / 2;
	// printf("%f, %f\n", info->ray->x, info->ray->y);
	for (int i = 0; i < wall_height; i++){
		offset_y = i * info->mlx.txt_image->height / wall_height;
		// if ()
		color = get_color(info,ray, offset_y);
		mlx_put_pixel(info->mlx.image, x, y + i, color);
	}
}
#include "cube3d.h"


/*  after rendreing floor and ceiling,//

we have to store how many rays are casted
to get the value of drawing walls increment (width / nb of rays casted);
after getting the value we render walls depending on how many rays 
to render the walls we calculate the size of the wall and its start point; */



void	put_col(t_data *info, int x, int y, int color)
{
	//protect


	// if (info->ray->t == 'H')
	// // {
	// // }
	// 	else
			// mlx_put_pixel(info->mlx.image, x, y, 0x0090FF);
			mlx_put_pixel(info->mlx.image, x, y, color);

	// mlx_resize_image()
}

int	get_color(t_data *info, int *o)
{
	int	color;
	int	img_x;
	// static int x1 = 0;
	if (info->ray->t == 'V')
		img_x =	fmod(info->ray->y , SIZE);
	else
		img_x =	fmod(info->ray->x , SIZE);

	int	num = info->mlx.txt_image->width * (*o) + img_x;
	if ( num + 3 >= info->mlx.txt_image->height * info->mlx.txt_image->width)
		return (0);
	unsigned int r = info->mlx.txt_image->pixels[num];
	unsigned int g = info->mlx.txt_image->pixels[num + 1];
	unsigned int b = info->mlx.txt_image->pixels[num + 2];
	unsigned int a = info->mlx.txt_image->pixels[num + 3];
	if (*o >= info->mlx.txt_image->height)
		*o = 0;
	color = RGBA(r, g, b, a);
	return color;
}

void	draw_walls(t_ray *ray, t_data *info, float x)
{
	float wall_height;
	float middle;
	float y;
	int color;

	middle = HEIGHT / 2;
	wall_height = HEIGHT * SIZE / ray->distance ;
	// * cos(ray->angle - info->angle);
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	y = middle - wall_height / 2;

	for (int i = 0; i < wall_height; i++){
		int o = 0;
		int		inc;
		inc = i * wall_height / info->mlx.txt_image->height;
		color = get_color(info, &o);
		o += inc;
		put_col(info, x, y + i, color);
		// mlx_put_wall(info, x, y + i);
	}
}
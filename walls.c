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
			mlx_put_pixel(info->mlx.image, x, y, 0x0090FF);
	// // }
	// 	else
			// mlx_put_pixel(info->mlx.image, x, y, color);

	// mlx_resize_image()
}

int	get_color(t_data *info, int i, int y)
{
	int	color;
	static int x1 = 0;
	static int x2 = 0;
	if (info->ray->t == 'H')
	{
		if (i * x1 + 3 > info->mlx.txt_image->width)
			return (0);
		color = RGBA(info->mlx.txt_image->pixels[i * x1], info->mlx.txt_image->pixels[i * x1 + 1], info->mlx.txt_image->pixels[i * x2 + 2], info->mlx.txt_image->pixels[i * x2 + 3]);

	}
	if (info->ray->t == 'V')
	{
		x2++;
		x1 = 0;
		if (i * x1 + 3 > info->mlx.txt_image->width)
			return (0);
		color = RGBA(info->mlx.txt_image->pixels[i * x2], info->mlx.txt_image->pixels[i * x2 + 1], info->mlx.txt_image->pixels[i * x2 + 2], info->mlx.txt_image->pixels[i * x2 + 3]);
	}
	return color;
}

void	draw_walls(t_ray *ray, t_data *info, float x)
{
	float wall_height;
	float middle;
	float y;
	int color;

	middle = HEIGHT / 2;
	wall_height = HEIGHT * SIZE / ray->distance * cos(ray->angle - info->angle);
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	y = middle - wall_height / 2;

	for (int i = 0; i < wall_height; i++){
		
		// color = get_color(info, i, y);
		put_col(info, x, y + i, color);
		// mlx_put_wall(info, x, y + i);
	}
}
#include "cube3d.h"

void    ft_mlx_put_pixel(mlx_image_t *img, int j, int i, int color)
{
	for (int y=0; y<SIZE; y++)
		for(int x=0; x<SIZE; x++)
			mlx_put_pixel(img, (j+ x) * MINI , (i + y) * MINI , color);
}

void    render_minimap(t_data *info)
{
	for (int i=0; i<info->height; i++)
		for (int j=0; j<info->width; j++){
			if (info->map2d[i][j] == '1')
				ft_mlx_put_pixel(info->mlx.image, j  * SIZE, i * SIZE , 0x000FF);
			else
				ft_mlx_put_pixel(info->mlx.image, j* SIZE, i* SIZE, 0x0900F);
		}
	draw_player(info, 0x99FF90, 1);

		draw_ray(info);
	while (info->ray->next)
	{
		info->ray = info->ray->next;
	}   
		draw_ray(info);
}
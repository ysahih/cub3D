#include "cube3d.h"


/*  after rendreing floor and ceiling,//

we have to store how many rays are casted
to get the value of drawing walls increment (map->width / nb of rays casted);
after getting the value we render walls depending on how many rays 
to render the walls we calculate the size of the wall and its start point; */


void    mlx_put_wall(t_data *info, float x, float y)
{
	float block = WIDTH / RAYS;

	if (y < 0 )
		return ;
	for (float j = 0; j < block; j++)
    {
            if (x + j < info->width * SIZE)
				if(x + j <= WIDTH)
			    	mlx_put_pixel(info->mlx.image, x + j, y, 0x000F0);
    }
}

void    draw_walls(t_data *info, float x)
{
	float middle = HEIGHT / 2;

	float wall_height = HEIGHT * SIZE / info->ray->distance;

    if (wall_height > HEIGHT)
        wall_height = HEIGHT;

	float y = middle - wall_height / 2;
	
	for (int i = 0; i < wall_height; i++){
		mlx_put_pixel(info->mlx.image, x , y + i, 0x000F0);
		// mlx_put_wall(info, x, y + i);
	}
}
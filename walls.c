#include "cube3d.h"


/*  after rendreing floor and ceiling,//

we have to store how many rays are casted
to get the value of drawing walls increment (map->width / nb of rays casted);
after getting the value we render walls depending on how many rays 
to render the walls we calculate the size of the wall and its start point; */


void    mlx_put_wall(t_data *info, float x, float y)
{
	int block = info->width * SIZE / RAYS + 1;

    // printf("%f    %f\n", x, y);
	for (int j = 0; j < block; j++)
    {
            if (x + j < info->width * SIZE)
			    mlx_put_pixel(info->mlx.image, x + j, y, 0xFFFFFF);
    }
	

}

void    draw_walls(t_data *info, int x)
{
	
	int middle = info->height * 32 / 2;

	float wall_height = SIZE / info->ray->distance * 210;

    if (wall_height > info->height * SIZE)
        wall_height = info->height * SIZE;

	int y = middle - wall_height / 2;
	
	for (int i = 0; i < wall_height; i++){
		mlx_put_wall(info, x, y + i);
	}
}
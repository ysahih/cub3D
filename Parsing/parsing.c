#include "../cube3d.h"

char *ft_f(t_data *info)
{
    char *to_return;
    int i;

    i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "F ", 2) == 0)
        {
            return(ft_strdup(&(info->map2d[i][2])));
        }
        i++;
    }
    ft_error();
    return NULL;
}

char *ft_c(t_data *info)
{
    char *to_return;
    int i;

    i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "C ", 2) == 0)
        {
            return(ft_strdup(&(info->map2d[i][2])));
        }
        i++;
    }
    ft_error();
    return NULL;
}

void check_av(char *av)
{
	int i = 0;
	int len = ft_strlen(av);
	if(av)
	{
		if(av[len - 1] != 'b' || av[len - 2] != 'u' || av[len - 3] != 'c' || av[len - 4] != '.')
			ft_error();
	}
}

void check_map(char *map)
{
    if(!map)
        ft_error();
    int i = 0;
    while(map[i] && map[i] == '\n')
        i++;
    if(!map[i])
        ft_error();
}

void ft_parsing(t_data *info)
{
    check_arguments(info);
    argument_under_map(info);
    ft_arguments_to_space(info);
    ft_rect(info);
    remove_space_lines(info);
    ft_check_letters(info);
    check_inside(info);
}
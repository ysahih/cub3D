#include "../cube3d.h"

void check_empty_line1(char **map2d1, int i, int first_line_index, int last_line_index)
{
    int j;
    while(map2d1[i - 1] && map2d1[i])
    {
        j = 0;
        while(map2d1[i - 1] && map2d1[i] && (map2d1[i][j] && (map2d1[i][j] == ' ' || map2d1[i][j] == '1')))
            j++;
        if((map2d1[i - 1] && map2d1[i] && (!map2d1[i][j] || map2d1[i][j] == '\n') && j != 0))
        {
            last_line_index = i;
            break;
        }
        i++;
    }
    while(first_line_index < last_line_index)
    {
        if(map2d1[first_line_index] && map2d1[first_line_index][0] == '\n')
            ft_error();
        first_line_index++;
    }
}

void check_empty_line(char **map2d1)
{
    int first_line_index = -1;
    int last_line_index = -1;
    int i = 0;
    int j = 0;
    while(map2d1[i])
    {
        j = 0;
        while(map2d1[i][j] && (map2d1[i][j] == ' ' || map2d1[i][j] == '1'))
            j++;
        if((!map2d1[i][j] || map2d1[i][j] == '\n') && j != 0)
        {
            first_line_index = i;
            break;
        }
        i++;
    }
    i++;
    check_empty_line1(map2d1, i, first_line_index, last_line_index);
}

int ft_lines_to_alloc(char **map2d)
{
    int i = 0;
    int count = 0;

    while(map2d[i])
    {
        if(check_all_spaces(map2d[i]) == 0)
            count++;
        i++;
    }
    return count;
}

int check_all_spaces(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}

void remove_space_lines(t_data *info)
{
    int lines_to_alloc = ft_lines_to_alloc(info->map2d);
    char **new_array = malloc((lines_to_alloc + 1) * sizeof(char *));
    new_array[lines_to_alloc] = NULL;
    int i = 0;
    int count = 0;
    while(info->map2d[i])
    {
        if(check_all_spaces(info->map2d[i]) == 0)
        {
            
            new_array[count] = ft_strdup(info->map2d[i]);
            count++;
        }
        i++;
    }
    info->map2d = new_array;
}

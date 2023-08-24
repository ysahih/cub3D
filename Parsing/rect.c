#include "../cube3d.h"

void ft_error()
{
    write(2, "error\n", 6);
    exit(1);
}

int ft_longest(t_data *info)
{
    int i;
    int j;
    int max;

    j = 0;
    max = 0;
    i = 0;
    while(info->map2d[i])
    {
        j = 0;
        while(info->map2d[i][j])
        {
            j++;
        }
        if(j > max)
            max = j;
        i++;
    }
    return max;
}

void add_spaces_one(t_data *info, int i, int longest)
{
    int added;
    int len;

    added = 0;
    len = ft_strlen(info->map2d[i]);
    while(len + added < longest)
    {
        info->map2d[i] = ft_strjoin(info->map2d[i], " ");
        added++;
    }
}

void add_spaces(t_data *info, int longest)
{
    int i;

    i = 0;
    while(info->map2d[i])
    {
        if(ft_strlen(info->map2d[i]) < longest)
            add_spaces_one(info, i, longest);
        i++;
    }
}

void ft_rect(t_data *info)
{
    int longest;
    longest = ft_longest(info);
    add_spaces(info, longest);
}

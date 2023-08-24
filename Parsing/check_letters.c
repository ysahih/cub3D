#include "../cube3d.h"

void ft_check_two(int i, int j,  t_data *info, t_letters *letters)
{
    if(info->map2d[i][j] == 'W')
        {
            if(letters->w ==1)
                ft_error();
            letters->w = 1;
        }
    else if(info->map2d[i][j] == '0')
        {
            letters->zero = 1;
        }
    else if(info->map2d[i][j] == '1')
        {
            letters->one = 1;
        }
    else if(info->map2d[i][j] != ' ')
        ft_error();
}

void ft_check_one(int i, int j,  t_data *info, t_letters *letters)
{
    if(info->map2d[i][j] == 'N')
        {
            if(letters->n == 1)
                ft_error();
            letters->n = 1;
        }
    else if(info->map2d[i][j] == 'S')
        {
            if(letters->s ==1)
                ft_error();
            letters->s = 1;
        }
    else if(info->map2d[i][j] == 'E')
        {
            if(letters->e ==1)
                ft_error();
            letters->e = 1;
        }
    else
        ft_check_two(i , j , info, letters);
}

void    ft_init_zero(t_letters *letters, int *i, int *j)
{
    letters->n = 0;
    letters->s = 0;
    letters->e = 0;
    letters->w = 0;
    letters->zero = 0;
    letters->one = 0;
    *i = 0;
    *j = 0;
}

void ft_check_letters(t_data *info)
{
    t_letters letters;
    int i;
    int j;
    ft_init_zero(&letters, &i, &j);
    while(info->map2d[i])
    {
        j = 0;
        while(info->map2d[i][j])
        {
            ft_check_one(i, j, info, &letters);
            j++;
        }
        i++;
    }
    if(letters.e + letters.n + letters.one + letters.s + letters.w + letters.zero != 3)
        ft_error();
    if(letters.one + letters.zero != 2)
        ft_error();
}

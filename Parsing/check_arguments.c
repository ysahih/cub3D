#include "../cube3d.h"

void check_two_camas(char *str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(str[i])
    {
        if((str[i] < '0' || str[i] > '9') && str[i] != ',')
            ft_error();
        if(str[i] == ',')
            count ++;
        i++;
    }
    if(count != 2)
    {
        ft_error();
    }
}

char *first_cama(char *str)
{
    int i;

    i = 0;
    while(str[i] != ',')
        i++;
    return &str[i + 1];
}

char *second_coma(char *str)
{
    int i;

    i = 0;
    while(str[i] != ',')
        i++;
    i++;
    while(str[i] && str[i] != ',')
        i++;
    if(str[i + 1] == '\0')
        ft_error();
    return &str[i + 1];
}

void ft_check_rgb(char *str, char c, t_data *info)
{ 
    check_two_camas(str);
    int r = ft_atoi(str);
    int g = ft_atoi(first_cama(str));
    int b = ft_atoi(second_coma(str));
    if(r > 255 || r < 0 ||g > 255 || g < 0 ||b > 255 || b < 0)
    {
        ft_error();
    }
    if(c == 'f')
    {
        info->sources.f_r = r;
        info->sources.f_g = g;
        info->sources.f_b = b;
    }
    else
    {
        info->sources.c_r = r;
        info->sources.c_g = g;
        info->sources.c_b = b;
    }

}

void check_arguments(t_data *info)
{
    info->sources.no = ft_no(info);
    info->sources.so = ft_so(info);
    info->sources.we = ft_we(info);
    info->sources.ea = ft_ea(info);
    char *F = ft_f(info);
    char *C = ft_c(info);
    ft_check_rgb(F, 'f', info);
    ft_check_rgb(C, 'c', info);
}

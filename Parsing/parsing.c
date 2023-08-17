#include "../cube3d.h"

void ft_error()
{
    write(2, "error\n", 6);
    exit(1);
}
char *ft_so(t_data *info)
{
    char *to_return;
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "SO ", 3) == 0)
        {
            return(&(info->map2d[i][3]));
        }
        i++;
    }
    ft_error();
    return NULL;
}
char *ft_we(t_data *info)
{
    char *to_return;
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "WE ", 3) == 0)
        {
            return(&(info->map2d[i][3]));
        }
        i++;
    }
    ft_error();
    return NULL;
}
char *ft_ea(t_data *info)
{
    char *to_return;
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "EA ", 3) == 0)
        {
            return(&(info->map2d[i][3]));
        }
        i++;
    }
    ft_error();
    return NULL;
}
char *ft_no(t_data *info)
{
    char *to_return;
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "NO ", 3) == 0)
        {
            return(&(info->map2d[i][3]));
        }
        i++;
    }
    ft_error();
    return NULL;
}
char *ft_f(t_data *info)
{
    char *to_return;
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "F ", 2) == 0)
        {
            return(&(info->map2d[i][2]));
        }
        i++;
    }
    ft_error();
    return NULL;
}
char *ft_c(t_data *info)
{
    char *to_return;
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "C ", 2) == 0)
        {
            return(&(info->map2d[i][2]));
        }
        i++;
    }
    ft_error();
    return NULL;
}

void check_two_camas(char *str)
{
    int i = 0;
    int count = 0;
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
    int i = 0;
    while(str[i] != ',')
        i++;
    return &str[i + 1];
}
char *second_coma(char *str)
{
    int i = 0;
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

void ft_transform_to_spaces(t_data *info, int i)
{
    int x = 0;
    while(info->map2d[i][x])
    {
        info->map2d[i][x] = ' ';
        x++;
    }

}

void ft_arguments_to_space(t_data *info)
{
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strncmp(info->map2d[i], "NO ", 3) == 0
        || ft_strncmp(info->map2d[i], "SO ", 3) == 0
        || ft_strncmp(info->map2d[i], "WE ", 3) == 0 
        || ft_strncmp(info->map2d[i], "EA ", 3) == 0 
        || ft_strncmp(info->map2d[i], "F ", 2) == 0
        || ft_strncmp(info->map2d[i], "C ", 2) == 0)
                ft_transform_to_spaces(info,i);
        i++;
    }
    i = 0;
}

void check_under_map(t_data *info, int i)
{
    while(info->map2d[i] && info->map2d[i][0])
    {
        if(info->map2d[i][0] == 'N'
        || info->map2d[i][0] == 'S'
        || info->map2d[i][0] == 'F'
        || info->map2d[i][0] == 'W'
        || info->map2d[i][0] == 'C'
        || info->map2d[i][0] == 'E')
        {
            ft_error();
        }
        i++;
    }
}

void argument_under_map(t_data *info)
{
    int i = 0;
    while(info->map2d[i])
    {
        if(info->map2d[i][0] == '1')
        {
            check_under_map(info, i);
            break;
        }
        i++;
    }
}

int ft_longest(t_data *info)
{
    int i = 0;
    int j = 0;
    int max = 0;
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
    int added = 0;
    int len = ft_strlen(info->map2d[i]);
    while(len + added < longest)
    {
        info->map2d[i] = ft_strjoin(info->map2d[i], " ");
        added++;
    }
}

void add_spaces(t_data *info, int longest)
{
    int i = 0;
    while(info->map2d[i])
    {
        if(ft_strlen(info->map2d[i]) < longest)
            add_spaces_one(info, i, longest);
        i++;
    }
}



void ft_rect(t_data *info)
{
    int longest = ft_longest(info);
    add_spaces(info, longest);
    int i = 0;
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
    else if(info->map2d[i][j] == 'W')
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

void ft_check_letters(t_data *info)
{
    t_letters letters;
    letters.n = 0;
    letters.s = 0;
    letters.e = 0;
    letters.w = 0;
    letters.zero = 0;
    letters.one = 0;
    int i = 0;
    int j = 0;
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


void ft_check_character(t_data *info, int i, int j)
{
    int tmp_i = i;
    int tmp_j = j;
    int check[4];
    check[0] = 0;
    check[1] = 0;
    check[2] = 0;
    check[3] = 0;
    while(tmp_i >= 0)
    {
        if(info->map2d[tmp_i][j] == '1')
            check[0] = 1;
        if(info->map2d[tmp_i][j] != '0'
        && info->map2d[tmp_i][j] != 'N'
        && info->map2d[tmp_i][j] != 'S'
        && info->map2d[tmp_i][j] != 'W'
        && info->map2d[tmp_i][j] != 'E')
            break;
        tmp_i--;
    }
    while(tmp_j >= 0)
    {
        if(info->map2d[i][tmp_j] == '1')
            check[1] = 1;
        if(info->map2d[i][tmp_j] != '0'
        && info->map2d[i][tmp_j] != 'N'
        && info->map2d[i][tmp_j] != 'S'
        && info->map2d[i][tmp_j] != 'W'
        && info->map2d[i][tmp_j] != 'E')
            break;
        tmp_j--;
    }
    tmp_i = i;
    tmp_j = j;
    while(tmp_i < ft_len(info->map2d))
    {
        if(info->map2d[tmp_i][j] == '1')
            check[2] = 1;
        if(info->map2d[tmp_i][j] != '0'
        && info->map2d[tmp_i][j] != 'N'
        && info->map2d[tmp_i][j] != 'S'
        && info->map2d[tmp_i][j] != 'W'
        && info->map2d[tmp_i][j] != 'E')
            break;
        tmp_i++;
    }
    while(tmp_j < ft_strlen(info->map2d[0]))
    {
        if(info->map2d[i][tmp_j] == '1')
            check[3] = 1;
        if(info->map2d[i][tmp_j] != '0'
        && info->map2d[i][tmp_j] != 'N'
        && info->map2d[i][tmp_j] != 'S'
        && info->map2d[i][tmp_j] != 'W'
        && info->map2d[i][tmp_j] != 'E')
            break;
        tmp_j++;
    }
    if(check[0] + check[1] + check[2] + check[3] != 4)
        ft_error();
}

void check_inside(t_data *info)
{
    int i = 0;
    int j = 0;
    while(info->map2d[i])
    {
        j = 0;
        while(info->map2d[i][j])
        {
            if(info->map2d[i][j] == '0'
            || info->map2d[i][j] == 'N' ||
            info->map2d[i][j] == 'S' ||
            info->map2d[i][j] == 'E' ||
            info->map2d[i][j] == 'W')
                ft_check_character(info, i, j);
            j++;
        }
        i++;
    }
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
    i = 0;
    while(new_array[i])
    {
        printf("%s++\n", new_array[i]);
        i++;
    }

    info->map2d = new_array;

}

void ft_parsing_tmp(t_data *info)
{
    check_arguments(info);
    argument_under_map(info);
    ft_arguments_to_space(info);
    ft_rect(info);
    remove_space_lines(info);
    ft_check_letters(info);
    check_inside(info);
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


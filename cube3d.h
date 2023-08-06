#ifndef CUBE3D_H
# define CUBE3D_H

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#define KEY_UP 13
#define KEY_DOWN 1
#define KEY_LEFT 0
#define KEY_RIGHT 2
#define FALSE 0



typedef struct s_vars
{
    double xp;
    double yp;
    float angelP;
    char **map2d;
    void *mlx;
    void *mlx_win;
    void *dackBlue;
    int x_darckBlue;
    int y_darckBlue;
    void *white;
    int x_white;
    int y_white;
    double x_der;
    double y_der;
    float move_speed;
    float rotate_speed;
}   t_vars;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin_one(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

#endif
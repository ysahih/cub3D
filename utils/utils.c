/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:52:10 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/27 00:01:05 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_word(const char *s, char c)
{
	char	*str;
	int		len;

	len = word_len(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		ft_error("allocation failed");
	}
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}

static char	**str_count(char **str, const char *s, char c)
{
	int	i ;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			s++;
		}
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
		{
			s++;
		}
	}
	str = malloc((i + 1) * sizeof(char *));
	if (!str)
	{
		free(str);
		ft_error("allocation failed");
	}
	str[i] = 0;
	return (str);
}

char	*ft_read_map2d1(char *map, int fd)
{
	char	*str;
	int		i;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		i++;
		map = ft_strjoin(map, str);
		free(str);
	}
	return (map);
}

char	**ft_read_map2d(char *av, t_data *info)
{
	char	**map2d;
	char	**map2d1;
	char	*map;
	int		fd;

	check_av(av);
	fd = open((const char *)av, O_RDWR);
	if (fd == -1)
	{
		write(1, "cound not find the map\n", 23);
		exit(-1);
	}
	map = NULL;
	map = ft_read_map2d1(map, fd);
	check_map(map);
	map2d = ft_split(map, '\n');
	map2d1 = ft_split_one(map, '\n');
	info->map2d1 = map2d1;
	check_empty_line(map2d1);
	free(map);
	return (map2d);
}

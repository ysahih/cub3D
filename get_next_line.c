/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:35 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/11 18:15:58 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	check_ln_eof(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n' && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strs(char ***to_stock, char *line)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	len = ft_len(line);
	new_line = malloc(len + 1);
	**to_stock = ft_strdup(ft_strchr(line, '\n'));
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free (line);
	return (new_line);
}

static char	*ft_read(char **to_stock, char *line, int fd)
{
	ssize_t	count;
	char	*buff;

	count = 1;
	buff = malloc(1 + 1);
	while (count > 0)
	{
		ft_bzero(buff, 1 + 1);
		if (check_ln_eof(line))
		{
			free (buff);
			return (ft_strs(&to_stock, line));
		}
		count = read(fd, buff, 1);
		if (count < 0)
		{
			free(buff);
			return (0);
		}
		line = ft_strjoin_one(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*to_stock;
	char		*line;

	line = 0;
	if (fd < 0 || 10 <= 0)
		return (0);
	if (to_stock)
	{
		line = ft_strdup(to_stock);
		free (to_stock);
		to_stock = NULL;
	}
	line = ft_read(&to_stock, line, fd);
	if (line && *line)
	{
		return (line);
	}
	free (line);
	return (0);
}

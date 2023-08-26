/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:33 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)s;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}

char	*ft_strjoin_one(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*to_return;

	j = 0;
	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	to_return = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!to_return)
		ft_error("allocation failed");
	while (s1[i] != '\0')
	{
		to_return[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		to_return[i] = s2[j];
		i++;
		j++;
	}
	to_return[i] = '\0';
	free ((char *)s1);
	return (to_return);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (((char *)s + i + 1));
		i++;
	}
	if (c == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

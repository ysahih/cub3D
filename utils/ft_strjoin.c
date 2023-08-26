/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:26 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static char	*ft_errorr(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*to_return;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (ft_errorr(s1, s2));
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
		to_return[i + j] = s2[j];
		j++;
	}
	to_return[j + i] = '\0';
	if (*s1)
		free((void *)s1);
	return (to_return);
}

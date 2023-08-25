/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:22 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/11 18:15:45 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*new_s;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	new_s = malloc(s_len + 1);
	if (!new_s)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

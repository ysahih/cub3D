/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:22 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/26 14:55:36 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

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
		ft_error("allocation failed");
	}
	while (s[i] != '\0')
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:10 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*my_dest;
	unsigned char	*my_src;
	size_t			i;

	if (n < 0)
		n = ft_strlen(src);
	my_dest = (unsigned char *)dest;
	my_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (dest);
}

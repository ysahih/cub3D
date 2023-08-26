/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:51:36 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/26 18:41:45 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	*ft_calloc(size_t size)
{
	void	*s;

	s = malloc(size);
	if (!s)
	{
		ft_error("malloc failed");
	}
	ft_bzero (s, size);
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texuters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:53:13 by ysahih            #+#    #+#             */
/*   Updated: 2023/08/26 17:53:16 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

mlx_image_t	*load_png(t_data *info, char *s)
{
	mlx_texture_t	*txt;
	mlx_image_t		*image;

	if (!s)
		return (0);
	txt = mlx_load_png(s);
	if (!txt)
		ft_error("failed to load png");
	image = mlx_texture_to_image(info->mlx.mlx, txt);
	if (!image)
		ft_error("failed to get image from texture");
	return (image);
}

void	get_textures(t_data *info)
{
	info->mlx.ea_image = load_png(info, info->sources.ea);
	info->mlx.so_image = load_png(info, info->sources.so);
	info->mlx.we_image = load_png(info, info->sources.we);
	info->mlx.no_image = load_png(info, info->sources.no);
}

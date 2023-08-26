/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:18:47 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_so_one(t_data *info)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "SO ", 3) == 0)
		{
			if (info->map2d[i][3] && check == 0)
				check = 1;
			else
				ft_error("duplicated SO");
		}
		i++;
	}
}

void	ft_we_one(t_data *info)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "WE ", 3) == 0)
		{
			if (info->map2d[i][3] && check == 0)
				check = 1;
			else
				ft_error("duplicated WE");
		}
		i++;
	}
}

void	ft_ea_one(t_data *info)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "EA ", 3) == 0)
		{
			if (info->map2d[i][3] && check == 0)
				check = 1;
			else
				ft_error("duplicated EA");
		}
		i++;
	}
}

void	ft_no_one(t_data *info)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "NO ", 3) == 0)
		{
			if (info->map2d[i][3] && check == 0)
				check = 1;
			else
				ft_error("duplicated NO");
		}
		i++;
	}
}

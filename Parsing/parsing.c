/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:17:01 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_f_one(t_data *info)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "F ", 2) == 0 && check == 0)
		{
			check = 1;
		}
		else if (ft_strncmp(info->map2d[i], "F ", 2) == 0 && check == 1)
			ft_error("duplicated arguments");
		i++;
	}
}

void	ft_c_one(t_data *info)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "C ", 2) == 0 && check == 0)
		{
			check = 1;
		}
		else if (ft_strncmp(info->map2d[i], "C ", 2) == 0 && check == 1)
			ft_error("duplicated arguments");
		i++;
	}
}

void	check_av(char *av)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (av)
	{
		if (av[len - 1] != 'b' || av[len - 2] != 'u'
			|| av[len - 3] != 'c' || av[len - 4] != '.')
			ft_error("error extention");
	}
}

void	check_map(char *map)
{
	int	i;

	if (!map)
		ft_error("empty");
	i = 0;
	while (map[i] && map[i] == '\n')
		i++;
	if (!map[i])
		ft_error("empty");
}

void	ft_parsing(t_data *info)
{
	check_arguments(info);
	argument_under_map(info);
	ft_arguments_to_space(info);
	ft_rect(info);
	remove_space_lines(info);
	ft_check_letters(info);
	check_inside(info);
}

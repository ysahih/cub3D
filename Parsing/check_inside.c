/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahih <ysahih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:16:20 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/27 00:08:13 by ysahih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_check_character3(t_check *check)
{
	if (check->check[0] + check->check[1]
		+ check->check[2] + check->check[3] != 4)
		ft_error("invalid map");
}

void	ft_check_character2(t_data *info, int i, int j, t_check *check)
{
	while (check->tmp_i < ft_len(info->map2d))
	{
		if (info->map2d[check->tmp_i][j] == '1')
			check->check[2] = 1;
		if (info->map2d[check->tmp_i][j] != '0'
		&& info->map2d[check->tmp_i][j] != 'N'
		&& info->map2d[check->tmp_i][j] != 'S'
		&& info->map2d[check->tmp_i][j] != 'W'
		&& info->map2d[check->tmp_i][j] != 'E')
			break ;
		check->tmp_i++;
	}
	while (check->tmp_j < ft_strlen(info->map2d[0]))
	{
		if (info->map2d[i][check->tmp_j] == '1')
			check->check[3] = 1;
		if (info->map2d[i][check->tmp_j] != '0'
		&& info->map2d[i][check->tmp_j] != 'N'
		&& info->map2d[i][check->tmp_j] != 'S'
		&& info->map2d[i][check->tmp_j] != 'W'
		&& info->map2d[i][check->tmp_j] != 'E')
			break ;
		check->tmp_j++;
	}
	ft_check_character3(check);
}

void	ft_check_character1(t_data *info, int i, int j, t_check *check)
{
	while (check->tmp_j >= 0)
	{
		if (info->map2d[i][check->tmp_j] == '1')
			check->check[1] = 1;
		if (info->map2d[i][check->tmp_j] != '0'
		&& info->map2d[i][check->tmp_j] != 'N'
		&& info->map2d[i][check->tmp_j] != 'S'
		&& info->map2d[i][check->tmp_j] != 'W'
		&& info->map2d[i][check->tmp_j] != 'E')
			break ;
		check->tmp_j--;
	}
	check->tmp_i = i;
	check->tmp_j = j;
	ft_check_character2(info, i, j, check);
}

void	ft_check_character(t_data *info, int i, int j)
{
	t_check	check;

	check.tmp_i = i;
	check.tmp_j = j;
	check.check[0] = 0;
	check.check[1] = 0;
	check.check[2] = 0;
	check.check[3] = 0;
	while (check.tmp_i >= 0)
	{
		if (info->map2d[check.tmp_i][j] == '1')
			check.check[0] = 1;
		if (info->map2d[check.tmp_i][j] != '0'
		&& info->map2d[check.tmp_i][j] != 'N'
		&& info->map2d[check.tmp_i][j] != 'S'
		&& info->map2d[check.tmp_i][j] != 'W'
		&& info->map2d[check.tmp_i][j] != 'E')
			break ;
		check.tmp_i--;
	}
	ft_check_character1(info, i, j, &check);
}

void	check_inside(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (info->map2d[i])
	{
		j = 0;
		while (info->map2d[i][j])
		{
			if (info->map2d[i][j] == '0'
			|| info->map2d[i][j] == 'N' ||
			info->map2d[i][j] == 'S' ||
			info->map2d[i][j] == 'E' ||
			info->map2d[i][j] == 'W')
				ft_check_character(info, i, j);
			j++;
		}
		i++;
	}
}

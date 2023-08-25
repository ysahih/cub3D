/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_under_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:16:12 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/25 14:16:12 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	check_under_map(t_data *info, int i)
{
	while (info->map2d[i] && info->map2d[i][0])
	{
		if (info->map2d[i][0] == 'N'
		|| info->map2d[i][0] == 'S'
		|| info->map2d[i][0] == 'F'
		|| info->map2d[i][0] == 'W'
		|| info->map2d[i][0] == 'C'
		|| info->map2d[i][0] == 'E')
		{
			ft_error();
		}
		i++;
	}
}

void	argument_under_map(t_data *info)
{
	int	i;

	i = 0;
	while (info->map2d[i])
	{
		if (info->map2d[i][0] == '1')
		{
			check_under_map(info, i);
			break ;
		}
		i++;
	}
}

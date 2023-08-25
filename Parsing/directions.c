/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:16:25 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/25 14:20:16 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*ft_so(t_data *info)
{
	char	*to_return;
	int		i;

	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "SO ", 3) == 0)
		{
			if (info->map2d[i][3])
				return (ft_strdup(&(info->map2d[i][3])));
			else
				ft_error();
		}
		i++;
	}
	ft_error();
	return (NULL);
}

char	*ft_we(t_data *info)
{
	char	*to_return;
	int		i;

	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "WE ", 3) == 0)
		{
			if (info->map2d[i][3])
				return (ft_strdup(&(info->map2d[i][3])));
			else
				ft_error();
		}
		i++;
	}
	ft_error();
	return (NULL);
}

char	*ft_ea(t_data *info)
{
	char	*to_return;
	int		i;

	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "EA ", 3) == 0)
		{
			if (info->map2d[i][3])
				return (ft_strdup(&(info->map2d[i][3])));
			else
				ft_error();
		}
		i++;
	}
	ft_error();
	return (NULL);
}

char	*ft_no(t_data *info)
{
	char	*to_return;
	int		i;

	i = 0;
	while (info->map2d[i])
	{
		if (ft_strncmp(info->map2d[i], "NO ", 3) == 0)
		{
			if (info->map2d[i][3])
				return (ft_strdup(&(info->map2d[i][3])));
			else
				ft_error();
		}
		i++;
	}
	ft_error();
	return (NULL);
}

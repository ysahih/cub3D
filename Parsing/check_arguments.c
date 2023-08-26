/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:16:16 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/26 17:28:50 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	check_two_camas(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
			ft_error("not number");
		if (str[i] == ',')
			count ++;
		i++;
	}
	if (count != 2)
	{
		ft_error("not two camas");
	}
}

char	*first_cama(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ',')
		i++;
	return (&str[i + 1]);
}

char	*second_coma(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ',')
		i++;
	i++;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i + 1] == '\0')
		ft_error("cama");
	return (&str[i + 1]);
}

void	ft_check_rgb(char *str, char c, t_data *info)
{
	int	r ;
	int	g ;
	int	b ;

	check_two_camas(str);
	if(str[0] == ',')
		ft_error("cama");
	r = ft_atoi(str);
	g = ft_atoi(first_cama(str));
	b = ft_atoi(second_coma(str));
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		ft_error("cama");
	if (c == 'f')
	{
		info->sources.f_r = r;
		info->sources.f_g = g;
		info->sources.f_b = b;
	}
	else
	{
		info->sources.c_r = r;
		info->sources.c_g = g;
		info->sources.c_b = b;
	}
}

void	check_arguments(t_data *info)
{
	char	*f;
	char	*c;

	info->sources.no = ft_no(info);
	info->sources.so = ft_so(info);
	info->sources.we = ft_we(info);
	info->sources.ea = ft_ea(info);
	ft_no_one(info);
	ft_so_one(info);
	ft_we_one(info);
	ft_ea_one(info);
	f = ft_f(info);
	c = ft_c(info);
	ft_f_one(info);
	ft_c_one(info);
	ft_check_rgb(f, 'f', info);
	ft_check_rgb(c, 'c', info);
	free(f);
	free(c);
}

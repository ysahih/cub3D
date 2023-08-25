/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:16:28 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/25 14:16:28 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static int	ft_tab_or_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == ' ' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_result_to_return(const char *str, int sign)
{
	long long	res;
	int			i;
	long long	temp;

	temp = 0;
	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = res;
		res = res * 10 + str[i] - '0';
		i++;
		if (temp != res / 10 && sign == 1)
			return (-1);
		if (temp != res / 10 && sign == -1)
			return (0);
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	long long	i;
	long long	sign;

	i = 0;
	sign = 1;
	while (ft_tab_or_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	return (ft_result_to_return (&str[i], sign));
}

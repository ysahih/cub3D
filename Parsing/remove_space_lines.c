/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:17:14 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/26 14:52:41 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	check_empty_line1(char **map2d1, int i, int first_line, int last_line)
{
	int	j;

	while (map2d1[i - 1] && map2d1[i])
	{
		j = 0;
		while (map2d1[i - 1] && map2d1[i]
			&& (map2d1[i][j] && (map2d1[i][j] == ' '
			|| map2d1[i][j] == '1')))
			j++;
		if ((map2d1[i - 1] && map2d1[i]
				&& (!map2d1[i][j] || map2d1[i][j] == '\n')
			&& j != 0))
		{
			last_line = i;
			break ;
		}
		i++;
	}
	while (first_line < last_line)
	{
		if (map2d1[first_line] && map2d1[first_line][0] == '\n')
			ft_error("map error");
		first_line++;
	}
}

void	check_empty_line(char **map2d1)
{
	int	first_line_index ;
	int	last_line_index ;
	int	i ;
	int	j ;

	first_line_index = -1;
	last_line_index = -1;
	i = 0;
	j = 0;
	while (map2d1[i])
	{
		j = 0;
		while (map2d1[i][j] && (map2d1[i][j] == ' ' || map2d1[i][j] == '1'))
			j++;
		if ((!map2d1[i][j] || map2d1[i][j] == '\n') && j != 0)
		{
			first_line_index = i;
			break ;
		}
		i++;
	}
	i++;
	check_empty_line1(map2d1, i, first_line_index, last_line_index);
}

int	ft_lines_to_alloc(char **map2d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map2d[i])
	{
		if (check_all_spaces(map2d[i]) == 0)
			count++;
		i++;
	}
	return (count);
}

int	check_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	remove_space_lines(t_data *info)
{
	int		lines_to_alloc ;
	char	**new_array ;
	int		i ;
	int		count ;

	lines_to_alloc = ft_lines_to_alloc(info->map2d);
	new_array = malloc((lines_to_alloc + 1) * sizeof(char *));
	if(!new_array)
		ft_error("allocation failed");
	i = 0;
	count = 0;
	new_array[lines_to_alloc] = NULL;
	while (info->map2d[i])
	{
		if (check_all_spaces(info->map2d[i]) == 0)
		{
			new_array[count] = ft_strdup(info->map2d[i]);
			count++;
		}
		i++;
	}
	info->map2d = new_array;
}

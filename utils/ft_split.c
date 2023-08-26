/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbarka <isbarka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:56:19 by isbarka           #+#    #+#             */
/*   Updated: 2023/08/26 14:55:33 by isbarka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static char	**str_count(char **str, const char *s, char c)
{
	int	i ;
	int count = 0;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			s++;
		}
		while (*s && *s != c)
		s++;
		count = 0;
		while (*s && *s == c)
		{
			s++;
		}
	}
	str = malloc((i + 1) * sizeof(char *));
	if (!str)
	{
		free(str);
		ft_error("allocation failed");
	}
	str[i] = 0;
	return (str);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_word(const char *s, char c)
{
	char	*str;
	int		len;

	len = word_len(s, c);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		ft_error("allocation failed");
	}
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}

static char	**ft_free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int count;

	if (!s)
		return (0);
	str = NULL;
	str = str_count(str, s, c);
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[i] = ft_word(s, c);
			if (!str[i])
				return (ft_free_all(str));
			i++;
		}
		while (*s && *s != c)
			s++;
		count = 0;
		while (*s && *s == c)
		{
			s++;
		}
	}
	return (str);
}

// int main()
// {
// 	char *s = "ismail---barka";
// 	char **strs = ft_split(s, '-');
// 	int i = 0;
// 	while(strs[i])
// 	{
// 		printf("%s\n", strs[i]);
// 		i++;
// 	}
// }
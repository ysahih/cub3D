
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
				ft_error();
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
				ft_error();
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
				ft_error();
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
				ft_error();
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:26:10 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 20:24:55 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cond1_notrectangle(int k, int i, char *str)
{
	if (k != i)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	check_cond1(t_data *vars)
{
	int		i;
	int		j;
	int		k;
	char	*str;
	int		fd;

	fd = open(vars->file, O_RDONLY);
	str = get_next_line(fd);
	i = ft_strlen(str);
	j = 0;
	while (str)
	{
		if (check_map_mur(str, j, vars) == 0)
		{
			free(str);
			return (0);
		}
		k = ft_strlen(str);
		if (check_cond1_notrectangle(k, i, str))
			return (0);
		free(str);
		str = get_next_line(fd);
		j++;
	}
	return (1);
}

int	check_cond2_else(t_data *vars, char *str, int fd)
{
	t_data	*bom;

	bom = vars;
	free(str);
	close(fd);
	return (1);
}

int	check_cond2(t_data *vars)
{
	int		i;
	int		fd;
	int		lmax;
	char	*str;

	lmax = max_line_file(vars);
	fd = open(vars->file, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (i == lmax - 1)
		{
			if (check_map_last_line(str, fd) == 1)
				return (1);
			else if (check_cond2_else(vars, str, fd))
				return (0);
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

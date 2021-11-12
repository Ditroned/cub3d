/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:08:21 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 12:08:21 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_1(t_data *vars, int i, int x, int fd)
{
	char	*str;
	int		y;

	y = 0;
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		draw_3(str, &x, &y, vars);
		y += 32;
		x = 0;
		free(str);
		str = get_next_line(fd);
	}
}

void	draw(t_data *vars)
{
	int	fd;
	int	i;
	int	x;
	int	y;

	fd = open(vars->file, O_RDONLY);
	i = 0;
	x = 0;
	y = 0;
	draw_1(vars, i, x, fd);
	close(fd);
}

int	checkpos(t_data *vars, int x, int y)
{
	int		fd;
	char	*str;
	int		yy;

	vars->i += 0;
	if (x < 0 || y < 0)
		return (0);
	yy = y;
	fd = open(vars->file, O_RDONLY);
	str = get_next_line(fd);
	while (yy-- > 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	if (str[x] == '0' || str[x] == 'P' || str[x] == 'C' || str[x] == 'E')
	{
		free(str);
		close(fd);
		return (1);
	}
	free(str);
	close(fd);
	return (0);
}

int	checkpos_e(t_data *vars, int x, int y)
{
	int		fd;
	char	*str;
	int		yy;

	vars->i += 0;
	if (x < 0 || y < 0)
		return (0);
	yy = y;
	fd = open(vars->file, O_RDONLY);
	str = get_next_line(fd);
	while (yy-- > 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	if (str[x] == 'E')
	{
		vars->e = 1;
		close(fd);
		free(str);
		return (1);
	}
	free(str);
	close(fd);
	return (0);
}

int	checkpos_c(t_data *vars, int x, int y)
{
	int		fd;
	char	*str;
	int		yy;

	vars->i += 0;
	if (x < 0 || y < 0)
		return (0);
	yy = y;
	fd = open(vars->file, O_RDONLY);
	str = get_next_line(fd);
	while (yy-- > 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	if (str[x] == 'C')
	{
		close(fd);
		free(str);
		return (1);
	}
	free(str);
	close(fd);
	return (0);
}

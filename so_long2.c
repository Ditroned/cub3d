/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:08:37 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/11 16:49:59 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*str_process(char *s1)
{
	char	*s2;

	s2 = ft_select2(s1);
	free(s1);
	s1 = s2;
	return (s1);
}

int	cheker(int	*ret, char **str)
{
	if (*ret == 0 && !*str)
	{
		free(str);
		*str = 0;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*str = NULL;
	char		*line;

	ret = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret == 0 && str == 0) || ret == -1)
			return (NULL);
		buf[ret] = 0;
		line = str;
		str = ft_strjoin(str, buf);
		free(line);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (cheker(&ret, &str))
		return (NULL);
	line = ft_select(str);
	str = str_process(str);
	return (line);
}

void	my_put_img(t_data *vars, int obj, int x, int y)
{
	int		b;
	int		c;
	void	*image;

	b = 0;
	c = 0;
	if (obj == 0)
		image = mlx_xpm_file_to_image(vars->mlx, "./empty.xpm", &b, &c);
	if (obj == 1)
		image = mlx_xpm_file_to_image(vars->mlx, "./wall.xpm", &b, &b);
	if (obj == 67)
		image = mlx_xpm_file_to_image(vars->mlx, "./collectible.xpm", &b, &b);
	if (obj == 69)
		image = mlx_xpm_file_to_image(vars->mlx, "./exit.xpm", &b, &b);
	if (obj == 80 && vars->player == 0)
	{
		image = mlx_xpm_file_to_image(vars->mlx, "./player.xpm", &b, &b);
		vars->player = 1;
		vars->posx = x;
		vars->posy = y;
	}
	else if (obj == 80 && vars->player != 0)
		image = mlx_xpm_file_to_image(vars->mlx, "./empty.xpm", &b, &b);
	mlx_put_image_to_window(vars->mlx, vars->win, image, x, y);
}

void	draw_3(char	*str, int *x, int *y, t_data *vars)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			my_put_img(vars, 0, *x, *y);
		if (str[i] == '1')
			my_put_img(vars, 1, *x, *y);
		if (str[i] == 'C')
			my_put_img(vars, 67, *x, *y);
		if (str[i] == 'E')
			my_put_img(vars, 69, *x, *y);
		if (str[i] == 'P')
			my_put_img(vars, 80, *x, *y);
		*x += 32;
		i++;
	}
}

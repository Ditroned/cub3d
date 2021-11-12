/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:52:08 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 12:04:58 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_con3(t_data *vars, int i)
{
	int		fd;
	char	*str;

	fd = open(vars->file, O_RDONLY);
	if (fd < 0 || fd > 1023)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str[i] != 0 && str[i] != '\n')
		{
			if (str[i] == 'C')
				vars->c = 1;
			if (str[i] == 'E')
				vars->e = 1;
			if (str[i] == 'P')
				vars->p = 1;
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	check_all_condition(t_data *vars)
{
	int	i;

	i = 0;
	if (check_con3(vars, i) == 0)
	{
		write(1, "Error\n", 6);
		write(1, "Map failed\n", 11);
		return (0);
	}
	if (((check_cond1(vars) && check_cond2(vars)))
		&& (vars->e >= 1 && vars->c >= 1 && vars->p >= 1))
		return (1);
	write(1, "Error\n", 6);
	write(1, "Map failed\n", 11);
	return (0);
}

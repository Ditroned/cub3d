/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:08:16 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 12:08:16 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision_cond(t_data *vars, int keycode)
{
	if ((keycode == 13 && vars->posy == 0)
		|| (keycode == 1 && vars->posy == vars->posymax)
		|| (keycode == 2 && vars->posx == vars->posxmax)
		|| (keycode == 0 && vars->posx == 0))
		return (1);
	return (0);
}

int	check_collision(t_data *vars, int keycode)
{
	if (check_collision_cond(vars, keycode))
		return (1);
	if (keycode == 13 && vars->posy != 0)
	{
		if (checkpos(vars, vars->posx / 32, (vars->posy - 32) / 32))
			return (1);
	}
	if (keycode == 1 && vars->posy != vars->posymax)
	{
		if (checkpos(vars, vars->posx / 32, (vars->posy + 32) / 32))
			return (1);
	}
	if (keycode == 2 && vars->posx != vars->posxmax)
	{
		if (checkpos(vars, (vars->posx + 32) / 32, (vars->posy) / 32))
			return (1);
	}
	if (keycode == 0 && vars->posx != 0)
	{
		if (checkpos(vars, (vars->posx - 32) / 32, (vars->posy) / 32))
			return (1);
	}
	return (0);
}

int	check_current_letter_1(t_data *vars, int keycode)
{
	if (vars->posy == 0)
	{
		if (keycode == 13)
			return (0);
	}
	if (vars->posy == vars->posymax)
	{
		if (keycode == 1)
			return (0);
	}
	if (vars->posx == vars->posxmax)
	{
		if (keycode == 2)
			return (0);
	}
	if (vars->posx == 0)
	{
		if (keycode == 0)
			return (0);
	}
	return (1);
}

int	check_current_letter(
		t_data *vars, int keycode)
{
	int		fd;
	char	*str;
	int		called;
	int		i;
	int		x;

	called = vars->posy / 32;
	x = vars->posx / 32;
	i = 0;
	fd = open(vars->file, O_RDONLY);
	str = get_next_line(fd);
	if (check_current_letter_1(vars, keycode) == 0)
	{
		close(fd);
		free(str);
		return (0);
	}
	close(fd);
	free(str);
	return (1);
}

void	key_hook_cond_check_mov2(
		t_data *vars, int keycode, void *empty, void *player)
{
	if (keycode == 0)
	{
		mlx_put_image_to_window(
			vars->mlx, vars->win, empty, vars->posx, vars->posy);
		if (check_current_letter(vars, keycode) && checkpos(vars, (
					vars->posx - 32) / 32, (vars->posy) / 32))
			vars->posx -= 32;
		mlx_put_image_to_window(
			vars->mlx, vars->win, player, vars->posx, vars->posy);
	}
}

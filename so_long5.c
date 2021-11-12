/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:08:11 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 20:23:42 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_cond_check_mov(
			t_data *vars, int keycode, void *empty, void *player)
{
	if (keycode == 13)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			empty, vars->posx, vars->posy);
		if (check_current_letter(vars, keycode) && checkpos(
				vars, vars->posx / 32, (vars->posy - 32) / 32))
			vars->posy -= 32;
		mlx_put_image_to_window(vars->mlx,
			vars->win, player, vars->posx, vars->posy);
	}
	else if (keycode == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, empty,
			vars->posx, vars->posy);
		if (check_current_letter(vars, keycode)
			&& checkpos(vars, vars->posx / 32, (vars->posy + 32) / 32))
			vars->posy += 32;
		mlx_put_image_to_window(
			vars->mlx, vars->win, player, vars->posx, vars->posy);
	}
	key_hook_cond_check_mov2(vars, keycode, empty, player);
}

void	key_hook_cond_checkc(t_data *vars)
{
	struct d_list	*new;

	if (checkpos_c(vars, vars->posx / 32, vars->posy / 32))
	{
		new = vars->new;
		while (new != NULL)
		{
			if ((vars->posx / 32 == (new->x))
				&& (vars->posy / 32 == (new->y)) && (new->oui == 1))
			{
				vars->collected += 1;
				new->oui = 0;
				break ;
			}
			new = new->next;
		}
	}
}

void	key_hook_cond_check1(
			t_data *v, int keycode, void *empty, void *exitmap)
{
	int		b;
	void	*p;

	b = 0;
	p = exitmap;
	p = mlx_xpm_file_to_image(v->mlx, "./player.xpm", &b, &b);
	if (keycode == 2)
	{
		mlx_put_image_to_window(
			v->mlx, v->win, empty, v->posx, v->posy);
		if (check_current_letter(v, keycode)
			&& checkpos(v, (v->posx + 32) / 32, (v->posy) / 32))
			v->posx += 32;
		mlx_put_image_to_window(v->mlx, v->win, p, v->posx, v->posy);
	}
	if (checkpos_e(v, v->posx / 32, v->posy / 32))
	{
		if (v->collectmax == v->collected)
		{
			mlx_destroy_window(v->mlx, v->win);
			ft_lstclear(&(v->first));
			printf("%d\n", v->step + 1);
			exit(EXIT_SUCCESS);
		}
	}
}

int	key_hook2(int keycode, t_data *vars, int oldx, int oldy)
{
	void	*empty;
	void	*player;
	void	*exitmap;
	int		b;

	b = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_lstclear(&(vars->first));
		exit(EXIT_SUCCESS);
	}
	exitmap = mlx_xpm_file_to_image(vars->mlx, "./exit.xpm", &b, &b);
	empty = mlx_xpm_file_to_image(vars->mlx, "./empty.xpm", &b, &b);
	player = mlx_xpm_file_to_image(vars->mlx, "./player.xpm", &b, &b);
	key_hook_cond_check_mov(vars, keycode, empty, player);
	key_hook_cond_check1(vars, keycode, empty, exitmap);
	if (((oldx * 32) != vars->posx) || ((oldy * 32) != vars->posy))
	{
		if (checkpos_e(vars, oldx, oldy))
			mlx_put_image_to_window(
				vars->mlx, vars->win, exitmap, oldx * 32, oldy * 32);
	}
	key_hook_cond_checkc(vars);
	return (0);
}

int	key_hook(int keycode, t_data *vars)
{
	int	oldx;
	int	oldy;
	int	newx;
	int	newy;

	oldx = vars->posx / 32;
	oldy = vars->posy / 32;
	newx = oldx;
	newy = oldy;
	key_hook2(keycode, vars, oldx, oldy);
	if ((oldx != (vars->posx / 32)) || (oldy != (vars->posy / 32)))
	{
		vars->step += 1;
		printf("%d\n", vars->step);
	}
	return (0);
}

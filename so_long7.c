/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:07:55 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 21:00:43 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	boucle_while_main(char *str, int i, struct d_list **new, t_data *vars)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (str[k] == 'C')
		{
			vars->collectmax += 1;
			vars->c = 1;
			if (!(vars->new))
			{
				*new = ifnot_first(vars, i, k);
				if (!(vars->new))
					return (0);
			}
			else
			{
				if (else_consommable(new, k, i) == 0)
					return (0);
			}
		}
		k++;
	}
	return (1);
}

void	boucle_str2(t_data *vars, char *str, int *i, int *j)
{
	if (*i == 0)
	{
		*j = ft_strlen(str) - 1;
		(*vars).posxmax = (*j - 1) * 32;
	}
	if (char_in_str(str, 'P'))
	{
		vars->p = 1;
		(*vars).posy = *i * 32;
		(*vars).posx = pos_char_in_str(str, 'P') * 32;
	}
	*i += 1;
}

void	i_j_set0(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

int	boucle_str(char *str, int *a, t_data *vars, int *b)
{
	int				fd;
	int				i;
	int				j;
	struct d_list	*new;

	new = NULL;
	fd = open(vars->file, O_RDONLY);
	str = get_next_line(fd);
	i_j_set0(&i, &j);
	while (str)
	{
		if (boucle_while_main(str, i, &new, vars) == 0)
		{
			close(fd);
			free(str);
			return (0);
		}
		boucle_str2(vars, str, &i, &j);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	*a = i;
	*b = j;
	return (1);
}

int	matrice_map(char *matrice, t_data *vars)
{
	int				fd;
	struct d_list	*new;
	char *str;
	int	i;
	int j;

	new = NULL;
	i = 0;
	j = 0;
	fd = open(vars->file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str[i])
		{
			matrice[j * (vars->posxmax / 32) + i] = str[i];
			printf("%c", matrice[j * (vars->posxmax / 32) + i]);
			i++;
		}
		j++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	redclose(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->first != NULL)
		ft_lstclear(&(vars->first));
	exit(EXIT_SUCCESS);
}

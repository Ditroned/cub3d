/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:50:34 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 20:22:22 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	max_line_file(t_data *vars)
{
	int		i;
	int		fd;
	char	*str;

	fd = open(vars->file, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	check_map_last_line(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != 0 && (str[i] == '1' || str[i] == '\n'))
		i++;
	if (str[i] == 0)
	{
		if (fd == -5)
			return (1);
		close(fd);
		free(str);
		return (1);
	}
	return (0);
}

int	check_map_mur(char *str, int j, t_data *vars)
{
	int	i;
	int	imax;
	int	jmax;

	imax = ft_strlen(str) - 2;
	jmax = max_line_file(vars);
	i = 0;
	while (i < imax)
	{
		if (!(str[i] == '1' || str[i] == '0'
				|| str[i] == 'C' || str[i] == 'P' || str[i] == 'E'))
			return (0);
		i++;
	}
	if (j == 0)
	{
		if (check_map_last_line(str, -5) == 0)
			return (0);
	}
	if (j != 0 && j < jmax - 1)
	{
		if (!(str[0] == '1' && str[ft_strlen(str) - 2] == '1'))
			return (0);
	}
	return (1);
}

void	ft_lstclear(void **lst)
{
	struct d_list	*second;
	struct d_list	*first;

	if (!lst || !*lst)
		return ;
	first = *lst;
	while (first->next)
	{
		second = first->next;
		free(first);
		first = second;
	}
	free(first);
	*lst = NULL;
}

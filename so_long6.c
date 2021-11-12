/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:08:07 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 20:23:34 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	pos_char_in_str(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

struct d_list	*ft_lstnew(int x, int y)
{
	struct d_list	*new;

	new = malloc(sizeof(struct d_list) * 1);
	if (!new)
		return (new);
	new->x = x;
	new->y = y;
	new->oui = 1;
	new->next = NULL;
	return (new);
}

void	*ifnot_first(t_data *vars, int i, int k)
{
	struct d_list	*first;
	struct d_list	*new;

	first = malloc(sizeof(*new));
	if (!first)
		return (0);
	(*vars).new = first;
	new = first;
	new->x = k;
	new->y = i;
	new->oui = 1;
	new->next = NULL;
	vars->first = new;
	return (first);
}

int	else_consommable(struct d_list **new, int k, int i)
{
	struct d_list	*swap;

	swap = ft_lstnew(k, i);
	if (!swap)
		return (0);
	(*new)->next = swap;
	*new = swap;
	return (1);
}

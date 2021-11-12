/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:44:02 by ppizzo            #+#    #+#             */
/*   Updated: 2021/10/09 21:05:16 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# define BUFFER_SIZE 1

typedef struct d_list
{
	int		x;
	int		y;
	int		oui;
	void	*next;
}			t_list;

typedef struct s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	char	*file;
	int		i;
	int		j;
	int		player;
	int		e;
	int		c;
	int		p;
	int		step;
	int		posx;
	int		posy;
	int		posxmax;
	int		posymax;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		collectmax;
	int		collected;
	void	*first;
	void	*new;
}			t_data;

size_t			ft_strlen(const char *s);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strchr(const char *s, int c);

char			*ft_select(char *buf);

char			*ft_select2(char *buf);

char			*str_process(char *s1);

int				cheker(int *ret, char **str);

char			*get_next_line(int fd);

void			my_put_img(t_data *vars, int obj, int x, int y);

int				max_line_file(t_data *vars);

int				check_map_last_line(char *str, int fd);

int				draw_main(t_data *vars);

int				check_map_mur(char *str, int j, t_data *vars);

int				check_cond1(t_data *vars);

int				check_cond2(t_data *vars);

int				check_con3(t_data *vars, int i);

int				check_all_condition(t_data *vars);

void			draw_3(char	*str, int *x, int *y, t_data *vars);

void			my_put_img(t_data *vars, int obj, int x, int y);

int				checkpos_c(t_data *vars, int x, int y);

int				checkpos_e(t_data *vars, int x, int y);

int				checkpos(t_data *vars, int x, int y);

void			draw(t_data *vars);

void			draw_1(t_data *vars, int i, int x, int fd);

void			key_hook_cond_check_mov2(
					t_data *vars, int keycode, void *empty, void *player);

int				check_current_letter(t_data *vars, int keycode);

int				check_current_letter_1(t_data *vars, int keycode);

int				check_collision(t_data *vars, int keycode);

int				check_collision_cond(t_data *vars, int keycode);

int				key_hook(int keycode, t_data *vars);

int				key_hook2(int keycode, t_data *vars, int oldx, int oldy);

void			key_hook_cond_check1(
					t_data *vars, int keycode, void *empty, void *exitmap);

void			key_hook_cond_checkc(t_data *vars);

void			key_hook_cond_check_mov(
					t_data *vars, int keycode, void *empty, void *player);

int				else_consommable(struct d_list **new, int k, int i);

void			*ifnot_first(t_data *vars, int i, int k);

struct	d_list	*ft_lstnew(int x, int y);

int				pos_char_in_str(char *str, char c);

int				char_in_str(char *str, char c);

int				redclose(t_data *vars);

int				boucle_str(char *str, int *a, t_data *vars, int *b);

void			i_j_set0(int *i, int *j);

void			boucle_str2(t_data *vars, char *str, int *i, int *j);

int				boucle_while_main(char *str, int i,
					struct d_list **new, t_data *vars);

int				check_cond2_else(t_data *vars, char *str, int fd);

int				check_cond1_notrectangle(int k, int i, char *str);

void			ft_lstclear(void **lst);

int	matrice_map(char *matrice, t_data *vars);

#endif

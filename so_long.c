/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppizzo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:08:58 by ppizzo            #+#    #+#             */
/*   Updated: 2021/11/11 22:44:31 by ppizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	draw_main(t_data *vars)
{
	int		i;
	int		j;
	char	*str;
	char *matrice;

	

	i = 0;
	j = 0;
	str = NULL;
	if (boucle_str(str, &i, vars, &j) == 0)
		return (0);
	
	vars->posymax = (i - 1) * 32;
	vars->win = mlx_new_window(vars->mlx, j * 32, i * 32, "Hello world!");
	vars->img = mlx_new_image(vars->mlx, j * 32, i * 32);
	vars->addr = mlx_get_data_addr(vars->img,
			&vars->bits_per_pixel, &vars->line_length, &vars->endian);
	//draw(vars);
	matrice = malloc((vars->posxmax/32 + 1) * (vars->posymax/32 + 1));
	if (!matrice)
	return (0);
	matrice_map(matrice, vars);
	float	k;
	k = 0;
	int posx = 500;
	int posy = 200;
	float posxinit = (float)posx;
	float	posyinit = (float)posy;
	//int	m = 0;
	j = 0;
	//float px = 500;
	//float py = 200;
	//float dirx = -1;
	//float diry = 0;
	//float planex = 0;
	//float planey = 0.66;
	//float x = 0;
	float camerax = 0;
	//while (x < 100)
	//{
	k = 0;
	float w = 100;
	//int vecty = b * k;
	float u = 0;
	
	k = 0;
	u = 0;
	//float xvar;
	//float yvar;
	float x;
	float y;
	float x0;
	float x1;
	float y0;
	float y1;
	float deltadistx;
	float deltadisty;
	float realdist;
	float sidex;
	float sidey;
	float prpwall;
	int	stepx;
	int stepy;
	int hit;
	int side;
	
	hit = 0;
	side = 0;
	stepx = 0;
	stepy = 0;
	sidex = 0;
	sidey = 0;
	deltadistx = 0;
	deltadisty = 0;
	u = 50;

	//while (u < 100)
	//while (posy + (k * camerax* 0.66) < vars->posymax)
	
		//while (k < 100)
		
		
		
		camerax = (2 * u / w) - 1;
		k = 1;
		x = k;
		y = (k * camerax * 0.66);
		if (x == 0)
		{
			deltadistx = pow(10,32);
		}
		else
		{
			deltadistx = fabsf(1 / k);
		}
		if (y == 0)
		{
			deltadisty = pow(10,32);
		}
		else
		{
			deltadisty = fabs(1 / (k * camerax* 0.66));
		}
		
		k = 0;
		x0 = posx + k;
		y0 = posy + (k * camerax * 0.66);
		k = 1;
		x1 = posx + k;
		y1 = posy + (k * camerax * 0.66);
		k = 0;
		if (x1 == x0)
			stepx = 0;
		if (y1 == y0)
			stepy = 0;
		if (x1 < x0)
		{
			stepx = -1;
			sidex = (posx - (posx/32 * 32)) * deltadistx;
		}
		if (x1 > x0)
		{
			stepx = 1;
			sidex = ((posx/32 * 32) + 32 - posx) * deltadistx;
		}
		if (y1 < y0)
		{
			stepy = -1;
			sidey = (posy - (posy/32 * 32)) * deltadisty;
		}
		if (y1 > y0)
		{
			stepy = 1;
			sidey = ((posy/32 * 32) + 32 - posy) * deltadisty;
		}

		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sidex < sidey)
			{
				sidex += deltadistx;
				posx += stepx * 32;
				side = 0;
			}
			else
			{
				sidey += deltadisty;
				posy += stepy * 32;
				side = 1;
			}
			//Check if ray has hit a wall
			//write(1, "b", 1);
			//printf("%c", matrice[posy/32 * vars->posxmax/32 + posx/32]);
			if (matrice[posy/32 * vars->posxmax/32 + posx/32] != '0')
				hit = 1;
			
		}
		if (side == 0)
			prpwall = sidex - deltadistx;
		else
		{
			prpwall = sidey - deltadisty;
		}
		
		k = 0;
		float disthit;
		//disthit = sqrt((posx*1.0 - posxinit)*(posx*1.0 - posxinit)/64.0 + (posy*1.0 - posyinit)*(posy*1.0 - posyinit)/64.0);
		disthit = (pow((posxinit/32.0 - (double)posx/32.0), 2) + pow((posyinit/32.0 - (double)posy/32.0), 2));
		printf("\n ma disthit %f \n", disthit);
		float testdist;
		int posxmur;
		int	posymur;
		posymur = (int)posy/32;
		posxmur = (int)posx/32;
		testdist = sqrt((posxmur - posxinit/32)*(posxmur - posxinit/32) + (posymur - posyinit/32)*(posymur - posyinit/32));
		//printf("\n ma test dist %f\n", testdist);




		u = 50;
			k = 0;
			posx = 500;
			posy = 200;
			camerax = (2 * u / w) - 1;
		realdist = sqrt(((k/32) * (k/32)) + (((k * camerax * 0.66)/32) * ((k * camerax * 0.66)/32)));
		printf("realdist : %f \n", realdist);
		k = 0;
		while (sqrt(((k/32.0) * (k/32.0)) + (((k * camerax * 0.66)/32) * ((k * camerax * 0.66)/32))) < testdist)
		//while ((posx + k < vars->posxmax + 32) && (posx + k > 0) && (posy + (k * camerax* 0.66) < vars->posymax + 32) && (posy + (k * camerax* 0.66) > 0))
		//while (k < 0)
		{
			camerax = (2 * u / w) - 1;
			//printf("%f", camerax);
			//camerax = 1;
			x = posx + k;
			y = posy + (k * camerax * 0.66);
			//xvar = posx + (cos(60) * (k)) - (((k * camerax * 0.66)) * sin(60));
			//yvar = posy + (sin(60) * (k)) + (((k * camerax * 0.66)) * cos(60));

			//if (fabs((x * x) + (y * y)) >= prpwall)
			//	break ;
			

			my_mlx_pixel_put(vars,500 + k, 200 + (k * camerax* 0.66), 0x00FF0000);
			//my_mlx_pixel_put(vars,xvar, yvar, 0x00FF0000);
			mlx_put_image_to_window(
			vars->mlx, vars->win, vars->img, 0, 0);
			//my_mlx_pixel_put(vars, k, 0, 0x00FF0000);
			//mlx_put_image_to_window(
			//	vars->mlx, vars->win, vars->img, posx, posy + b);
			k+=1;
			//my_mlx_pixel_put(vars, k, j, 0x00FF0000);
			//mlx_put_image_to_window(
			//	vars->mlx, vars->win, vars->img, posx + j, posy + j);
		}
		//u += 30;
		
		
		//u+= 30;

		
		printf("%f et %f",(double)sqrt(((k/32.0) * (k/32.0)) + (((k * camerax * 0.66)/32.0) * ((k * camerax * 0.66)/32.0))), prpwall);
		
		int bonobo;
		bonobo = 0;
		

	while (bonobo < vars->posymax + 32)
	{
		my_mlx_pixel_put(vars, 0, bonobo, 0x00FF0000);
		my_mlx_pixel_put(vars,vars->posxmax + 31, bonobo , 0x00FF0000);
		bonobo++;
		mlx_put_image_to_window(
			vars->mlx, vars->win, vars->img, 0, 0);
	}
				/*

			while (jimbe < vars)
			{
				my_mlx_pixel_put(vars,posx + jimbe, posy + bonobo, 0x00FF0000);
				jimbe++;
				mlx_put_image_to_window(
				vars->mlx, vars->win, vars->img, 0, 0);
			}
			bonobo += 10;
		}
		*/
		
		//x+= 1;
	//}
	

	//draw ray
	//2D to 3D
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 5, redclose, vars);
	mlx_loop(vars->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	vars;
	char	*file;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		write(1, "Map failed\n", 11);
		return (0);
	}
	file = argv[1];
	vars.file = file;
	vars.step = 0;
	vars.player = 0;
	vars.e = 0;
	vars.c = 0;
	vars.p = 0;
	if (check_all_condition(&vars) == 0)
		return (0);
	vars.new = NULL;
	vars.posx = 0;
	vars.posy = 0;
	vars.mlx = mlx_init();
	if (draw_main(&vars) == 0)
		return (0);
	return (0);
}

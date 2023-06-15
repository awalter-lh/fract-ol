/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:20:53 by awalter           #+#    #+#             */
/*   Updated: 2023/05/12 16:20:54 by awalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ppj(t_mlx mlx, t_cmp pix, double arg_one, double arg_two)
{
	t_cmp	start;
	t_cmp	coo;
	int		res;
	char	*dst;

	start.re = (pix.re - mlx.ho) / (int)mlx.zoom;
	start.im = (pix.im - mlx.vo) / (int)mlx.zoom;
	coo.re = arg_one;
	coo.im = arg_two;
	res = mandelbrot_calculation(coo, start, mlx);
	dst = mlx.addr + ((int)pix.im * mlx.ll + (int)pix.re * (mlx.bpp / 8));
	*(unsigned int *)dst = res;
}

void	put_pixel_b(t_mlx mlx, t_cmp pix)
{
	t_cmp	start;
	t_cmp	coo;
	int		res;
	char	*dst;

	start.re = 0;
	start.im = 0;
	coo.re = (pix.re - mlx.ho) / (int)mlx.zoom;
	coo.im = (pix.im - mlx.vo) / (int)mlx.zoom;
	res = bs_calculation(coo, start, mlx);
	dst = mlx.addr + ((int)pix.im * mlx.ll + (int)pix.re * (mlx.bpp / 8));
	*(unsigned int *)dst = res;
}

void	put_pixel_m(t_mlx mlx, t_cmp pix)
{
	t_cmp	start;
	t_cmp	coo;
	int		res;
	char	*dst;

	start.re = 0;
	start.im = 0;
	coo.re = (pix.re - mlx.ho) / (int)mlx.zoom;
	coo.im = (pix.im - mlx.vo) / (int)mlx.zoom;
	res = mandelbrot_calculation(coo, start, mlx);
	dst = mlx.addr + ((int)pix.im * mlx.ll + (int)pix.re * (mlx.bpp / 8));
	*(unsigned int *)dst = res;
}

t_mlx	make_image(t_mlx mlx)
{
	t_cmp		screen;

	screen.re = 0;
	while (screen.re < mlx.width)
	{
		screen.im = 0;
		while (screen.im < mlx.length)
		{
			if (mlx.type == 1)
				put_pixel_m(mlx, screen);
			else if (mlx.type == 2 || (mlx.type == 3 && mlx.arg_one == 1))
				ppj(mlx, screen, -1.6362725450901805, 0.004949883898656804);
			else if (mlx.type == 3 && mlx.arg_one == 2)
				ppj(mlx, screen, -0.5264529058116234, 0.5155711263836267);
			else if (mlx.type == 4)
				put_pixel_b(mlx, screen);
			screen.im++;
		}
		screen.re++;
	}
	return (mlx);
}

void	init_screen(t_mlx *mlx, int type, char **argv)
{
	mlx->width = 1920;
	mlx->length = 1080;
	mlx->hm = mlx->width / 2;
	mlx->vm = mlx->length / 2;
	mlx->ho = mlx->width / 2;
	mlx->vo = mlx->length / 2;
	mlx->zoom = 400;
	mlx->nz = 1;
	mlx->color = 0x000050505;
	mlx->type = type;
	if (type == 3)
		mlx->arg_one = ft_atoi(argv[2]);
}

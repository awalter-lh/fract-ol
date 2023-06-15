/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:16:12 by awalter           #+#    #+#             */
/*   Updated: 2023/05/07 12:16:16 by awalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

int	bs_calculation(t_cmp coo, t_cmp start, t_mlx mlx)
{
	int		i;
	double	mod;
	double	temp;

	i = 0;
	mod = 0;
	while (i < 100 && mod < 4.0)
	{
		temp = fabs(pow(start.re, 2) - pow(start.im, 2) + coo.re);
		start.im = fabs(2 * start.re * start.im + coo.im);
		start.re = temp;
		mod = sqrt(pow(start.re, 2) + pow(start.im, 2));
		i++;
	}
	if (i == 100)
		return (0x00000000);
	else
		return (mlx.color * i);
}

int	mandelbrot_calculation(t_cmp coo, t_cmp start, t_mlx mlx)
{
	int		i;
	double	mod;
	double	temp;

	i = 0;
	mod = 0;
	while (i < 100 && mod < 4.0)
	{
		temp = pow(start.re, 2) - pow(start.im, 2) + coo.re;
		start.im = 2 * start.re * start.im + coo.im;
		start.re = temp;
		mod = sqrt(pow(start.re, 2) + pow(start.im, 2));
		i++;
	}
	if (i == 100)
		return (0x00000000);
	else
		return (mlx.color * i);
}

void	wrong_args(void)
{
	write(1, "|***********Arguments**********|\n", 33);
	write(1, "|  starts w/ M for Mandelbrot  |\n", 33);
	write(1, "|     starts w/ J for Julia    |\n", 33);
	write(1, "| starts w/ B for Burning ship |\n", 33);
	write(1, "|      add 1 or 2 for Julia    |\n", 33);
	write(1, "|******************************|\n", 33);
	exit(0);
}

int	check_args(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] == 'M')
		return (1);
	else if (argc == 2 && argv[1][0] == 'J')
		return (2);
	else if (argc == 3 && argv[1][0] == 'J')
		return (3);
	else if (argc == 2 && argv[1][0] == 'B')
		return (4);
	else
		wrong_args();
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		type;

	type = check_args(argc, argv);
	init_screen(&mlx, type, argv);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, mlx.width, mlx.length, "Fract_ol");
	mlx_key_hook(mlx.mlx_win, key_event, &mlx);
	mlx_mouse_hook(mlx.mlx_win, mouse_event, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, close_bsdhjkacvbka, &mlx);
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.length);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.ll, &mlx.endian);
	mlx = make_image(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:17:35 by awalter           #+#    #+#             */
/*   Updated: 2023/05/12 16:17:36 by awalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_bsdhjkacvbka(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

void	color_shaft(int key, t_mlx *mlx)
{
	if (key == 114)
		mlx->color = 0x00050000;
	if (key == 103)
		mlx->color = 0x00000500;
	if (key == 98)
		mlx->color = 0x00020206;
	if (key == 99)
		mlx->color = 0x00000505;
	if (key == 109)
		mlx->color = 0x00050005;
	if (key == 121)
		mlx->color = 0x00050500;
	if (key == 119)
		mlx->color = 0x00050505;
	if (key == 112)
		mlx->color = 0x006AF8A2;
}

int	key_event(int key, t_mlx *mlx)
{
	if (key == 65307)
		close_bsdhjkacvbka(mlx);
	else if (key == 65362)
		mlx->vo -= 100;
	else if (key == 65364)
		mlx->vo += 100;
	else if (key == 65363)
		mlx->ho += 500;
	else if (key == 65361)
		mlx->ho -= 500;
	else
		color_shaft (key, mlx);
	*mlx = make_image(*mlx);
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	return (0);
}

int	mouse_event(int key, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (key == 4)
	{
		mlx->ho = mlx->ho - ((fabs(x / mlx->nz) + 1) - fabs(mlx->hm / mlx->nz));
		mlx->vo = mlx->vo - ((fabs(y / mlx->nz) + 1) - fabs(mlx->vm / mlx->nz));
		mlx->zoom = mlx->zoom * 1.2;
		mlx->nz = mlx->nz * 1.2;
		*mlx = make_image(*mlx);
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (key == 5)
	{
		mlx->ho = mlx->ho - ((fabs(x * mlx->nz) + 1) - fabs(mlx->hm * mlx->nz));
		mlx->vo = mlx->vo - ((fabs(y * mlx->nz) + 1) - fabs(mlx->vm * mlx->nz));
		mlx->zoom = mlx->zoom / 1.2;
		mlx->nz = mlx->nz / 1.2;
		*mlx = make_image(*mlx);
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	return (0);
}

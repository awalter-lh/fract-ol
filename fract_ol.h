/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:08:47 by awalter           #+#    #+#             */
/*   Updated: 2023/05/07 14:08:49 by awalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cmp {
	double		re;
	double		im;
}	t_cmp;

typedef struct s_mlx {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
	int			width;
	int			length;
	int			hm;
	int			vm;
	int			vo;
	int			ho;
	double		zoom;
	double		nz;
	int			color;
	int			type;
	double		arg_one;
}	t_mlx;

int		ft_atoi(const char *nptr);
int		close_bsdhjkacvbka(t_mlx *mlx);
void	color_shaft(int key, t_mlx *mlx);
int		key_event(int key, t_mlx *mlx);
int		mouse_event(int key, int x, int y, t_mlx *mlx);
void	ppj(t_mlx mlx, t_cmp pix, double arg_one, double arg_two);
void	put_pixel_b(t_mlx mlx, t_cmp pix);
void	put_pixel_m(t_mlx mlx, t_cmp pix);
t_mlx	make_image(t_mlx mlx);
void	init_screen(t_mlx *mlx, int type, char **argv);
int		mandelbrot_calculation(t_cmp coo, t_cmp start, t_mlx mlx);
int		bs_calculation(t_cmp coo, t_cmp start, t_mlx mlx);

#endif

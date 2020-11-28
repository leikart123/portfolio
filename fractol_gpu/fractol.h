/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:49:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/07/27 18:04:54 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include "minilibx_macos/mlx.h"
# include "libft.h"

# define WID	800
# define HEI	800

# define IVORY	0xE4E4E1

typedef	struct		s_cmplx
{
	double			re;
	double			im;
}					t_cmplx;

typedef struct		s_cntrl
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
	char			fr_name;
	int				j_move;
	int				menu;
	int				iter;
	int				color;
	double			zoom;
	t_cmplx			min;
	t_cmplx			max;
	t_cmplx			k;
	t_cmplx			z;
	t_cmplx			c;
	t_cmplx			pos;
	t_cmplx			zbuf;
}					t_cntrl;

void				error_handling(int i);
void				draw_fractal(t_cntrl *cntrl);
void				set_minimum(t_cntrl *cntrl);
void				set_re_im(t_cntrl *cntrl, int x, int y);
void				mandelbrot(t_cntrl *cntrl);
void				flowerbrot(t_cntrl *cntrl);
void				julia(t_cntrl *cntrl);
void				burning_ship(t_cntrl *cntrl);
int					colors(int i, int iter, int color);
void				default_settings(t_cntrl *cntrl);
int					key_mouse_control(t_cntrl *cntrl);
void				julia_changes(t_cntrl *cntrl, int x, int y);
void				scroll(int button, t_cntrl *cntrl, double x, double y);
void				move(int key, t_cmplx *pos);
void				menu_onoff(t_cntrl *cntrl);
void				show_menu(t_cntrl *cntrl);
void				set_flowerbrot(t_cntrl *cntrl);

#endif

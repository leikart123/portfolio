/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_norme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:47:39 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 18:00:35 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_cos_calc(t_image_data *img_d, int x, int y)
{
	int					i;
	t_complex_double	c;
	t_complex_double	z;
	t_complex_double	z2;

	i = 0;
	c.re = x / img_d->zoom + img_d->min.re;
	c.im = y / img_d->zoom + img_d->min.im;
	z.re = 0;
	z.im = 0;
	while (i < img_d->maxiter)
	{
		z2 = complex_cos(z);
		if (z2.re - z2.im > 10 * PI)
			break ;
		z = z2;
		z.im += c.im;
		z.re += c.re;
		i++;
	}
	img_d->pixels_arr[(img_d->thread_size - 1 - (img_d->max_y - y)) * HEI \
	+ x] = get_color(img_d->maxiter, i, img_d->palett_type);
}

void	mandel_sin_calc(t_image_data *img_d, int x, int y)
{
	int					i;
	t_complex_double	c;
	t_complex_double	z;
	t_complex_double	z2;

	i = 0;
	c.re = x / img_d->zoom + img_d->min.re;
	c.im = y / img_d->zoom + img_d->min.im;
	z.re = 0;
	z.im = 0;
	while (i < img_d->maxiter)
	{
		z2 = complex_sin(z);
		if (z2.re - z2.im > 10 * PI)
			break ;
		z = z2;
		z.im += c.im;
		z.re += c.re;
		i++;
	}
	img_d->pixels_arr[(img_d->thread_size - 1 - (img_d->max_y - y)) * HEI + \
	x] = get_color(img_d->maxiter, i, img_d->palett_type);
}

void	draw_mandel_cos(t_image_data *img_d, int x, int y)
{
	y = img_d->max_y - img_d->thread_size;
	while (y++ < img_d->max_y)
	{
		while (x++ < WID)
			mandel_cos_calc(img_d, x, y);
		x = 0;
	}
}

void	draw_mandel_sin(t_image_data *img_d, int x, int y)
{
	y = img_d->max_y - img_d->thread_size;
	while (y++ < img_d->max_y)
	{
		while (x++ < WID)
			mandel_sin_calc(img_d, x, y);
		x = 0;
	}
}

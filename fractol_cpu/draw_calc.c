/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:50:31 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 18:02:05 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_double	set_flowerbrot(t_complex_double z, t_complex_double c)
{
	double r;
	double i;

	r = z.re;
	i = z.im;
	z.re = pow(r, 6) - (15 * pow(r, 4) * pow(i, 2)) + \
		(15 * pow(r, 2) * pow(i, 4)) - pow(i, 6) + c.im;
	z.im = (6 * pow(r, 5) * i - 20 * pow(r, 3) * \
		pow(i, 3) + 6 * r * pow(i, 5)) + c.re;
	return (z);
}

void				julia_calc(t_image_data *img_d, int x, int y)
{
	t_complex_double	z;
	t_complex_double	zbuf;
	int					i;

	z.im = y / img_d->zoom + img_d->min.im;
	z.re = x / img_d->zoom + img_d->min.re;
	i = -1;
	while (++i < img_d->maxiter)
	{
		zbuf.re = z.re * z.re;
		zbuf.im = z.im * z.im;
		if (zbuf.re + zbuf.im > 4)
			break ;
		z.im = 2 * z.re * z.im + img_d->julia_k.im;
		z.re = zbuf.re - zbuf.im + img_d->julia_k.re;
	}
	img_d->pixels_arr[(img_d->thread_size - 1 - (img_d->max_y - y)) * HEI + \
	x] = get_color(img_d->maxiter, i, img_d->palett_type);
}

void				mandel_calc(t_image_data *img_d, int x, int y)
{
	int					i;
	t_complex_double	c;
	t_complex_double	z;
	t_complex_double	z2;

	c.re = x / img_d->zoom + img_d->min.re;
	c.im = y / img_d->zoom + img_d->min.im;
	z.re = 0;
	z.im = 0;
	i = 0;
	while (i < img_d->maxiter)
	{
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		if (z2.re + z2.im > 4)
			break ;
		z.im = 2 * z.re * z.im + c.im;
		z.re = z2.re - z2.im + c.re;
		i++;
	}
	img_d->pixels_arr[(img_d->thread_size - 1 - (img_d->max_y - y)) * HEI + \
	x] = get_color(img_d->maxiter, i, img_d->palett_type);
}

void				flower_calc(t_image_data *img_d, int x, int y)
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
		z2.re = pow(z.re, 6);
		z2.im = pow(z.im, 6);
		if (z2.re + z2.im > 4)
			break ;
		z = set_flowerbrot(z, c);
		i++;
	}
	img_d->pixels_arr[(img_d->thread_size - 1 - (img_d->max_y - y)) * HEI + \
	x] = get_color(img_d->maxiter, i, img_d->palett_type);
}

void				burning_ship_calc(t_image_data *img_d, int x, int y)
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
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		if (z2.re + z2.im > 4)
			break ;
		z.im = 2 * z.re * z.im + c.im;
		z.re = z2.re - z2.im + c.re;
		i++;
	}
	img_d->pixels_arr[(img_d->thread_size - 1 - (img_d->max_y - y)) * HEI + \
	x] = get_color(img_d->maxiter, i, img_d->palett_type);
}

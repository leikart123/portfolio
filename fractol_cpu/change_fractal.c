/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:57:09 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:41:29 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_fractal_norm(int key, t_image_data *img_d)
{
	if (key == 21)
	{
		img_d->fractal_num = 4;
		img_d->zoom = 100;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
		img_d->maxiter = 100;
	}
	if (key == 23)
	{
		img_d->fractal_num = 5;
		img_d->zoom = 100;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
		img_d->maxiter = 100;
	}
	if (key == 22)
	{
		img_d->fractal_num = 6;
		img_d->zoom = 200;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
		img_d->maxiter = 100;
	}
}

void	change_fractal(int key, t_image_data *img_d)
{
	if (key == 18)
	{
		img_d->fractal_num = 1;
		img_d->zoom = 240;
		img_d->x_pos = 0;
		img_d->y_pos = 0;
		img_d->maxiter = 100;
	}
	if (key == 19)
	{
		img_d->fractal_num = 2;
		img_d->zoom = 260;
		img_d->x_pos = 160;
		img_d->y_pos = 0;
		img_d->maxiter = 100;
	}
	if (key == 20)
	{
		img_d->fractal_num = 3;
		img_d->zoom = 240;
		img_d->x_pos = 100;
		img_d->y_pos = 100;
		img_d->maxiter = 100;
	}
	change_fractal_norm(key, img_d);
}

void	change_julia_k(t_image_data *img_d, int x, int y)
{
	if (x > 0 && x < WID && y > 0 && y < HEI)
	{
		img_d->julia_k.re = ((x / 10) + img_d->x_pos) / \
		(img_d->zoom + img_d->min.re);
		img_d->julia_k.im = ((y / 10) + img_d->y_pos) / \
		(img_d->zoom + img_d->min.im);
	}
}

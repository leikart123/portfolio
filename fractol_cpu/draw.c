/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:53:41 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:56:45 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_image_data *img_d, int x, int y)
{
	y = img_d->max_y - img_d->thread_size;
	if (x >= WID || y >= HEI)
		return ;
	while (y++ < img_d->max_y)
	{
		while (++x < WID)
			julia_calc(img_d, x, y);
		x = 0;
	}
}

void	draw_flowerbrot(t_image_data *img_d, int x, int y)
{
	y = img_d->max_y - img_d->thread_size;
	while (y++ < img_d->max_y)
	{
		while (x++ < WID)
			flower_calc(img_d, x, y);
		x = 0;
	}
}

void	draw_mandelbrod(t_image_data *img_d, int x, int y)
{
	y = img_d->max_y - img_d->thread_size;
	while (y++ < img_d->max_y)
	{
		while (x++ < WID)
			mandel_calc(img_d, x, y);
		x = 0;
	}
}

void	draw_burning_ship(t_image_data *img_d, int x, int y)
{
	y = img_d->max_y - img_d->thread_size;
	while (y++ < img_d->max_y)
	{
		while (x++ < WID)
			burning_ship_calc(img_d, x, y);
		x = 0;
	}
}

void	drawfractal(t_image_data *img_d)
{
	set_minimum(img_d);
	if (img_d->fractal_num == 1)
		draw_julia(img_d, -1, -1);
	if (img_d->fractal_num == 2)
		draw_mandelbrod(img_d, 0, 0);
	if (img_d->fractal_num == 3)
		draw_burning_ship(img_d, 0, 0);
	if (img_d->fractal_num == 4)
		draw_mandel_cos(img_d, 0, 0);
	if (img_d->fractal_num == 5)
		draw_mandel_sin(img_d, 0, 0);
	if (img_d->fractal_num == 6)
		draw_flowerbrot(img_d, 0, 0);
}

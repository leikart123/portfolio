/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:42:23 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:57:28 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_change(int key, t_image_data *img_d)
{
	if (key == 0x003d)
		img_d->maxiter += 50;
	if (key == 0x002d)
		img_d->maxiter -= 50;
	if (img_d->maxiter <= 0)
		img_d->maxiter = 50;
}

void	move(t_mlx_data *cmd, int key, t_image_data *img_d)
{
	double step;

	step = 50;
	if (key == 0xff54)
		cmd->img_data->y_pos += step;
	if (key == 0xff52)
		img_d->y_pos -= step;
	if (key == 0xff51)
		img_d->x_pos += step;
	if (key == 0xff53)
		img_d->x_pos -= step;
}

void	img_changes(int key, t_mlx_data *cmd, t_image_data *img_d)
{
	if (key == 0x003d || key == 0x002d)
		iter_change(key, img_d);
	if (key == 0xff52 || key == 0xff54 || key == 0xff51 || key == 0xff53)
		move(cmd, key, img_d);
	if (key == 0x0036 || key == 0x0031 || key == 0x0032 ||\
	key == 0x0033 || key == 0x0034 || key == 0x0035)
		change_fractal(key, img_d);
	if (key == 0x0071 || key == 0x0077 || key == 0x0065 || key == 0x0072)
		choose_color(key, img_d);
}

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
	if (key == 24)
		img_d->maxiter += 50;
	if (key == 27)
		img_d->maxiter -= 50;
	if (img_d->maxiter <= 0)
		img_d->maxiter = 50;
}

void	move(t_mlx_data *cmd, int key, t_image_data *img_d)
{
	double step;

	step = 50;
	if (key == 125)
		cmd->img_data->y_pos += step;
	if (key == 126)
		img_d->y_pos -= step;
	if (key == 124)
		img_d->x_pos += step;
	if (key == 123)
		img_d->x_pos -= step;
}

void	img_changes(int key, t_mlx_data *cmd, t_image_data *img_d)
{
	if (key == 24 || key == 27)
		iter_change(key, img_d);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move(cmd, key, img_d);
	if (key == 18 || key == 19 || key == 20 ||\
	key == 21 || key == 22 || key == 23)
		change_fractal(key, img_d);
	if (key == 12 || key == 13 || key == 14 || key == 15)
		choose_color(key, img_d);
}

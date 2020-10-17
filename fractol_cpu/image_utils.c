/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:41:13 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 15:16:04 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_new_image(t_mlx_data *cmd)
{
	if (cmd->img)
		mlx_destroy_image(cmd->mlx, cmd->img);
	cmd->img = mlx_new_image(cmd->mlx, WID, HEI);
	cmd->img_data->pixels_arr = (int *)mlx_get_data_addr(cmd->img, \
		&cmd->bpp, &cmd->size_line, &cmd->endian);
}

void	set_minimum(t_image_data *img_d)
{
	img_d->min.re = ((img_d->x_pos + (WID >> 1)) / (img_d->zoom / 2)) / -2;
	img_d->min.im = ((img_d->y_pos + (HEI >> 1)) / (img_d->zoom / 2)) / -2;
}

void	choose_color(int key, t_image_data *img_d)
{
	if (key == 12)
		img_d->palett_type = 1;
	if (key == 13)
		img_d->palett_type = 2;
	if (key == 14)
		img_d->palett_type = 3;
	if (key == 15)
		img_d->palett_type = 4;
}

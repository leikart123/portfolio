/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:41:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/02/21 16:17:19 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_changes(int key, t_cntrl *cntrl)
{
	if ((key >= 0xff51 && key <= 0xff54) || (key == 0x0061 || key == 0x0064))
		rotation(cntrl, key);
	if (key == 0x003d || key == 0x002d)
		scale(cntrl, key);
	if (key == 0x0069 || key == 0x006a || key == 0x006b || key == 0x006c)
		move(cntrl, key);
	if (key == 0x007a)
	{
		parallel_coor(cntrl);
		find_center(cntrl);
	}
	if (key == 0x0078)
	{
		make_3d(cntrl);
		find_center(cntrl);
	}
}

void	color_changes(int key, t_cntrl *cntrl)
{
	if (key == 0x0031)
	{
		cntrl->color = MINT;
		cntrl->end_color = RED;
	}
	if (key == 0x0032)
	{
		cntrl->color = MARS;
		cntrl->end_color = IVORY;
	}
	if (key == 0x0033)
	{
		cntrl->color = INDIGO;
		cntrl->end_color = MARS;
	}
}

int		key_control(int key, t_cntrl *cntrl)
{
	if (key == 0xff1b)
	{
		mlx_destroy_window(cntrl->mlx, cntrl->win);
		cleanup(cntrl);
		exit(EXIT_SUCCESS);
	}
	if ((key >= 0xff51 && key <= 0xff54) || key == 0x0031 || key == 0x0032 || key == 0x0033 || \
		key == 0x0061 || key == 0x0064 || key == 0x007a || key == 0x0078 || key == 0x003d || key == 0x002d \
		|| key == 0x006b || key == 0x006a || key == 0x0069 || key == 0x006c)
	{
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		img_changes(key, cntrl);
		color_changes(key, cntrl);
		points_output(cntrl->points, cntrl, 0, 0);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
		show_menu(cntrl);
	}
	return (0);
}

int		key_mouse_control(t_cntrl *cntrl)
{
	mlx_hook(cntrl->win, 2, (1L << 0), key_control, cntrl);
	return (0);
}

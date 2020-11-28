/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:42:22 by hunnamab          #+#    #+#             */
/*   Updated: 2020/02/17 14:52:17 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_menu(t_cntrl *cntrl)
{
	mlx_string_put(cntrl->mlx, cntrl->win, 80, 20, IVORY, \
		"Control keys");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 50, IVORY, \
		"Move - arrows");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 70, IVORY, \
		"Zoom - mouse wheel");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 90, IVORY, \
		"Zoom to mouse position - left button");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 110, IVORY, \
		"Number of iterations [-] / [+]");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 130, IVORY, \
		"Julia set motion on/off - shift");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 150, IVORY, \
		"Change color palette [1] / [2] / [3]");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 170, IVORY, \
		"Exit [esc]");
	mlx_string_put(cntrl->mlx, cntrl->win, 20, 190, IVORY, \
		"Hide/show menu [tab]");
}

void	menu_onoff(t_cntrl *cntrl)
{
	cntrl->menu = (!cntrl->menu) ? 1 : 0;
	if (cntrl->menu == 1)
		show_menu(cntrl);
	else
	{
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		draw_fractal(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	}
}

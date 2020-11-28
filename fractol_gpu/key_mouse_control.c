/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:41:49 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/16 16:57:34 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	img_changes(int key, t_cntrl *cntrl)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, &cntrl->pos);
	if (key == 27 || key == 24 || key == 18 || key == 19 || key == 20)
	{
		if (key == 27)
			cntrl->iter -= 10;
		if (key == 24)
			cntrl->iter += 10;
		if (key == 18)
			cntrl->color = 0;
		if (key == 19)
			cntrl->color = 1;
		if (key == 20)
			cntrl->color = 2;
	}
}

static int	key_control(int key, t_cntrl *cntrl)
{
	if (key == 53)
	{
		mlx_destroy_window(cntrl->mlx, cntrl->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 257 || key == 258)
		cntrl->j_move = (!cntrl->j_move) ? 1 : 0;
	if (key == 48)
		menu_onoff(cntrl);
	if (key == 123 || key == 124 || key == 125 || key == 126 || \
			key == 27 || key == 24 || key == 18 || key == 19 || key == 20)
	{
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		img_changes(key, cntrl);
		draw_fractal(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
		if (cntrl->menu)
			show_menu(cntrl);
	}
	return (0);
}

static int	mouse_move(int x, int y, t_cntrl *cntrl)
{
	if (cntrl->fr_name == 'j')
	{
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		julia_changes(cntrl, x, y);
		set_minimum(cntrl);
		julia(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
		if (cntrl->menu)
			show_menu(cntrl);
	}
	return (0);
}

static int	mouse_press(int button, int x, int y, t_cntrl *cntrl)
{
	if (cntrl->img)
		mlx_destroy_image(cntrl->mlx, cntrl->img);
	cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
	cntrl->data = (int *)mlx_get_data_addr(cntrl->img, \
		&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
	scroll(button, cntrl, x, y);
	draw_fractal(cntrl);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	if (cntrl->menu)
		show_menu(cntrl);
	return (0);
}

int			key_mouse_control(t_cntrl *cntrl)
{
	mlx_hook(cntrl->win, 2, (1L << 0), key_control, cntrl);
	mlx_hook(cntrl->win, 6, (1L << 6), mouse_move, cntrl);
	mlx_hook(cntrl->win, 4, (1L << 2), mouse_press, cntrl);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:47:02 by hunnamab          #+#    #+#             */
/*   Updated: 2020/07/27 18:01:29 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	define_fractal(char *name, t_cntrl *cntrl)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		cntrl->fr_name = 'm';
	else if (ft_strcmp(name, "julia") == 0)
		cntrl->fr_name = 'j';
	else if (ft_strcmp(name, "burning_ship") == 0)
		cntrl->fr_name = 'b';
	else if (ft_strcmp(name, "flowerbrot") == 0)
		cntrl->fr_name = 'f';
	else
		return (0);
	default_settings(cntrl);
	draw_fractal(cntrl);
	return (1);
}

int			main(int argc, char **argv)
{
	t_cntrl	*cntrl;

	if (!(cntrl = (t_cntrl *)ft_memalloc(sizeof(t_cntrl))))
		return (0);
	if (argc != 2)
		error_handling(0);
	if (!(define_fractal(argv[1], cntrl)))
		error_handling(1);
	mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	if (cntrl->menu)
		show_menu(cntrl);
	key_mouse_control(cntrl);
	mlx_loop(cntrl->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_choose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:59:28 by hunnamab          #+#    #+#             */
/*   Updated: 2020/07/27 18:07:52 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_cntrl *cntrl)
{
	set_minimum(cntrl);
	if (cntrl->fr_name == 'm')
		mandelbrot(cntrl);
	if (cntrl->fr_name == 'j')
		julia(cntrl);
	if (cntrl->fr_name == 'b')
		burning_ship(cntrl);
	if (cntrl->fr_name == 'f')
		flowerbrot(cntrl);
}

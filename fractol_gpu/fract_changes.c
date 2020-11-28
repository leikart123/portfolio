/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_changes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:42:20 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/16 16:57:52 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int key, t_cmplx *pos)
{
	if (key == 123)
		pos->re += -50;
	if (key == 126)
		pos->im += -50;
	if (key == 124)
		pos->re += 50;
	if (key == 125)
		pos->im += 50;
}

void	scroll(int button, t_cntrl *cntrl, double x, double y)
{
	double scale;

	scale = 0;
	if ((button == 5 || button == 4 || button == 1 || button == 2) && \
			(x >= 0 && x < WID && y >= 0 && y < HEI))
	{
		if (button == 5 || button == 2)
			scale = 0.9;
		if (button == 4 || button == 1)
			scale = 1.1;
		if (button == 1 || button == 2)
		{
			cntrl->pos.re = round((cntrl->pos.re + ((WID >> 1) - x)) * scale);
			cntrl->pos.im = round((cntrl->pos.im + ((HEI >> 1) - y)) * scale);
		}
		cntrl->zoom *= scale;
	}
}

void	julia_changes(t_cntrl *cntrl, int x, int y)
{
	if (x > 0 && x < WID && y > 0 && y < HEI && !cntrl->j_move)
	{
		cntrl->k.re = (x + cntrl->pos.re) / cntrl->zoom + cntrl->min.re;
		cntrl->k.im = (y + cntrl->pos.im) / cntrl->zoom + cntrl->min.im;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:01:47 by hunnamab          #+#    #+#             */
/*   Updated: 2020/07/27 18:07:32 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	flowerbrot(t_cntrl *cntrl)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			set_re_im(cntrl, x, y);
			i = -1;
			while (++i < cntrl->iter)
			{
				cntrl->zbuf.re = pow(cntrl->z.re, 6);
				cntrl->zbuf.im = pow(cntrl->z.im, 6);
				if (cntrl->zbuf.re + cntrl->zbuf.im > 4)
					break ;
				set_flowerbrot(cntrl);
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
		}
	}
}

void	burning_ship(t_cntrl *cntrl)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			set_re_im(cntrl, x, y);
			i = -1;
			while (++i < cntrl->iter)
			{
				cntrl->zbuf.re = cntrl->z.re * cntrl->z.re;
				cntrl->zbuf.im = cntrl->z.im * cntrl->z.im;
				if (cntrl->zbuf.re + cntrl->zbuf.im > 4)
					break ;
				cntrl->z.im = 2 * fabs(cntrl->z.re * cntrl->z.im) + cntrl->c.im;
				cntrl->z.re = cntrl->zbuf.re - cntrl->zbuf.im + cntrl->c.re;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
		}
	}
}

void	julia(t_cntrl *cntrl)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			set_re_im(cntrl, x, y);
			i = -1;
			while (++i < cntrl->iter)
			{
				cntrl->zbuf.re = cntrl->z.re * cntrl->z.re;
				cntrl->zbuf.im = cntrl->z.im * cntrl->z.im;
				if (cntrl->zbuf.re + cntrl->zbuf.im > 4)
					break ;
				cntrl->z.im = 2 * cntrl->z.re * cntrl->z.im + (cntrl->k.im);
				cntrl->z.re = cntrl->zbuf.re - cntrl->zbuf.im + (cntrl->k.re);
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
		}
	}
}

void	mandelbrot(t_cntrl *cntrl)
{
	int		i;
	int		x;
	int		y;

	y = -1;
	while (++y < HEI)
	{
		x = -1;
		while (++x < WID)
		{
			set_re_im(cntrl, x, y);
			i = -1;
			while (++i < cntrl->iter)
			{
				cntrl->zbuf.re = cntrl->z.re * cntrl->z.re;
				cntrl->zbuf.im = cntrl->z.im * cntrl->z.im;
				if (cntrl->zbuf.re + cntrl->zbuf.im > 4)
					break ;
				cntrl->z.im = 2 * cntrl->z.re * cntrl->z.im + cntrl->c.im;
				cntrl->z.re = cntrl->zbuf.re - cntrl->zbuf.im + cntrl->c.re;
			}
			cntrl->data[y * WID + x] = colors(i, cntrl->iter, cntrl->color);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:43:52 by hunnamab          #+#    #+#             */
/*   Updated: 2020/03/13 17:56:42 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	colors_three(int i, int iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)i / (double)iter;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(8.5 * pow((1 - t), 3) * t * 255);
	green <<= 8;
	red <<= 16;
	blue = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	return (red | green | blue);
}

static int	colors_two(int i, int iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)i / (double)iter;
	red = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	green = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green <<= 8;
	red <<= 16;
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (red | green | blue);
}

static int	colors_one(int i, int iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)i / (double)iter;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	green <<= 8;
	red <<= 16;
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (red | green | blue);
}

int			colors(int i, int iter, int color)
{
	if (color == 0)
		return (colors_one(i, iter));
	if (color == 1)
		return (colors_two(i, iter));
	if (color == 2)
		return (colors_three(i, iter));
	return (0);
}

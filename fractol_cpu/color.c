/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:55:12 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:58:30 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		first_palett(double maxiter, int i)
{
	int		r;
	int		g;
	int		b;
	int		color;
	double	t;

	t = (double)i / (double)maxiter;
	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(8.5 * pow((1 - t), 3) * t * 255);
	b = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	g <<= 8;
	r <<= 16;
	color = (r | g | b);
	return (color);
}

int		second_palett(double maxiter, double i)
{
	int		r;
	int		g;
	int		b;
	int		color;
	double	t;

	t = (double)i / (double)maxiter;
	r = (int)(15 * (1 - t) * pow(t, 3) * 255);
	g = (int)(9 * pow((1 - t), 3) * t * 255);
	b = (int)(8.5 * pow((1 - t), 2) * pow(t, 2) * 255);
	g <<= 8;
	r <<= 16;
	color = (r | g | b);
	return (color << 8);
}

int		third_palett(double maxiter, double i)
{
	int		r;
	int		g;
	int		b;
	int		color;
	double	t;

	t = (double)i / (double)maxiter;
	r = (int)(8.5 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 3) * t * 255);
	b = (int)(9 * pow((1 - t), 2) * pow(t, 2) * 255);
	g <<= 8;
	g /= 1000;
	r <<= 16;
	r /= 5;
	color = (r | g | b);
	return (color);
}

int		fourth_palett(int i)
{
	int		r;
	int		g;
	int		b;

	r = i;
	g = i;
	b = i;
	g <<= 8;
	r <<= 16;
	return (r | g | b);
}

int		get_color(double maxiter, double i, int palett_type)
{
	if (palett_type == 1)
		return (first_palett(maxiter, i));
	if (palett_type == 2)
		return (second_palett(maxiter, i));
	if (palett_type == 3)
		return (third_palett(maxiter, i));
	if (palett_type == 4)
		return (fourth_palett(i));
	return (0);
}

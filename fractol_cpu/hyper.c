/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:43:43 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:37:13 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double				sinhyp(double x)
{
	double result;

	result = (pow(E, x) - pow(E, -x)) / 2;
	return (result);
}

double				coshyp(double x)
{
	double result;

	result = (pow(E, x) + pow(E, -x)) / 2;
	return (result);
}

t_complex_double	complex_cos(t_complex_double z)
{
	t_complex_double result;

	result.re = cos(z.re) * coshyp(z.im);
	result.im = -(sin(z.re) * sinhyp(z.im));
	return (result);
}

t_complex_double	complex_sin(t_complex_double z)
{
	t_complex_double result;

	result.re = sin(z.re) * coshyp(z.im);
	result.im = cos(z.re) * sinhyp(z.im);
	return (result);
}

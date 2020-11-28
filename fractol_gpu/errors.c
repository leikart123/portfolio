/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunnamab <hunnamab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 18:28:43 by hunnamab          #+#    #+#             */
/*   Updated: 2020/07/27 18:08:10 by hunnamab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_handling(int i)
{
	if (i == 0)
		ft_putstr("usage: ./fractol [fractal_name]\n\n");
	if (i == 1)
		ft_putstr("Oops! Wrong fractal name, try again! :(\n\n");
	ft_putstr("available fractals:");
	ft_putstr("\t[mandelbrot]\n\t\t\t[julia]\n\t\t\t[burning_ship]\n");
	ft_putstr("\t\t\t[flowerbrot]\n");
	exit(EXIT_SUCCESS);
}

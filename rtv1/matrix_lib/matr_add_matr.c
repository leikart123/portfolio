/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matr_add_matr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:43:56 by pmetron           #+#    #+#             */
/*   Updated: 2020/11/10 17:53:32 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	matr_add_matr(double **matrix1, double **matrix2, \
int num_rows, int num_cols)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < num_rows)
	{
		while (j < num_cols)
		{
			matrix1[i][j] += matrix2[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

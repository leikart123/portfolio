/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:36:38 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:59:07 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear(t_image_data *img_buf)
{
	ft_memdel((void **)&img_buf->pixels_arr);
	free(img_buf);
}

void	copy_img_data(t_image_data *img_d, t_image_data **img_buf, int i)
{
	img_buf[i - 1] = malloc(sizeof(t_image_data));
	img_buf[i - 1]->thread_size = img_d->thread_size;
	img_buf[i - 1]->x_pos = img_d->x_pos;
	img_buf[i - 1]->y_pos = img_d->y_pos;
	img_buf[i - 1]->scale = img_d->scale;
	img_buf[i - 1]->zoom = img_d->zoom;
	img_buf[i - 1]->fractal_num = img_d->fractal_num;
	img_buf[i - 1]->maxiter = img_d->maxiter;
	img_buf[i - 1]->palett_type = img_d->palett_type;
	img_buf[i - 1]->max_y = img_d->thread_size * i;
	img_buf[i - 1]->min.re = img_d->min.re;
	img_buf[i - 1]->min.im = img_d->min.im;
	img_buf[i - 1]->mouse_pos.x = img_d->mouse_pos.x;
	img_buf[i - 1]->mouse_pos.y = img_d->mouse_pos.y;
	img_buf[i - 1]->julia_k.re = img_d->julia_k.re;
	img_buf[i - 1]->julia_k.im = img_d->julia_k.im;
	img_buf[i - 1]->pixels_arr = malloc(sizeof(int) * WID * HEI);
}

void	copy_data_from_buf(t_image_data *img_d, t_image_data **img_buf)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (i <= THREAD_NUM)
	{
		while (j < img_d->thread_size * WID)
		{
			img_d->pixels_arr[(i - 1) * img_d->thread_size * WID + j] = \
			img_buf[i - 1]->pixels_arr[j];
			j++;
		}
		clear(img_buf[i - 1]);
		j = 0;
		i++;
	}
	ft_memdel((void **)&img_buf);
}

void	thread_init(t_image_data *img_d)
{
	pthread_t		tid[THREAD_NUM];
	int				i;
	int				j;
	t_image_data	**img_buf;

	img_d->max_y = 100;
	i = 1;
	j = 0;
	img_buf = malloc(sizeof(t_image_data *) * THREAD_NUM);
	set_minimum(img_d);
	while (i <= THREAD_NUM)
	{
		copy_img_data(img_d, img_buf, i);
		pthread_create(&tid[i - 1], NULL, (void *)(*drawfractal), \
		(void *)img_buf[i - 1]);
		i++;
	}
	i = 1;
	while (i <= THREAD_NUM)
	{
		pthread_join(tid[i - 1], NULL);
		i++;
	}
	copy_data_from_buf(img_d, img_buf);
}

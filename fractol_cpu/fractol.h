/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmetron <pmetron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:04:01 by pmetron           #+#    #+#             */
/*   Updated: 2020/08/03 17:59:17 by pmetron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define THREAD_NUM	4
# define WID		1024
# define HEI		1024
# define PI			3.1415
# define E			2.71828

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <mlx.h>
# include <pthread.h>
# include <fcntl.h>

typedef	struct			s_cmplx
{
	double				re;
	double				im;
}						t_complex_double;

typedef	struct			s_mouse_pos
{
	int					x;
	int					y;
}						t_mouse_pos;

typedef struct			s_image_data
{
	double				x_pos;
	double				y_pos;
	int					scale;
	double				zoom;
	int					*pixels_arr;
	int					fractal_num;
	int					maxiter;
	int					palett_type;
	int					max_y;
	int					thread_size;
	t_complex_double	min;
	t_complex_double	max;
	t_mouse_pos			mouse_pos;
	t_complex_double	julia_k;
}						t_image_data;

typedef struct			s_mlx_data
{
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					size_line;
	int					endian;
	int					mouse_locked;
	t_image_data		*img_data;
}						t_mlx_data;

int						key_mouse_control(t_mlx_data *cmd);
void					init_mlx(t_mlx_data *cmd);
void					img_data_init(t_image_data *img_d, t_mlx_data *cmd);
int						key_control(int key, t_mlx_data *cmd);
void					drawfractal(t_image_data *img_d);
void					draw_julia(t_image_data *img_d, int x, int y);
int						mouse_press(int button, int x, int y, t_mlx_data *cmd);
void					img_changes(int key, t_mlx_data *cmd, \
						t_image_data *img_d);
void					get_new_image(t_mlx_data *cmd);
void					zoom(int key, t_image_data *img_d);
int						get_color(double maxiter, double i, \
						int palett_type);
int						args_parse(int argc, char **argv, t_mlx_data *cmd);
int						mouse_move(int x, int y, t_mlx_data *cmd);
void					change_julia_k(t_image_data *img_d, int x, int y);
t_complex_double		complex_cos(t_complex_double z);
t_complex_double		complex_sin(t_complex_double z);
void					choose_color(int key, t_image_data *img_d);
void					thread_init(t_image_data *img_d);
void					change_julia_k(t_image_data *img_d, int x, int y);
void					set_minimum(t_image_data *img_d);
void					change_fractal(int key, t_image_data *img_d);
void					julia_calc(t_image_data *img_d, int x, int y);
void					mandel_calc(t_image_data *img_d, \
						int x, int y);
t_complex_double		set_flowerbrot(t_complex_double z, t_complex_double c);
void					flower_calc(t_image_data *img_d, int x, int y);
void					draw_mandel_cos(t_image_data *img_d, int x, int y);
void					draw_mandel_sin(t_image_data *img_d, int x, int y);
void					burning_ship_calc(t_image_data *img_d, int x, int y);
double					sinhyp(double x);
double					coshyp(double x);

#endif

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>
#include <fcntl.h>
#include <stdint.h>
#include <mlx.h>
#include <cuda_runtime_api.h>
#include <vector_types.h>
#include <cuda.h>
#include "device_launch_parameters.h"
#include "libft/libft.h"

# define WID 1024
# define HEI 1024
# define threadNum 1024
# define NumberOfPixel (WID * HEI)
# define RED 0xa4303d
# define JULIA_RE -0.70176
# define JULIA_IM -0.3842
# define MAN_RE
# define MAN_IM

typedef enum fractal_type
{
	MANDELBROT,
	JULIA
}			t_fractal_type;

typedef struct  cntrl
{
	void        *mlx;
	void        *win;
	void        *img;
	int			fractal_num;
	int         bpp;
	int         size_line;
	int         endian;
	int         color;
	int32_t     end_color;
	float      angle;
	float      dx;
	float      dy;
	float      x_pos;
	float      y_pos;
	int         scale;
	int			z_max;
	int			z_min;
	float      zoom;
	int			*d_data_ptr;
	int			*h_data_ptr;
	int			type;
}               c_cntrl;

int		args_parse(int argc, char **argv, c_cntrl *cmd);
int		key_mouse_control(c_cntrl *cntrl);
void	mlx(c_cntrl *cntrl);
int		key_control(int key, c_cntrl *cntrl);

#endif
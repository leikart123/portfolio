#ifndef FRACTOL_CUH
# define FRACTOL_CUH

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <stdint.h>
#include <mlx.h>
#include <cuda_runtime_api.h>
#include <vector_types.h>
#include <cuda.h>
#include "device_launch_parameters.h"
#include <stdint.h>

# define RED 0xa4303d
# define JULIA_RE -0.70176
# define JULIA_IM -0.3842

__global__ void    draw_julia(int w, int h, double zoom, int *data_ptr, double minx, double miny, double posX, double posY);
__host__ void    draw_call(c_cntrl *cntrl);
__global__ void draw_mandelbrot(int w, int h, double zoom, int *data_ptr, double minx, double miny, double posX, double posY);
#endif
extern "C"{
    #include "fractol.h"
    }
    #include "fractol.cuh"

__host__ void    draw_call(c_cntrl *cntrl)
{
    dim3     gridSize;
    dim3     blockSize;
    double minx;
    double miny;

    minx = (cntrl->x_pos + (WID >> 1)) / (cntrl->zoom / 2) / -2;
    miny = (cntrl->y_pos + (WID >> 1)) / (cntrl->zoom / 2) / -2;
    gridSize = dim3(1, HEI, 1);
    blockSize = dim3(threadNum, 1, 1);
    if(cntrl->type == JULIA)
        draw_julia<<<gridSize, blockSize>>>(WID, HEI, cntrl->zoom, cntrl->d_data_ptr, minx, miny, cntrl->x_pos, cntrl->y_pos);
    if(cntrl->type == MANDELBROT)
        draw_mandelbrot<<<gridSize, blockSize>>>(WID, HEI, cntrl->zoom, cntrl->d_data_ptr, minx, miny, cntrl->x_pos, cntrl->y_pos);
    cudaMemcpy(cntrl->h_data_ptr, cntrl->d_data_ptr, sizeof(int) * NumberOfPixel, cudaMemcpyDeviceToHost);
    mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);    
}
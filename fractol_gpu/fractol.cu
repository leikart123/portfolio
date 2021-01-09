extern "C"{
    #include "fractol.h"
    }
    #include "fractol.cuh"

    __host__ int main(int argc, char **argv)
    {
        c_cntrl	*cntrl;

        if (!(cntrl = (c_cntrl *)malloc(sizeof(c_cntrl))))
            return (0);
        mlx(cntrl);
        if (args_parse(argc, argv, cntrl) < 0)
            exit(0);
        cudaMalloc((int **)&cntrl->d_data_ptr, sizeof(int) *NumberOfPixel);
        draw_call(cntrl);
        key_mouse_control(cntrl);
        mlx_loop(cntrl->mlx);
        return (0);
    }
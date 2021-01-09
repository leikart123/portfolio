#include "fractol.h"

void    mlx(c_cntrl *cntrl)
{
    cntrl->mlx = mlx_init();
	cntrl->win = mlx_new_window(cntrl->mlx, WID, HEI, "fractol");
	cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
	cntrl->h_data_ptr = (int *)mlx_get_data_addr(cntrl->img, &cntrl->bpp, \
		&cntrl->size_line, &cntrl->endian);
	cntrl->fractal_num = 2;
	cntrl->zoom = 400;
    cntrl->x_pos = 0;
    cntrl->y_pos = 0;
}

int		key_mouse_control(c_cntrl *cntrl)
{
	mlx_hook(cntrl->win, 2, (1L << 0), key_control, cntrl);
	return (0);
}
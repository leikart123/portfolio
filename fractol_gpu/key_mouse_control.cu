extern "C"{
    #include "fractol.h"
    }
    #include "fractol.cuh"

void	zoom(int key, c_cntrl *cntrl)
{
	if (key == 0x003d)
		cntrl->zoom *= 1.02;
	if (key == 0x002d)
		cntrl->zoom /= 1.02;
}

void	move(c_cntrl *cntrl, int key)
{
		double step;

		step = 10.0 / cntrl->zoom;
		if (step == 0)
			step = 0.001;
		if (key == 0xff52)
			cntrl->y_pos -= step;
		if (key == 0xff54)
			cntrl->y_pos += step;
		if (key == 0xff53)
			cntrl->x_pos -= step;
		if (key == 0xff51)
			cntrl->x_pos += step;
}
void	img_changes(int key, c_cntrl *cntrl)
{
	if (key == 0x003d || key == 0x002d)
		zoom(key, cntrl);
	if (key == 0xff52 || key == 0xff54 || key == 0xff53 || key == 0xff51)
		move(cntrl, key);
}

int		key_control(int key, c_cntrl *cntrl)
{
	if (key == 0xff1b)
	{
		mlx_destroy_window(cntrl->mlx, cntrl->win);
		exit(EXIT_SUCCESS);
	}
	if (key == 0x0031 || key == 0x0032 || key == 0x0033 || key == 0xff51 || key == 0xff52 || key == 0xff53 || key == 0xff54 || \
		key == 0x0077 || key == 0x0073 || key == 0x002d || key == 0x003d || \
		key == 0x0061 || key == 0x0064 || key == 0x0069 || key == 0x006b || \
		key == 0x006a || key == 0x006c || key == 0x007a || key == 0x0078)
	{
		if (cntrl->img)
			mlx_destroy_image(cntrl->mlx, cntrl->img);
		cntrl->img = mlx_new_image(cntrl->mlx, WID, HEI);
		cntrl->h_data_ptr = (int *)mlx_get_data_addr(cntrl->img, \
			&cntrl->bpp, &cntrl->size_line, &cntrl->endian);
		img_changes(key, cntrl);
		draw_call(cntrl);
		mlx_put_image_to_window(cntrl->mlx, cntrl->win, cntrl->img, 0, 0);
	}
	return (0);
}


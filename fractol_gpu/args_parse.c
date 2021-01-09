#include "fractol.h"

void	print_usage(void)
{
	ft_putstr("usage: ./fractol [fractal_name]\n");
	ft_putstr("names: \njulia\nmandelbrot\n");
	ft_putstr("[+ -] for zoom in/out\n");
	ft_putstr("arrows fot moving fractal\n");
}

int		args_parse(int argc, char **argv, c_cntrl *cmd)
{
	cmd->type = -1;
	if (argc != 2)
	{
		print_usage();
		return (-1);
	}
	if (argc == 2)
	{
		if (ft_strequ(argv[1], "julia\0"))
			cmd->type = JULIA;
		if (ft_strequ(argv[1], "mandelbrot\0"))
			cmd->type = MANDELBROT;
		if (cmd->type < 0)
			ft_putstr("wrong fractal name\n");
	}
	return (cmd->type < 0 ? -1 : 1);
}

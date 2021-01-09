__global__ void draw_julia(int w, int h, double zoom, int *data_ptr, double minx, double miny, double posX, double posY)
{
    double cRe, cIm;
    double newRe, newIm, oldRe, oldIm;
    int maxIterations = 880000;
    cRe = -0.74543;
    cIm = 0.11301;
    int r;
    int g;
    int b;
    int y = blockDim.y * blockIdx.y + threadIdx.y;
    int x = blockDim.x * blockIdx.x + threadIdx.x;
    if (x >= w || y>= h)
        return; 
    newRe = x / zoom + minx + posX;
    newIm = y / zoom + miny + posY;
    int i;
    for (i = 0; i < maxIterations; i++)
    {
        oldRe = newRe;
        oldIm = newIm;
        newRe = oldRe * oldRe - oldIm * oldIm + cRe;
        newIm = 2 * oldRe * oldIm + cIm;
        if ((newRe * newRe + newIm * newIm) > 2) break;
    }
        r = (i * 15) % 255;
        g = (i * 6) % 255;
        b = (i * 9) % 255;
        data_ptr[y * h + x] = ((r << 16) | (g << 8) | b);
}

__global__ void draw_mandelbrot(int w, int h, double zoom, int *data_ptr, double minx, double miny, double posX, double posY)
{
    double z_re;
    double z_im;
    double c_re;
    double c_im;
    double new_z_re;
    double new_z_im;
    int maxIterations = 1000;
    int r;
    int g;
    int b;
    int y = blockDim.y * blockIdx.y + threadIdx.y;
    int x = blockDim.x * blockIdx.x + threadIdx.x;
    int i;
    if (x >= w || y>= h)
        return;
    c_re = x / zoom + minx + posX;
    c_im = y / zoom + miny + posY;
    z_re = 0;
    z_im = 0;
    for(i = 0; i < maxIterations; i++)
    {
        new_z_re = z_re * z_re;
		new_z_im = z_im * z_im;
		if (new_z_re + new_z_im > 4)
			break ;
		z_im = 2 * z_re * z_im + c_im;
		z_re = new_z_re - new_z_im + c_re;
    }
    r = (i * 15) % 255;
    g = (i * 6) % 255;
    b = (i * 9) % 255;
    data_ptr[y * h + x] = ((r << 16) | (g << 8) | b);
}
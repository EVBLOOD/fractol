/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:01:36 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/15 19:55:44 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	*ft_new_image(t_varstock stock, t_dimensions win)
{
	int pixel_bits;
    int line_bytes;
    int endian;
	int *buffer;

    // new_image_ret = mlx_new_image(stock.init_ret, win.y, win.x);
    buffer = (int *)mlx_get_data_addr(stock.image, &pixel_bits, &line_bytes, &endian);
    // printf("\n%d\n",buffer);
	return (buffer);
}

// void	ft_startingvals(t_dimensions *xo_yo, t_dimensions *x_y, t_equation *r, t_equation *win_dmn)
// {
// 	count = 0;
//     xoyo_xy->c.x = xoyo_xy->z.x - win_dmn->c.x / 2.0;
//     xoyo_xy->c.y = -xoyo_xy->z.y + win_dmn->c.y / 2.0;
//     r->c.y = xoyo_xy->c.y * (win_dmn->z.y) / win_dmn->c.x;
//     r->c.x = win_dmn->z.x * xoyo_xy->c.x / win_dmn->c.y;
//     r->c.x = 0;
//     r->c.y = 0;
// }

void	*ft_mandelbrot(t_varstock stock, t_dimensions win, t_equation r, t_dimensions dmn, int x, int y)
{
    int	count;
    t_dimensions xo_yo;
    t_dimensions    x_y;
    float tmp_z;
	int *buffer;
    buffer = ft_new_image(stock, win);
    x_y.y = 0.0;
        // printf("|%f|", x_y.y);

    while (x_y.y < win.y)
    {
        // printf("|%f|", x_y.y);
        x_y.x = 0.0;
        while (x_y.x < win.x)
        {
       		count = 0;
        	xo_yo.x = x_y.x - win.x / 2.0;
            xo_yo.y = -x_y.y + win.y / 2.0;
            r.c.y = xo_yo.y * dmn.y / (win.x);
            r.c.y += 0.1;
            r.c.x = dmn.x * xo_yo.x / (win.y);
            r.c.x -= (float) sqrt(0.755 * 0.755 - 0.1 * 0.1);
            r.z.x = 0;
            r.z.y = 0;
            while (count < stock.iteration)
            {
                tmp_z = r.z.x;
                r.z.x = (r.z.x * r.z.x) - (r.z.y * r.z.y) + r.c.x;
                r.z.y = 2 * tmp_z * r.z.y + r.c.y;
                if ((r.z.x * r.z.x) + (r.z.y * r.z.y) > 4)
                    break;
                count++;
            }
            buffer[(int)(x_y.y * win.x + x_y.x)] = stock.color + (stock.iteration - count) * 15 * 200;
            // printf("\n|%d|\n", stock.color + (stock.iteration - count) * 15);
            x_y.x++;
        }
        x_y.y++;
    }
    return (stock.image);
}
int	key_hook(int keycode, int x ,int y, t_varstock *rec)
{
    // puts("test 001");


    // printf("wtf:%d", vargs->color);
    //  mlx_mouse_get_pos(vargs->win, &posx, &posy);
    printf("%d", keycode);
        int xb = x;
        int yb = y;
    printf("%d|%d", yb, xb);

    // win.x = 1000;
    // win.y = 1000;
    // t_equation z;
    // z.r.x = 0;
    // z.r.y = 0;
    // t_varstock stock;
    // stock.iteration = 1000;
    // puts("test 000");
    // // stock.image = vargs->image;
    // stock.init_ret = vargs->init;
    // stock.color = 0x00FF4500;
    // puts("test 001");

    // deux_d.x = vargs->x;
    // deux_d.y = vargs->y;
	// if (keycode == 4)
    // {
        x = 0;
   y = 0;
    if (keycode == 5)
    {
        rec->dmn->x /= 1.5;
        rec->dmn->y /=1.5;
        rec->iteration *= 1.5;
    }
    else if (keycode == 4)
    {
        if (rec->iteration > 100)
            rec->iteration /= 2;
         rec->dmn->x *= 2;
        rec->dmn->y *= 2;
    }
    
    ft_mandelbrot(*rec, *rec->wnd, *rec->r, *rec->dmn, x, y);
    mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
    // mlx_destroy_image(stock.init_ret, stock.image);
    // mlx_put_image_to_window(vargs->mlx, vargs->win, stock.image, 0, 0);
    puts("DONE");
    // }
    // else if (keycode == 5)
    // {
    //      deux_d.x *= 0.2;
    //     deux_d.y *= 0.2;
    //     ft_mandelbrot(win, z, deux_d, stock);
    //     // mlx_put_image_to_window(init_ret, wind_ret, new_image_ret, 0, 0);
    //     mlx_put_image_to_window(vargs->mlx, vargs->win, stock.image, 0, 0);

    // }

    return 0;
}
int main()
{
    t_varstock stock;
    t_dimensions    dmn;
    t_dimensions    wnd;
    t_equation r;
    void    *new_image_ret;

    // ft_startingmain(&stock, &win_dmn, &r);
    stock.init_ret = mlx_init();
    wnd.x = 600;
    wnd.y = 600;
    dmn.x = 4.0;
    dmn.y = 4.0;
    stock.iteration = 100;
    stock.color = 0x00FF4500;
    stock.win_ret = mlx_new_window(stock.init_ret, wnd.y, wnd.x, "EVBLOOD");
    stock.image = mlx_new_image(stock.init_ret, wnd.y, wnd.x);
// void	*ft_mandelbrot(t_varstock stock, t_dimensions win, t_equation r, t_dimensions dmn)

    ft_mandelbrot(stock, wnd, r, dmn, 0, 0);
    stock.r = &r;
    stock.wnd = &wnd;
    stock.dmn =&dmn;
    mlx_put_image_to_window(stock.init_ret, stock.win_ret, stock.image, 0, 0);
    mlx_hook(stock.win_ret,4 , 0, key_hook, &stock);
    // mlx_put_image_to_window(stock.init_ret, stock.win_ret, new_image_ret, 0, 0);
    mlx_loop(stock.init_ret);
}
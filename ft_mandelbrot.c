/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:01:36 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 01:48:55 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

// int	*ft_new_image(t_varstock stock, t_dimensions win)
// {
// 	int pixel_bits;
//     int line_bytes;
//     int endian;
// 	int *buffer;

//     // new_image_ret = mlx_new_image(stock.init_ret, win.y, win.x);
//     buffer = (int *)mlx_get_data_addr(stock.image, &pixel_bits, &line_bytes, &endian);
//     // printf("\n%d\n",buffer);
// 	return (buffer);
// }

// // void	ft_startingvals(t_dimensions *xo_yo, t_dimensions *x_y, t_equation *r, t_equation *win_dmn)
// // {
// // 	count = 0;
// //     xoyo_xy->c.x = xoyo_xy->z.x - win_dmn->c.x / 2.0;
// //     xoyo_xy->c.y = -xoyo_xy->z.y + win_dmn->c.y / 2.0;
// //     r->c.y = xoyo_xy->c.y * (win_dmn->z.y) / win_dmn->c.x;
// //     r->c.x = win_dmn->z.x * xoyo_xy->c.x / win_dmn->c.y;
// //     r->c.x = 0;
// //     r->c.y = 0;
// // }
// double      interpolate(double start, double end, double interp)
// {
//     return (start + ((end - start) * interp));
// }

// void        apply_zoom(t_zoomcrd *cord, double m_x, double m_y, double interp)
// {
//     cord->x_min = interpolate(m_x, cord->x_min, interp);
//     cord->y_min = interpolate(m_y, cord->y_min, interp);
//     cord->x_max = interpolate(m_x, cord->x_max, interp);
//     cord->y_max = interpolate(m_y, cord->y_max, interp);
// }


// void	*ft_mandelbrot(t_varstock stock, t_dimensions win, t_equation r, t_zoomcrd dmn, int x, int y)
// {
//     long double	count;
//     t_dimensions xo_yo;
//     t_dimensions    x_y;
//     float tmp_z;
// 	int *buffer;
//     float xm;
//     float ym;
//     buffer = ft_new_image(stock, win);
//     x_y.y = 0.0;

//             // printf("\n%f\n%f\n", (x - win.x / 2) * dmn.x  , (-y + win.y / 2));
//     while (x_y.y < win.y)
//     {
//         // printf("|%f|", x_y.y);
//         // printf("|%f|", x_y.y);
//         x_y.x = 0.0;
//         while (x_y.x < win.x)
//         {
//             // xm = (x - win.x / 2) / win.x ;
//             // ym = (-y + win.y / 2) / win.y;
//        		count = 0;
//         	// xo_yo.x = x_y.x - win.x / 2.0;
//             // xo_yo.y = -x_y.y + win.y / 2.0;
//             r.c.y = x_y.y * (dmn.y_max - dmn.y_min) / (win.y) + dmn.y_min;
//             // r.c.y += ym;
//             r.c.x = (dmn.x_max - dmn.x_min) * x_y.x / (win.x) + dmn.x_min;
//             // r.c.x += xm; //(float) 0.75;
//             r.z.x = 0;
//             r.z.y = 0;
//             while (count < stock.iteration)
//             {
//                 tmp_z = r.z.x;
//                 r.z.x = (r.z.x * r.z.x) - (r.z.y * r.z.y) + r.c.x;
//                 r.z.y = 2 * tmp_z * r.z.y + r.c.y;
//                 if ((r.z.x * r.z.x) + (r.z.y * r.z.y) > 4)
//                     break;
//                 count++;
//             }
//             buffer[(int)(x_y.y * win.x + x_y.x)] = stock.color + (stock.iteration - count) * 15 * 200;
//             // printf("\n|%d|\n", stock.color + (stock.iteration - count) * 15);
//             x_y.x++;
//         }
//         x_y.y++;
//     }
//     return (stock.image);
// }
// int	key_hook(int keycode, int x ,int y, t_varstock *rec)
// {
//     // puts("test 001");


//     // printf("wtf:%d", vargs->color);
//     //  mlx_mouse_get_pos(vargs->win, &posx, &posy);
//     // printf("%d", keycode);
//     //     int xb = x;
//     //     int yb = y;
//     // printf("%f|%f\n", (x - rec->wnd->x / 2) / rec->wnd->x , (-y + rec->wnd->y / 2) / rec->wnd->y);

//     // win.x = 1000;
//     // win.y = 1000;
//     // t_equation z;
//     // z.r.x = 0;
//     // z.r.y = 0;
//     // t_varstock stock;
//     // stock.iteration = 1000;
//     // puts("test 000");
//     // // stock.image = vargs->image;
//     // stock.init_ret = vargs->init;
//     // stock.color = 0x00FF4500;
//     // puts("test 001");

//     // deux_d.x = vargs->x;
//     // deux_d.y = vargs->y;
// 	// if (keycode == 4)
//     // {
//         double i = 0;
//         double n = 0;
       
//     if (keycode == 5)
//     {
//         // rec->dmn->x /= 1.5;
//         // rec->dmn->y /=1.5;
//         n = y * (rec->go->y_max - rec->go->y_min) / (rec->wnd->y) + rec->go->y_min;
//             // r.c.y += ym;
//         i = x * (rec->go->x_max - rec->go->x_min) / (rec->wnd->x) + rec->go->x_min;
//         rec->iteration += 200;
//         apply_zoom(rec->go, i, n, 0.9);
//         printf("%f", rec->go->x_max);
//         printf("%f", rec->go->y_max);

//     }
//     else if (keycode == 4)
//     {
//         i = (x - rec->wnd->x / 2) /  rec->wnd->x;
//         n = (-y + rec->wnd->y / 2) / rec->wnd->y;
//         if (rec->iteration > 100)
//             rec->iteration -= 200;
//         //  rec->dmn->x *= 1.5;
//         // rec->dmn->y *= 1.5;
//         apply_zoom(rec->go, i, n, 1/0.9);
//     }
    
//     ft_mandelbrot(*rec, *rec->wnd, *rec->r, *rec->go, i, n);
//     mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
//     // mlx_destroy_image(stock.init_ret, stock.image);
//     // mlx_put_image_to_window(vargs->mlx, vargs->win, stock.image, 0, 0);
//     puts("DONE");
//     // }
//     // else if (keycode == 5)
//     // {
//     //      deux_d.x *= 0.2;
//     //     deux_d.y *= 0.2;
//     //     ft_mandelbrot(win, z, deux_d, stock);
//     //     // mlx_put_image_to_window(init_ret, wind_ret, new_image_ret, 0, 0);
//     //     mlx_put_image_to_window(vargs->mlx, vargs->win, stock.image, 0, 0);

//     // }

//     return 0;
// }

// int main()
// {
//     t_varstock stock;
//     t_dimensions    dmn;
//     t_dimensions    wnd;
//     t_equation r;
//     void    *new_image_ret;

//     // ft_startingmain(&stock, &win_dmn, &r);
//     stock.init_ret = mlx_init();
//     wnd.x = 1000;
//     wnd.y = 1000;
//     dmn.x = 4.0;
//     dmn.y = 4.0;
//     stock.iteration = 100;
//     stock.color = 0x00FF4500;
//     t_zoomcrd yo;
//     yo.x_max = 2;
//     yo.x_min = -2;
//     yo.y_max = 2;
//     yo.y_min = -2;
//     stock.win_ret = mlx_new_window(stock.init_ret, wnd.y, wnd.x, "EVBLOOD");
//     stock.image = mlx_new_image(stock.init_ret, wnd.y, wnd.x);
// // void	*ft_mandelbrot(t_varstock stock, t_dimensions win, t_equation r, t_dimensions dmn)

//     ft_mandelbrot(stock, wnd, r, yo, 0, 0);
//     stock.r = &r;
//     stock.wnd = &wnd;
//     stock.dmn =&dmn;
//     stock.go = &yo;
//     mlx_put_image_to_window(stock.init_ret, stock.win_ret, stock.image, 0, 0);
//     mlx_hook(stock.win_ret,4 , 0, key_hook, &stock);
//     // mlx_hook(stock.win_ret,4 , 0, mose_move, &stock);
//     // mlx_put_image_to_window(stock.init_ret, stock.win_ret, new_image_ret, 0, 0);
//     mlx_loop(stock.init_ret);
// }
#include "fract.h"

void	*ft_mandelbrot(t_varstock *stock, float x, float y)
{
    long double     count;
    t_dimensions    x_y;
	int             *buffer;
    
    buffer = ft_new_image(stock);
    x_y.y = 0.0;
    while (x_y.y < stock->wnd->y)
    {
        x_y.x = 0.0;
        while (x_y.x < stock->wnd->x)
        {
       		count = -1;
            ft_initial(stock, x_y, x, y);
            while (++count < stock->iteration)
                if(ft_drowing(stock))
                    break;
            buffer[(int)(x_y.y * stock->wnd->x + x_y.x)] = stock->color + (stock->iteration - count) * 15 * 200;
            x_y.x++;
        }
        x_y.y++;
    }
    return (stock->image);
}

void    ft_initial(t_varstock *stock, t_dimensions x_y, float x, float y)
{
    stock->r->z.y = x_y.y * (stock->go->y_max - stock->go->y_min) / stock->wnd->y + stock->go->y_min;
    stock->r->z.x = (stock->go->x_max - stock->go->x_min) * x_y.x / stock->wnd->x + stock->go->x_min;
    stock->r->c.x = x;
    stock->r->c.y = y;
}

int ft_drowing(t_varstock *stock)
{
    float   tmp_z;
    tmp_z = stock->r->z.x;
    stock->r->z.x = (stock->r->z.x * stock->r->z.x) - (stock->r->z.y * stock->r->z.y) + stock->r->c.x;
    stock->r->z.y = 2 * tmp_z * stock->r->z.y + stock->r->c.y;
    if ((stock->r->z.x * stock->r->z.x) + (stock->r->z.y * stock->r->z.y) > 4)
        return (1);
    return (0);
}

int	key_hook(int keycode, int x ,int y, t_varstock *rec)
{
    double  i;
    double  n;

    i = 0;
    n = 0;
    rec->juliax = 0;
    rec->juliay = 0;
    if (keycode == 5)
    {
        rec->juliay = y * (rec->go->y_max - rec->go->y_min) / (rec->wnd->y) + rec->go->y_min;
        rec->juliax = x * (rec->go->x_max - rec->go->x_min) / (rec->wnd->x) + rec->go->x_min;
        rec->iteration += 50;
        apply_zoom(rec->go, rec->juliax, rec->juliay, 0.9);
    }
    else if (keycode == 4)
    {
        rec->juliay = y * (rec->go->y_max - rec->go->y_min) / (rec->wnd->y) + rec->go->y_min;
        rec->juliax = x * (rec->go->x_max - rec->go->x_min) / (rec->wnd->x) + rec->go->x_min;
        if (rec->iteration > 100)
            rec->iteration -= 50;
        apply_zoom(rec->go, rec->juliax, rec->juliay, 1/0.9);
    }
    ft_mandelbrot(rec, rec->juliax, rec->juliay);
    mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
    return 0;
}

int ft_exit(t_varstock *rec)
{
    free(rec->wnd);
    free(rec->dmn);
    free(rec->go);
    free(rec->r);
    mlx_destroy_image(rec->init_ret, rec->image);
    mlx_destroy_window(rec->init_ret, rec->win_ret);
    exit(0);
    return (0);
}

int ft_keybord(int keycode, t_varstock *rec)
{
    double   percx;
    double   percy;

    if (keycode == 53)
        ft_exit(rec);
    percx = (rec->go->x_max - rec->go->x_min) / 4;
    percy = (rec->go->y_max - rec->go->y_min) / 4;
    if (keycode == 123)
    {
        rec->go->x_max +=  percx;
        rec->go->x_min +=  percx;
    }
    else if (keycode == 124)
    {
        rec->go->x_max -=  percx;
        rec->go->x_min -=  percx;
    }
    else if (keycode == 126)
    {
        rec->go->y_max +=  percy;
        rec->go->y_min +=  percy;
    }
    else if (keycode == 125)
    {
        rec->go->y_max -=  percy;
        rec->go->y_min -=  percy;
    }
    ft_mandelbrot(rec, rec->juliax, rec->juliay);
    mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
    return (0);
}

void    ft_stockini(t_varstock *stock)
{
    t_dimensions    *dmn;
    t_dimensions    *wnd;
    t_equation      *r;
    t_zoomcrd       *yo;

    dmn = malloc(sizeof(t_dimensions));
    wnd = malloc(sizeof(t_dimensions));
    r = malloc(sizeof(t_equation));
    yo = malloc(sizeof(t_zoomcrd));
    wnd->x = 1000;
    wnd->y = 1000;
    dmn->x = 4.0;
    dmn->y = 4.0;
    yo->x_max = 2;
    yo->x_min = -2;
    yo->y_max = 2;
    yo->y_min = -2;
    stock->r = r;
    stock->wnd = wnd;
    stock->dmn =dmn;
    stock->go = yo;
}

int main()
{
    t_varstock  stock;
    void        *new_image_ret;

    stock.init_ret = mlx_init();
    ft_stockini(&stock);
    stock.iteration = 50;
    stock.color = 0x00FF4500;
    stock.win_ret = mlx_new_window(stock.init_ret, stock.wnd->y, stock.wnd->x, "EVBLOOD");
    stock.image = mlx_new_image(stock.init_ret, stock.wnd->y, stock.wnd->x);
    stock.juliax = 0;
    stock.juliay = 0;
    ft_mandelbrot(&stock, 0, 0);
    mlx_put_image_to_window(stock.init_ret, stock.win_ret, stock.image, 0, 0);
    // mlx_hook(stock.win_ret, 6, 0, mouse_hook, &stock);
    mlx_hook(stock.win_ret, 17, 0, ft_exit, &stock);
    mlx_hook(stock.win_ret, 2, 0, ft_keybord, &stock);
    mlx_hook(stock.win_ret, 4, 0, key_hook, &stock);
    mlx_loop(stock.init_ret);
}

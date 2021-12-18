/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:20:37 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 01:46:21 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*ft_julia(t_varstock *stock, float x, float y)
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
    ft_julia(rec, rec->juliax, rec->juliay);
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
    ft_julia(rec, rec->juliax, rec->juliay);
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
    ft_julia(&stock, 0, 0);
    mlx_put_image_to_window(stock.init_ret, stock.win_ret, stock.image, 0, 0);
    mlx_hook(stock.win_ret, 6, 0, mouse_hook, &stock);
    mlx_hook(stock.win_ret, 17, 0, ft_exit, &stock);
    mlx_hook(stock.win_ret, 2, 0, ft_keybord, &stock);
    mlx_hook(stock.win_ret, 4, 0, key_hook, &stock);
    mlx_loop(stock.init_ret);
}

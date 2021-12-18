/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:01:36 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 23:03:41 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*ft_mandelbrot(t_varstock *stock)
{
	long double		count;
	t_dimensions	x_y;
	int				*buffer;

	mlx_clear_window(stock->init_ret, stock->win_ret);
	buffer = ft_new_image(stock);
	x_y.y = 0.0;
	while (x_y.y < stock->wnd->y)
	{
		x_y.x = 0.0;
		while (x_y.x < stock->wnd->x)
		{
			count = -1;
			ft_initialmandel(stock, x_y);
			while (++count < stock->iteration)
				if (ft_drowing(stock))
					break ;
			buffer[(int)(x_y.y * stock->wnd->x + x_y.x)]
				= ft_colorate(count, stock->iteration, stock);
			x_y.x++;
		}
		x_y.y++;
	}
	return (stock->image);
}

void	ft_initialmandel(t_varstock *stock, t_dimensions x_y)
{
	stock->r->z.y = 0;
	stock->r->z.x = 0;
	stock->r->c.x = (stock->go->x_max - stock->go->x_min) * x_y.x
		/ stock->wnd->x + stock->go->x_min;
	stock->r->c.y = x_y.y * (stock->go->y_max - stock->go->y_min)
		/ stock->wnd->y + stock->go->y_min;
}

int	ft_drowing(t_varstock *stock)
{
	float	tmp_z;

	tmp_z = stock->r->z.x;
	stock->r->z.x = (stock->r->z.x * stock->r->z.x)
		- (stock->r->z.y * stock->r->z.y) + stock->r->c.x;
	stock->r->z.y = 2 * tmp_z * stock->r->z.y + stock->r->c.y;
	if ((stock->r->z.x * stock->r->z.x) + (stock->r->z.y * stock->r->z.y) > 4)
		return (1);
	return (0);
}

int	key_hook(int keycode, int x, int y, t_varstock *rec)
{
	double	i;
	double	n;

	i = 0;
	n = 0;
	rec->juliax = 0;
	rec->juliay = 0;
	if (keycode == 5)
	{
		ft_mnadelzoomin(rec, x, y);
		apply_zoom(rec->go, rec->juliax, rec->juliay, 0.9);
	}
	else if (keycode == 4)
	{
		rec->juliay = y * (rec->go->y_max - rec->go->y_min)
			/ (rec->wnd->y) + rec->go->y_min;
		rec->juliax = x * (rec->go->x_max - rec->go->x_min)
			/ (rec->wnd->x) + rec->go->x_min;
		if (rec->iteration > 100)
			rec->iteration -= 50;
		apply_zoom(rec->go, rec->juliax, rec->juliay, 1 / 0.9);
	}
	ft_mandelbrot(rec);
	mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
	return (0);
}

void	callmandel(void)
{
	t_varstock	stock;

	stock.init_ret = mlx_init();
	ft_stockini(&stock);
	stock.iteration = 50;
	stock.win_ret = mlx_new_window(stock.init_ret, stock.wnd->y,
			stock.wnd->x, "Mandelbrot set");
	stock.image = mlx_new_image(stock.init_ret, stock.wnd->y, stock.wnd->x);
	ft_mandelbrot(&stock);
	mlx_put_image_to_window(stock.init_ret, stock.win_ret, stock.image, 0, 0);
	mlx_hook(stock.win_ret, 17, 0, ft_exit, &stock);
	mlx_hook(stock.win_ret, 2, 0, ft_mandelkeybord, &stock);
	mlx_hook(stock.win_ret, 4, 0, key_hook, &stock);
	mlx_loop(stock.init_ret);
}

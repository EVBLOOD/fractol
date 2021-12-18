/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:20:37 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 12:40:09 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*ft_julia(t_varstock *stock, float x, float y)
{
	long double		count;
	t_dimensions	x_y;
	int				*buffer;

	buffer = ft_new_image(stock);
	x_y.y = 0.0;
	while (x_y.y < stock->wnd->y)
	{
		x_y.x = 0.0;
		while (x_y.x < stock->wnd->x)
		{
			count = -1;
			ft_initialjulia(stock, x_y, x, y);
			while (++count < stock->iteration)
				if (ft_drowjulia(stock))
					break ;
			buffer[(int)(x_y.y * stock->wnd->x + x_y.x)]
				= stock->color + (stock->iteration - count) * 15 * 200;
			x_y.x++;
		}
		x_y.y++;
	}
	return (stock->image);
}

int	ft_drowjulia(t_varstock *stock)
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

int	key_hook_jl(int keycode, int x, int y, t_varstock *rec)
{
	double	i;
	double	n;

	i = 0;
	n = 0;
	rec->juliax = 0;
	rec->juliay = 0;
	if (keycode == 5)
	{
		ft_zoomin(rec, x, y);
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
	ft_julia(rec, rec->juliax, rec->juliay);
	mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
	return (0);
}

int	ft_keybord(int keycode, t_varstock *rec)
{
	double	percx;
	double	percy;

	if (keycode == 53)
		ft_exit(rec);
	percx = (rec->go->x_max - rec->go->x_min) / 4;
	percy = (rec->go->y_max - rec->go->y_min) / 4;
	ft_navigation(keycode, rec, percx, percy);
	ft_julia(rec, rec->juliax, rec->juliay);
	mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
	return (0);
}

void	calljulia(void)
{
	t_varstock	stock;
	void		*new_image_ret;

	stock.init_ret = mlx_init();
	ft_stockini(&stock);
	stock.iteration = 50;
	stock.color = 0x00FF4500;
	stock.win_ret = mlx_new_window(stock.init_ret, stock.wnd->y,
			stock.wnd->x, "Julia set");
	stock.image = mlx_new_image(stock.init_ret, stock.wnd->y, stock.wnd->x);
	stock.juliax = 0;
	stock.juliay = 0;
	ft_julia(&stock, 0, 0);
	mlx_put_image_to_window(stock.init_ret, stock.win_ret, stock.image, 0, 0);
	mlx_hook(stock.win_ret, 6, 0, mouse_hook, &stock);
	mlx_hook(stock.win_ret, 17, 0, ft_exit, &stock);
	mlx_hook(stock.win_ret, 2, 0, ft_keybord, &stock);
	mlx_hook(stock.win_ret, 4, 0, key_hook_jl, &stock);
	mlx_loop(stock.init_ret);
}

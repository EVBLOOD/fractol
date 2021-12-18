/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:58:16 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 17:24:18 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	mouse_hook(int x, int y, t_varstock *rec)
{
	rec->juliay = y * (rec->go->y_max - rec->go->y_min)
		/ (rec->wnd->y) + rec->go->y_min;
	rec->juliax = x * (rec->go->x_max - rec->go->x_min)
		/ (rec->wnd->x) + rec->go->x_min;
	ft_julia(rec, rec->juliax, rec->juliay);
	mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
	return (0);
}

void	ft_initialjulia(t_varstock *stock, t_dimensions x_y, float x, float y)
{
	stock->r->z.y = x_y.y * (stock->go->y_max - stock->go->y_min)
		/ stock->wnd->y + stock->go->y_min;
	stock->r->z.x = (stock->go->x_max - stock->go->x_min) * x_y.x
		/ stock->wnd->x + stock->go->x_min;
	stock->r->c.x = x;
	stock->r->c.y = y;
}

void	ft_zoomin(t_varstock *rec, int x, int y)
{
	rec->juliay = y * (rec->go->y_max - rec->go->y_min)
		/ (rec->wnd->y) + rec->go->y_min;
	rec->juliax = x * (rec->go->x_max - rec->go->x_min)
		/ (rec->wnd->x) + rec->go->x_min;
	rec->iteration += 50;
	apply_zoom(rec->go, rec->juliax, rec->juliay, 0.9);
}

void	ft_navigation(int keycode, t_varstock *rec, double percx, double percy)
{
	if (keycode == 123)
	{
		rec->go->x_max += percx;
		rec->go->x_min += percx;
	}
	else if (keycode == 124)
	{
		rec->go->x_max -= percx;
		rec->go->x_min -= percx;
	}
	else if (keycode == 126)
	{
		rec->go->y_max += percy;
		rec->go->y_min += percy;
	}
	else if (keycode == 125)
	{
		rec->go->y_max -= percy;
		rec->go->y_min -= percy;
	}
}

double	ft_colorate(double c, double cmp, t_varstock *stock)
{
	if (c != cmp)
		return (stock->color + (c * 1248518));
	return (0);
}

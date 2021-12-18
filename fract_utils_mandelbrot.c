/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:51:51 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 12:17:19 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_mnadelzoomin(t_varstock *rec, int x, int y)
{
	rec->juliay = y * (rec->go->y_max - rec->go->y_min)
		/ (rec->wnd->y) + rec->go->y_min;
	rec->juliax = x * (rec->go->x_max - rec->go->x_min)
		/ (rec->wnd->x) + rec->go->x_min;
	rec->iteration += 50;
	apply_zoom(rec->go, rec->juliax, rec->juliay, 0.9);
}

int	ft_mandelkeybord(int keycode, t_varstock *rec)
{
	double	percx;
	double	percy;

	if (keycode == 53)
		ft_exit(rec);
	percx = (rec->go->x_max - rec->go->x_min) / 4;
	percy = (rec->go->y_max - rec->go->y_min) / 4;
	ft_mandelnavigation(keycode, rec, percx, percy);
	ft_mandelbrot(rec);
	mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
	return (0);
}

void	ft_mandelnavigation(int keycode, t_varstock *rec
		, double percx, double percy)
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

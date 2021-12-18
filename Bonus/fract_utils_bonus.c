/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:51:51 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 19:39:34 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_bonus.h"

void	ft_burningzoomin(t_varstock *rec, int x, int y)
{
	rec->juliay = y * (rec->go->y_max - rec->go->y_min)
		/ (rec->wnd->y) + rec->go->y_min;
	rec->juliax = x * (rec->go->x_max - rec->go->x_min)
		/ (rec->wnd->x) + rec->go->x_min;
	rec->iteration += 50;
	apply_zoom(rec->go, rec->juliax, rec->juliay, 0.9);
}

int	ft_burningkeybord(int keycode, t_varstock *rec)
{
	double	percx;
	double	percy;

	if (keycode == 53)
		ft_exit(rec);
	if (keycode == 69)
	{
		rec->color = rec->color >> 1;
	}
	else if (keycode == 78)
	{
		rec->color = rec->color << 1;
	}
	else
	{
		percx = 0.01;
		percy = 0.01;
		ft_burningnavigation(keycode, rec, percx, percy);
	}
	ft_burning(rec);
	mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
	return (0);
}

void	ft_burningnavigation(int keycode, t_varstock *rec
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

double	ft_colorate(double c, double cmp, t_varstock *stock)
{
	if (c != cmp)
		return (stock->color + (c * 1248518));
	return (0);
}

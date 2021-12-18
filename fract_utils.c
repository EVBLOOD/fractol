/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:30:59 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 11:10:13 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	*ft_new_image(t_varstock *stock)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int	*buffer;

	buffer = (int *)mlx_get_data_addr(stock->image, &pixel_bits,
			&line_bytes, &endian);
	return (buffer);
}

double	interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

void	apply_zoom(t_zoomcrd *cord, double m_x, double m_y, double interp)
{
	cord->x_min = interpolate(m_x, cord->x_min, interp);
	cord->y_min = interpolate(m_y, cord->y_min, interp);
	cord->x_max = interpolate(m_x, cord->x_max, interp);
	cord->y_max = interpolate(m_y, cord->y_max, interp);
}

int	ft_exit(t_varstock *rec)
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

void	ft_stockini(t_varstock *stock)
{
	t_dimensions	*dmn;
	t_dimensions	*wnd;
	t_equation		*r;
	t_zoomcrd		*yo;

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
	stock->dmn = dmn;
	stock->go = yo;
}

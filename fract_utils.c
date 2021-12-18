/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:30:59 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/17 21:02:32 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	*ft_new_image(t_varstock *stock)
{
	int pixel_bits;
    int line_bytes;
    int endian;
	int *buffer;

    buffer = (int *)mlx_get_data_addr(stock->image, &pixel_bits, &line_bytes, &endian);
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

int	mouse_hook(int x,int y, t_varstock *rec)
{

    rec->juliay = y * (rec->go->y_max - rec->go->y_min) / (rec->wnd->y) + rec->go->y_min;
    rec->juliax = x * (rec->go->x_max - rec->go->x_min) / (rec->wnd->x) + rec->go->x_min;
    ft_julia(rec, rec->juliax, rec->juliay);
    mlx_put_image_to_window(rec->init_ret, rec->win_ret, rec->image, 0, 0);
    return (0);
}

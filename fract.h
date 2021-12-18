/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:02:14 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/17 23:01:19 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "mlx.h"
#include <math.h>
#include <stdlib.h>
typedef struct	s_dimensions {
	double	x;
	double	y;
}	t_dimensions;

typedef struct	s_equation {
	t_dimensions z;
	t_dimensions c;
}	t_equation;

typedef struct	s_zoomcrd {
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
}	t_zoomcrd;

typedef struct	s_varstock {
	long double		iteration;
	int				color;
	void			*init_ret;
	void			*win_ret;
	void			*image;
	t_zoomcrd		*go;
	t_dimensions	*dmn;
    t_dimensions	*wnd;
    t_equation		*r;
	double			juliax;
	double			juliay;
}	t_varstock;

int	*ft_new_image(t_varstock *stock);
void	apply_zoom(t_zoomcrd *cord, double m_x, double m_y, double interp);
int	mouse_hook(int x,int y, t_varstock *rec);
void	*ft_julia(t_varstock *stock, float x, float y);
void    ft_initial(t_varstock *stock, t_dimensions x_y, float x, float y);
int ft_drowing(t_varstock *stock);
// int ft_keybord(int keycode, t_varstock *rec);
#endif
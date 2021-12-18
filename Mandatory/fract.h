/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:02:14 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 17:25:20 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_dimensions {
	double	x;
	double	y;
}	t_dimensions;

typedef struct s_equation {
	t_dimensions	z;
	t_dimensions	c;
}	t_equation;

typedef struct s_zoomcrd {
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
}	t_zoomcrd;

typedef struct s_varstock {
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

int		mouse_hook(int x, int y, t_varstock *rec);
void	ft_initialjulia(t_varstock *stock, t_dimensions x_y, float x, float y);
void	ft_zoomin(t_varstock *rec, int x, int y);
void	ft_navigation(int keycode, t_varstock *rec, double percx, double percy);
void	ft_mnadelzoomin(t_varstock *rec, int x, int y);
int		ft_mandelkeybord(int keycode, t_varstock *rec);
void	ft_mandelnavigation(int keycode, t_varstock *rec,
			double percx, double percy);
int		*ft_new_image(t_varstock *stock);
double	interpolate(double start, double end, double interp);
void	apply_zoom(t_zoomcrd *cord, double m_x, double m_y, double interp);
int		ft_exit(t_varstock *rec);
void	ft_stockini(t_varstock *stock);
void	*ft_julia(t_varstock *stock, float x, float y);
int		ft_drowjulia(t_varstock *stock);
int		key_hook_jl(int keycode, int x, int y, t_varstock *rec);
int		ft_keybord(int keycode, t_varstock *rec);
void	calljulia(void);
void	*ft_mandelbrot(t_varstock *stock);
void	ft_initialmandel(t_varstock *stock, t_dimensions x_y);
int		ft_drowing(t_varstock *stock);
int		key_hook(int keycode, int x, int y, t_varstock *rec);
void	callmandel(void);
double	ft_colorate(double c, double cmp, t_varstock *stock);
#endif
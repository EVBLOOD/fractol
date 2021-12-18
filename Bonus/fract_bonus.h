/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:02:14 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 23:18:41 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_BONUS_H
# define FRACT_BONUS_H
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

void	ft_burningzoomin(t_varstock *rec, int x, int y);
int		ft_burningkeybord(int keycode, t_varstock *rec);
void	ft_burningnavigation(int keycode, t_varstock *rec,
			double percx, double percy);
void	callburning(void);
int		key_hook(int keycode, int x, int y, t_varstock *rec);
int		ft_drowing(t_varstock *stock);
void	ft_initialburning(t_varstock *stock, t_dimensions x_y);
void	*ft_burning(t_varstock *stock);
int		ft_exit(t_varstock *rec);
int		*ft_new_image(t_varstock *stock);
double	interpolate(double start, double end, double interp);
void	ft_stockini(t_varstock *stock);
void	apply_zoom(t_zoomcrd *cord, double m_x, double m_y, double interp);
double	ft_colorate(double c, double cmp, t_varstock *stock);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 06:02:14 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/15 12:03:28 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include "mlx.h"


typedef struct	s_dimensions {
	float	x;
	float	y;
}	t_dimensions;

typedef struct	s_equation {
	t_dimensions z;
	t_dimensions c;
}	t_equation;

typedef struct	s_varstock {
	int		iteration;
	int		color;
	void	*init_ret;
	void	*win_ret;
	void	*image;
	t_dimensions    *dmn;
    t_dimensions    *wnd;
    t_equation *r;
}	t_varstock;
#endif
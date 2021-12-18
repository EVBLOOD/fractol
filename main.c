/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:17:55 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/18 15:52:35 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *) s1;
	st2 = (unsigned char *) s2;
	while ((st1[i] || st2[i]))
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("please chose first each fractal you want to see.\n");
		printf("		we have here:\n");
		printf("\e[1;34m-Mandelbrot\e[0m\n");
		printf("-Julia\n");
	}
	else
	{
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			callmandel();
		else if (!ft_strcmp(argv[1], "Julia"))
			calljulia();
		else
		{
			printf("please chose the correct fractal\n");
			printf("we only have here:\n");
			printf("****Mandelbrot****\n");
			printf("***Julia\n");
		}
	}
}

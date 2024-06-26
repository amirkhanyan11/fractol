/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:43:07 by aamirkha          #+#    #+#             */
/*   Updated: 2024/04/04 17:00:39 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	t_complex	julia;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
	{
		fractal_init("mandelbrot", 0, &fractal);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", ft_strlen("julia")))
	{
		julia.real = atodouble(av[2]);
		julia.i = atodouble(av[3]);
		fractal_init("julia", &julia, &fractal);
	}
	else
		exit(EXIT_FAILURE);
	fractal_render(&fractal);
	mlx_loop(fractal.connect.mlx);
	return (0);
}

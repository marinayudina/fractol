/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:36:49 by bpono             #+#    #+#             */
/*   Updated: 2022/03/02 21:46:17 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../fractol.h"

void	my_mlx_pixel_put(t_fract *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_list	init_complex(double re, double im)
{
	t_list	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	get_colour(int it)
{
	if (it >= 150)
		return (0);
	else
		return (create_trgb(0, (255 * it) % 256, (153 * it) % 256, \
			(204 * it) % 256));
}

void	ft_error(void)
{
	write(2, "Wrong arguments\n", 17);
	exit(1);
}

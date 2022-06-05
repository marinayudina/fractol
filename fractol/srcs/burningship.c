/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:19:32 by bpono             #+#    #+#             */
/*   Updated: 2022/03/02 21:35:35 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <mlx.h>

int	func_bs(t_fract *data)
{
	int	n;

	n = 0;
	data->c_re = data->x;
	data->c_im = data->y;
	data->x = 0;
	data->y = 0;
	while (n < 300 && (data->x * data->x + data->y * data->y) <= 4)
	{
		data->tmp_re = data->x * data->x - data->y * data->y;
		data->tmp_im = fabs(2.0 * data->x * data->y);
		data->x = data->tmp_re + data->c_re;
		data->y = data->tmp_im + data->c_im;
		n++;
	}
	return (n);
}

void	create_fractol_bs(t_fract *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			data->x = ((double)i / WIDTH * data->scale + data->x1);
			data->y = ((double)j / WIDTH * data->scale + data->y1);
			data->it = func_bs(data);
			my_mlx_pixel_put(data, i, j, \
			data->colour * get_colour(data->it));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	zoom_bs(int mousecode, int x, int y, t_fract *data)
{
	double		realx;
	double		realy;

	realx = data->x1 + (double)x / WIDTH * data->scale;
	realy = data->y1 + (double)y / WIDTH * data->scale;
	if (mousecode == SCROLL_UP)
	{
		data->scale *= 1.1;
		data->x1 = (data->x1 - realx) * 1.1 + realx;
		data->y1 = (data->y1 - realy) * 1.1 + realy;
		create_fractol(data);
	}
	else if (mousecode == SCROLL_DOWN)
	{
		data->scale /= 1.1;
		data->x1 = (data->x1 - realx) / 1.1 + realx;
		data->y1 = (data->y1 - realy) / 1.1 + realy;
		create_fractol_bs(data);
	}
	return (0);
}

void	event_bs(t_fract *data)
{
	mlx_hook(data->win, 2, 0, key_pressed_bs, data);
	mlx_hook(data->win, 17, 0, terminate, data);
	mlx_hook(data->win, 4, 0, zoom_bs, data);
}

void	make_fract_bs(void)
{
	t_fract	data;

	data.scale = 4;
	data.colour = 1;
	data.x1 = -2;
	data.y1 = -2;
	data_init(&data);
	create_fractol_bs(&data);
	event_bs(&data);
	mlx_loop(data.mlx);
}

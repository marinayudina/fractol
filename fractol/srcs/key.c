/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:12:26 by bpono             #+#    #+#             */
/*   Updated: 2022/03/02 16:46:49 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <mlx.h>
#include <stdio.h>

int	key_pressed(int key, t_fract *data)
{
	if (key == KEY_ESC)
		terminate(data);
	else if (key == KEY_LEFT)
		data->x1 -= 0.2 * data->scale;
	else if (key == KEY_RIGHT)
		data->x1 += 0.2 * data->scale;
	else if (key == KEY_DOWN)
		data->y1 += 0.2 * data->scale;
	else if (key == KEY_UP)
		data->y1 -= 0.2 * data->scale;
	else if (key == 49)
	{
		if (data->colour * 2 > 1000000)
			data->colour = 1;
		data->colour *= 2;
	}
	create_fractol(data);
	return (0);
}

int	key_pressed_julia(int key, t_fract *data)
{
	if (key == KEY_ESC)
		terminate(data);
	else if (key == KEY_LEFT)
		data->x1 -= 0.2 * data->scale;
	else if (key == KEY_RIGHT)
		data->x1 += 0.2 * data->scale;
	else if (key == KEY_DOWN)
		data->y1 += 0.2 * data->scale;
	else if (key == KEY_UP)
		data->y1 -= 0.2 * data->scale;
	else if (key == 49)
	{
		if (data->colour * 2 > 1000000)
			data->colour = 1;
		data->colour *= 2;
	}
	create_fractol_julia(data);
	return (0);
}

int	key_pressed_bs(int key, t_fract *data)
{
	if (key == KEY_ESC)
		terminate(data);
	else if (key == KEY_LEFT)
		data->x1 -= 0.2 * data->scale;
	else if (key == KEY_RIGHT)
		data->x1 += 0.2 * data->scale;
	else if (key == KEY_DOWN)
		data->y1 += 0.2 * data->scale;
	else if (key == KEY_UP)
		data->y1 -= 0.2 * data->scale;
	else if (key == 49)
	{
		if (data->colour * 2 > 1000000)
			data->colour = 1;
		data->colour *= 2;
	}
	create_fractol_bs(data);
	return (0);
}

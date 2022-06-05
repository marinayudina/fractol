/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:17:44 by bpono             #+#    #+#             */
/*   Updated: 2022/03/02 21:36:37 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../fractol.h"

// void ft_end(char *str,int i,long long res)
// {
// 	if (str[i] == '\0')
// 		answ = d * res / pow(10, k);
// 	else
// 		ft_error();
// 	return (answ);
// }

t_check	*make_args(void)
{
	t_check	*arg;

	arg = (t_check *)malloc(sizeof(t_check));
	arg->i = 0;
	arg->d = 1;
	arg->res = 0;
	arg->answ = 0 ;
	arg->k = 0;
	return (arg);
}

float	conv_argc(char *str)
{
	t_check	*args;

	args = make_args();
	if (str[args->i] == '-' || str[args->i] == '+')
		if (str[args->i++] == '-')
			args->d = args->d * (-1);
	while (str[args->i] >= '0' && str[args->i] <= '9')
		args->res = args->res * 10 + str[args->i++] - '0';
	if (str[args->i] == '\0')
		return (args->res);
	if (str[args->i] == '.' && str[args->i + 1] >= '0'\
	&& str[args->i + 1] <= '9')
		args->i++;
	else
		ft_error();
	while (str[args->i] >= '0' && str[args->i] <= '9')
	{
		args->res = args->res * 10 + str[args->i++] - '0';
		args->k++;
	}
	if (str[args->i] == '\0')
		return (args->d * args->res / pow(10, args->k));
	ft_error();
	return (-1);
}

t_list	check_argc(char *s1, char *s2)
{
	float	res1;
	float	res2;
	t_list	jul_argc;

	res1 = conv_argc(s1);
	res2 = conv_argc(s2);
	jul_argc = init_complex(res1, res2);
	return (jul_argc);
}

int	check_fract(int argc, char **argv)
{
	t_list	jul_argc;

	if (!ft_strcmp("mandelbrot", argv[1]))
		make_fract();
	else if (!ft_strcmp("julia", argv[1]))
	{
		if (argc == 4)
		{
			jul_argc = check_argc(argv[2], argv[3]);
			make_fract_julia(jul_argc);
		}
		else if (argc == 2)
		{
			jul_argc = init_complex(0.36, 0.36);
			make_fract_julia(jul_argc);
		}
		else
			ft_error();
	}
	else if (!ft_strcmp("burning_ship", argv[1]))
		make_fract_bs();
	return (-1);
}

int	main(int argc, char **argv)
{
	if (argc < 2 || check_fract(argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		write(2, "Write mandelbrot\n", 18);
		write(2, "Write julia float1 float2\n", 27);
		write(2, "Write burning_ship\n", 20);
		return (0);
	}
	return (0);
}

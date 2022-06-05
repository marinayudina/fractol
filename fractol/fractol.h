/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpono <bpono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:47:40 by bpono             #+#    #+#             */
/*   Updated: 2022/03/02 21:43:52 by bpono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 700
# define HEIGHT 700
# define SIZE 700
# define KEY_ESC 53
# define KEY_UP	126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT 124
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# include <math.h>
# include "unistd.h"
# include <stdlib.h>

typedef struct t_fract{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	float	x1;
	float	y1;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		colour;
	int		it ;
	double	x;
	double	y;
	double	scale;
	float	c_re;
	float	c_im;
	double	tmp_re;
	double	tmp_im;
}				t_fract;

typedef struct t_list{
	float	im;
	float	re;
}	t_list;

typedef struct t_check{
	unsigned int	i;
	int				d;
	long long		res;
	float			answ;
	int				k;
}	t_check;

int		ft_strcmp(char *s1, char *s2);
void	ft_error(void);
int		create_trgb(int t, int r, int g, int b);
int		key_pressed(int key, t_fract *data);
void	make_fract_julia(t_list jul_args);
int		key_pressed_julia(int key, t_fract *data);
int		get_colour(int it);
int		check_fract(int argc, char **argv);
void	my_mlx_pixel_put(t_fract *data, int x, int y, int color);
void	create_fractol_bs(t_fract *data);
void	make_fract_bs(void);
void	create_fractol_julia(t_fract *data);
void	data_init(t_fract *data);
void	make_fract(void);
int		terminate( t_fract *data);
void	create_fractol(t_fract *data);
int		key_pressed_bs(int key, t_fract *data);
void	leave(int code);
int		terminate( t_fract *data);
void	data_init(t_fract *data);
void	my_mlx_pixel_put(t_fract *data, int x, int y, int color);
t_list	init_complex(double re, double im);
int		get_colour(int it);
#endif
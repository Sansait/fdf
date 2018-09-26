/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:49:46 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/26 15:24:00 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	setup(void *mlx_ptr, void *win_ptr)
{
	mlx_string_put(mlx_ptr, win_ptr, 1600, 200, 16777215,
				"Right click or R/T to rotate");
	mlx_string_put(mlx_ptr, win_ptr, 1600, 250, 16777215,
				"Left click to move");
	mlx_string_put(mlx_ptr, win_ptr, 1600, 300, 16777215, "+/- to zoom in/out");
	mlx_string_put(mlx_ptr, win_ptr, 1600, 350, 16777215,
				"* or / to change relief");
	mlx_string_put(mlx_ptr, win_ptr, 1600, 400, 16777215, "C to change color");
	mlx_string_put(mlx_ptr, win_ptr, 943, 30, 16777215, "FdF");
}

void	first_params(t_data *data)
{
	data->zoom = (600 / data->l);
	data->relief = 0.5;
	data->sx = 0;
	data->sy = 0;
	data->ax = -0.1;
	data->ay = 0.1;
	data->az = -0.2;
	data->midf.x = data->ll[data->l - 1] / 2;
	data->midf.y = data->l / 2;
	data->mid.x = (1920 / 2) - data->midf.x;
	data->mid.y = (1080 / 2) - data->midf.y;
	data->color = 16777215;
	data->click_d = 0;
	data->click_g = 0;
}

int		main(int ac, char **av)
{
	t_data		*data;
	int			osef;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file");
		return (0);
	}
	if (!(data = malloc(sizeof(t_data))))
		return (0);
	if (reader(av[1], data) == 0)
	{
		ft_putendl("error: file not recognized");
		return (0);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fdf");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img = (int*)mlx_get_data_addr(data->img_ptr, &osef, &osef, &osef);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	first_params(data);
	centraldisp(data);
	setup(data->mlx_ptr, data->win_ptr);
	mlx_hook(data->win_ptr, 2, osef, key_press, data);
	mlx_hook(data->win_ptr, 4, osef, mouse_press, data);
	mlx_hook(data->win_ptr, 5, osef, mouse_release, data);
	mlx_hook(data->win_ptr, 6, osef, mouse_move, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

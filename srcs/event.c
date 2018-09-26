/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:36:20 by sklepper          #+#    #+#             */
/*   Updated: 2018/08/08 18:19:19 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			key_press(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	if (key == 69)
		data->zoom += 2;
	if (key == 78)
		data->zoom -= 2;
	if (key == 15)
		data->az += 0.1;
	if (key == 17)
		data->az -= 0.1;
	if (key == 8)
		data->color += 1000;
	if (key == 67)
		data->relief += 0.1;
	if (key == 75)
		data->relief -= 0.1;
	centraldisp(data);
	return (0);
}

int			mouse_press(int b, int x, int y, void *param)
{
	t_data *data;

	if (b == 1)
	{
		data = param;
		data->click_g = 1;
		data->mouse_last_x = x;
		data->mouse_last_y = y;
	}
	if (b == 2)
	{
		data = param;
		data->click_d = 1;
		data->mouse_last_x = x;
		data->mouse_last_y = y;
	}
	return (0);
}

int			mouse_release(int b, int x, int y, void *param)
{
	t_data *data;

	(void)x;
	(void)y;
	if (b == 1)
	{
		data = param;
		data->click_g = 0;
	}
	if (b == 2)
	{
		data = param;
		data->click_d = 0;
	}
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_data	*data;
	float	dx;
	float	dy;

	data = param;
	if (data->click_d == 1 || data->click_g == 1)
	{
		dx = data->mouse_last_x - x;
		dy = data->mouse_last_y - y;
		data->mouse_last_y = y;
		data->mouse_last_x = x;
	}
	if (data->click_d == 1)
	{
		data->ay += dx / 1000;
		data->ax -= dy / 1000;
		centraldisp(data);
	}
	if (data->click_g == 1)
	{
		data->mid.y -= dy;
		data->mid.x -= dx;
		centraldisp(data);
	}
	return (0);
}

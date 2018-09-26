/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:16:18 by sklepper          #+#    #+#             */
/*   Updated: 2018/08/08 18:19:09 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_incx(t_incre *inc, t_coords *d)
{
	inc->incre = 2 * d->y;
	inc->incrne = 2 * (d->y - d->x);
	inc->e = 2 * d->y - d->x;
}

static void	ft_incy(t_incre *inc, t_coords *d)
{
	inc->incre = 2 * d->x;
	inc->incrne = 2 * (d->x - d->y);
	inc->e = 2 * d->x - d->y;
}

static void	lines_x(t_data *data, t_line *line, t_incre *inc, t_coords *d)
{
	t_coords	xy;

	xy.x = line->p0->x;
	xy.y = line->p0->y;
	ft_incx(inc, d);
	while (xy.x != line->p1->x)
	{
		if (xy.x + data->mid.x >= 0 && xy.y + data->mid.y >= 0 && xy.x +
				data->mid.x < 1920 && xy.y + data->mid.y < 1080)
			data->img[((xy.y * 1920) + xy.x) + (data->mid.x + data->mid.y
				* 1920)] = data->color;
		if (inc->e >= 0)
		{
			xy.y += inc->incy;
			inc->e += inc->incrne;
		}
		else
			inc->e += inc->incre;
		xy.x += inc->incx;
	}
}

static void	lines_y(t_data *data, t_line *line, t_incre *inc, t_coords *d)
{
	t_coords	xy;

	xy.y = line->p0->y;
	xy.x = line->p0->x;
	ft_incy(inc, d);
	while (xy.y != line->p1->y)
	{
		if (xy.x + data->mid.x >= 0 && xy.y + data->mid.y >= 0 && xy.x +
				data->mid.x < 1920 && xy.y + data->mid.y < 1080)
			data->img[((xy.y * 1920) + xy.x) + (data->mid.x + data->mid.y
				* 1920)] = data->color;
		if (inc->e >= 0)
		{
			xy.x += inc->incx;
			inc->e += inc->incrne;
		}
		else
			inc->e += inc->incre;
		xy.y += inc->incy;
	}
}

void		lines_img(t_data *data, t_line *line)
{
	t_coords	d;
	t_incre		inc;

	d.x = line->p1->x - line->p0->x;
	d.y = line->p1->y - line->p0->y;
	if (d.x > 0)
		inc.incx = 1;
	else
	{
		inc.incx = -1;
		d.x = -d.x;
	}
	if (d.y > 0)
		inc.incy = 1;
	else
	{
		inc.incy = -1;
		d.y = -d.y;
	}
	if (d.x > d.y)
		lines_x(data, line, &inc, &d);
	else
		lines_y(data, line, &inc, &d);
}

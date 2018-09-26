/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:37:39 by sklepper          #+#    #+#             */
/*   Updated: 2018/08/08 18:20:04 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void	make_line(t_coords p0, t_coords p1, t_line *line, t_data *d)
{
	p0.x -= d->midf.x;
	p0.y -= d->midf.y;
	p0.z *= d->relief;
	p1.x -= d->midf.x;
	p1.y -= d->midf.y;
	p1.z *= d->relief;
	line->p0->x = (int)roundf((cosf(d->ay) * cosf(d->az) * p0.x +
		(cosf(d->ax) * sinf(d->az) + sinf(d->ax) * sinf(d->ay) *
		cosf(d->az)) * p0.y + (sinf(d->ax) * sinf(d->az) -
		cosf(d->ax) * sinf(d->ay) * cosf(d->az)) * p0.z) * d->zoom);
	line->p0->y = (int)roundf((-cosf(d->ay) * sinf(d->az) * p0.x + (cosf(d->ax)
		* cosf(d->az) - sinf(d->ax) * sinf(d->ay) * sinf(d->az)) * p0.y +
		(sinf(d->ax) * cosf(d->az) + cosf(d->ax) * sinf(d->ay) * sinf(d->az)) *
		p0.z) * d->zoom);
	line->p1->x = (int)roundf((cosf(d->ay) * cosf(d->az) * p1.x +
		(cosf(d->ax) * sinf(d->az) + sinf(d->ax) * sinf(d->ay) *
		cosf(d->az)) * p1.y + (sinf(d->ax) * sinf(d->az) -
		cosf(d->ax) * sinf(d->ay) * cosf(d->az)) * p1.z) * d->zoom);
	line->p1->y = (int)roundf((-cosf(d->ay) * sinf(d->az) * p1.x + (cosf(d->ax)
		* cosf(d->az) - sinf(d->ax) * sinf(d->ay) * sinf(d->az)) * p1.y +
		(sinf(d->ax) * cosf(d->az) + cosf(d->ax) * sinf(d->ay) * sinf(d->az)) *
		p1.z) * d->zoom);
}

void	display_2(t_data *data, int x, int y, t_line *line)
{
	if (x <= data->ll[y] - 2)
	{
		make_line(data->tab[y][x], data->tab[y][x + 1], line, data);
		lines_img(data, line);
	}
	if (y <= data->l - 2 && x <= data->ll[y + 1] - 1)
	{
		make_line(data->tab[y][x], data->tab[y + 1][x], line, data);
		lines_img(data, line);
	}
}

void	display(t_data *data)
{
	t_line	*line;
	int		x;
	int		y;

	y = -1;
	if (!(line = malloc(sizeof(t_line))))
		return ;
	if (!(line->p0 = malloc(sizeof(t_coords))))
		return ;
	if (!(line->p1 = malloc(sizeof(t_coords))))
		return ;
	while (++y <= data->l - 1)
	{
		x = -1;
		while (++x <= data->ll[y] - 1)
		{
			display_2(data, x, y, line);
		}
	}
}

void	centraldisp(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->img, (1920 * 1080 * 4));
	display(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr,
							data->sx, data->sy);
	setup(data->mlx_ptr, data->win_ptr);
}

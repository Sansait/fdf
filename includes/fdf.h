/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:32:19 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/01 09:45:35 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# define HEIGHT 1080
# define WIDTH 1920

struct	s_coords
{
	int x;
	int y;
	int z;
};

typedef struct s_coords	t_coords;

struct	s_line
{
	t_coords *p0;
	t_coords *p1;
};

typedef struct s_line	t_line;

struct	s_incre
{
	int incx;
	int incy;
	int incre;
	int incrne;
	int e;
};

typedef struct s_incre	t_incre;

struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_coords	**tab;
	int			l;
	int			*ll;
	int			zoom;
	float		relief;
	int			sx;
	int			sy;
	int			color;
	int			*img;
	float		ax;
	float		ay;
	float		az;
	t_coords	mid;
	t_coords	midf;
	int			click_d;
	int			click_g;
	int			mouse_last_x;
	int			mouse_last_y;
};

typedef struct s_data	t_data;

void	setup(void *mlx_ptr, void *win_ptr);
int		reader(char *str, t_data *data);
void	lines(t_data *mlx_ptr, t_line *line, int color);
int		keep_param(int x, int y, t_data *mlx);
void	display(t_data *data);
void	centraldisp(t_data *data);
void	lines_img(t_data *data, t_line *line);
int		key_press(int key, t_data *data);
int		mouse_press(int b, int x, int y, void *param);
int		mouse_release(int b, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);

#endif

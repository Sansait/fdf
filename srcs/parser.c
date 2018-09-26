/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:41:46 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/26 12:54:00 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>

int		line_counter(char *str)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 0;
	fd = open(str, O_RDONLY);
	ft_putnbr(fd);
	while (get_next_line(fd, &line) > 0)
	{
		lines++;
		ft_strdel(&line);
	}
	close(fd);
	return (lines);
}


void	parse_line(t_coords *tab, char *greed, int y)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (greed[i] != '\0')
	{
		if (ft_is_space(greed[i]) == 0)
		{
			tab[x].z = ft_atoi(&greed[i]);
			tab[x].y = y;
			tab[x].x = x;
			x++;
			while (greed[i] != '\0' && !ft_is_space(greed[i]))
				i++;
		}
		else
			i++;
	}
}

void	free_grid(char **greed, t_data *data)
{
	int i;

	i = 0;
	while (i < data->l)
	{
		free(greed[i]);
		i++;
	}
	free(greed);
}

void	parser(char **greed, t_data *data)
{
	int y;

	if (!(data->tab = malloc(sizeof(t_coords*) * data->l)))
		return ;
	if (!(data->ll = malloc(sizeof(int) * data->l)))
		return ;
	y = 0;
	while (y < data->l)
	{
		data->ll[y] = ft_count_words(greed[y], ' ');
		if (!(data->tab[y] = malloc(sizeof(t_coords) * data->ll[y])))
			return ;
		parse_line(data->tab[y], greed[y], y);
		y++;
	}
	free_grid(greed, data);
}

int		reader(char *str, t_data *data)
{
	int		fd;
	int		line_count;
	char	*line;
	char	**greed;

	if ((line_count = line_counter(str)) == 0)
		return (0);
	if (!(greed = malloc(sizeof(char *) * line_count)))
		return (0);
	fd = open(str, O_RDONLY);
	data->l = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(greed[data->l] = ft_strnew(ft_strlen(line) + 1)))
			return (0);
		greed[data->l] = ft_strcpy(greed[data->l], line);
		free(line);
		data->l++;
	}
	greed[data->l] = NULL;
	parser(greed, data);
	return (1);
}

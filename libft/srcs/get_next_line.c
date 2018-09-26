/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:45:09 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/26 15:22:48 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*get_current_file(t_list **file, const int fd)
{
	t_list				*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew("\0", 2)))
		return (NULL);
	tmp->content_size = (size_t)fd;
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*current;
	char			buff[BUFF_SIZE + 1];
	int				bytes;
	int				i;

	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	current = get_current_file(&file, fd);
	while ((bytes = (int)read(fd, buff, BUFF_SIZE)))
	{
		buff[bytes] = '\0';
		if (!(current->content = ft_straddend(current->content, buff)))
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (bytes < BUFF_SIZE && !ft_strlen(current->content))
		return (0);
	i = ft_copyuntil(line, current->content, '\n');
	if (i < (int)ft_strlen(current->content))
		current->content = ft_strremb(current->content, '\n');
	else
		ft_strclr(current->content);
	return (1);
}

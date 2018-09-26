/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:24:08 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/26 15:22:48 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*new;

	if (!s)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		new[j] = s[i];
		j++;
		i++;
	}
	return (new);
}

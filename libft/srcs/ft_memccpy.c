/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:59:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/26 15:22:48 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char				*dst;
	const unsigned char	*srcs;
	size_t				i;

	dst = dest;
	srcs = src;
	i = 0;
	while (i < n)
	{
		dst[i] = srcs[i];
		if (srcs[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

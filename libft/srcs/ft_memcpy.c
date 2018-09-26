/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:48:23 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/26 15:22:48 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*srcs;
	size_t		i;

	dst = dest;
	srcs = src;
	i = 0;
	while (i < n)
	{
		dst[i] = srcs[i];
		i++;
	}
	return (dst);
}

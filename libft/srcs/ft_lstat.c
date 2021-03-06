/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:00:23 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/26 15:22:48 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (nbr > (unsigned int)ft_lstsize(begin_list))
		return (NULL);
	while (++i < nbr)
		begin_list = begin_list->next;
	return (begin_list);
}

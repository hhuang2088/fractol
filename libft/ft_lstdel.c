/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:28:31 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/05 00:36:42 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodedel(t_node **anode, void (*del)(void *, size_t))
{
	if (!anode || !del)
		return ;
	if ((*anode)->next != NULL)
		ft_nodedel(&(*anode)->next, del);
	del((*anode)->content, (*anode)->content_size);
	free(*anode);
	*anode = NULL;
}

void 	ft_lstdel(t_list *list, void (*del)(void *, size_t))
{
	if (!list || !del)
		return ;
	ft_nodedel(&list->head, del);
	free(list);
}

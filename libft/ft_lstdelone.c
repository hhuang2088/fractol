/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:09:24 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/04 23:25:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodedelone(t_node **anode, void (*del)(void *, size_t))
{
	if (!anode || !del)
		return ;
	del((*anode)->content, (*anode)->content_size);
	free(*anode);
	*anode = NULL;
}

void 	ft_lstdelone(t_list *list, void (*del)(void *, size_t))
{
	if (!list || !list->node || !del)
		return ;
	ft_nodedelone(&(list->node), del);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 23:45:09 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 11:27:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodeadd(t_node *node, t_node *new)
{
	if (!node || !new)
		return ;
	new->next = node;
	node = new;
}

void	ft_lstadd(t_list *list, t_node *new)
{
	if (!list || !new)
		return ;
	ft_nodeadd(list->head, new);
}

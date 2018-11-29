/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 00:28:17 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:21:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	ft_nodeiter(t_node *node, void (*f)(t_node *elem))
{
	if (!node || !f)
		return ;
	f(node);
	if (node->next != NULL)
		ft_nodeiter(node->next, f);
}

void	ft_lstiter(t_list *list, void (*f)(t_node *elem))
{
	if (!list || !f)
		return ;
	ft_nodeiter(list->head, f);
}

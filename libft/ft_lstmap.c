/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:06:43 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/20 00:06:41 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_nodemap(t_node *node, t_node *(*f)(t_node *elem))
{
	t_node	*ret;

	if (!node || !f)
		return (NULL);
	ret = f(node);
	if (node->next != NULL)
		ret->next = ft_nodemap(node->next, f);
	return (ret);
}

t_list	*ft_lstmap(t_list *list, t_node *(*f)(t_node *elem))
{
	t_list *ret;

	if (!list || !f)
		return (NULL);
	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ret->head = ft_nodemap(list->head, f);
	ret->node = ret->head;
	return (ret);
}

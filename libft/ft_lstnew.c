/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 23:10:16 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 11:29:17 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_nodenew(void const *content, size_t content_size)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = (void*)malloc(content_size);
	if (!content || !node->content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		ft_memmove(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	t_node	*node;

	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content)
	{
		if (!(node = ft_nodenew(content, content_size)))
		{
			list->head = NULL;
			list->node = NULL;
			return (list);
		}
		list->head = node;
		list->node = node;
	}
	else
	{
		list->head = NULL;
		list->node = NULL;
	}
	return (list);
}

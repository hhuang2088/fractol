/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:08:45 by hehuang           #+#    #+#             */
/*   Updated: 2016/11/02 16:51:48 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item, size_t item_size)
{
	t_btree		*tmp;

	if ((tmp = (t_btree*)malloc(sizeof(t_btree))))
	{
		if (!item)
		{
			tmp->item = NULL;
			tmp->left = NULL;
			tmp->right = NULL;
			tmp->item_size = 0;
		}
		else
		{
			tmp->item = item;
			tmp->left = NULL;
			tmp->right = NULL;
			tmp->item_size = item_size;
		}
	}
	return (tmp);
}

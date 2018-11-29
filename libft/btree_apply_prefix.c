/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:21:26 by hehuang           #+#    #+#             */
/*   Updated: 2016/11/02 16:53:15 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_prefix(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		f(root->item);
		btree_apply_prefix(root->left, f);
		btree_apply_prefix(root->right, f);
	}
}

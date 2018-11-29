/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:31:14 by hehuang           #+#    #+#             */
/*   Updated: 2016/11/02 16:54:56 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_suffix(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		btree_apply_suffix(root->left, f);
		btree_apply_suffix(root->right, f);
		f(root->item);
	}
}

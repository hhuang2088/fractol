/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:21:26 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/24 10:54:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		btree_apply_infix(root->left, f);
		f(root->item);
		btree_apply_infix(root->right, f);
	}
}

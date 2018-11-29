/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:46:16 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:47:36 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_oct_base_helper(t_tag *tag)
{
	char *tmp;

	if (tag->prec)
	{
		tmp = ft_strjoin(tag->prec, tag->base);
		free(tag->base);
		tag->base = ft_strdup(tmp);
		free(tmp);
	}
	if (tag->dot && ft_strcmp(tag->base, "0") == 0 && !tag->prec)
	{
		free(tag->base);
		tag->base = ft_strdup("");
	}
}

static char	*set_oct_head(t_tag *tag)
{
	if ((tag->header || tag->hash) && (int)tag->arg)
		return (ft_strdup("0"));
	return (NULL);
}

int			handle_oct(t_tag *tag)
{
	char	*ret;
	char	*head;
	int		head_len;
	int		ret_len;

	head = set_oct_head(tag);
	head_len = 0;
	if (head)
		head_len = 1;
	tag = precision_utoa(tag, 8, 0);
	set_oct_base_helper(tag);
	tag->width = create_width(tag, ft_strlen(tag->base) + head_len);
	ret = oct_and_hex_helper(tag->base, tag->width, tag->l_just, head);
	if (!tag->base[0] && tag->hash)
	{
		cleanup(tag, ret, head);
		ft_putchar('0');
		return (1);
	}
	ft_putstr(ret);
	ret_len = ft_strlen(ret);
	cleanup(tag, ret, head);
	return (ret_len);
}

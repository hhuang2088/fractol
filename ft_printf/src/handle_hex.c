/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:36:37 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:37:21 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*set_hex_head(t_tag *tag)
{
	if ((tag->header || tag->hash) && ((int)tag->arg || tag->type == 'p'))
	{
		if (tag->cap)
			return (ft_strdup("0X"));
		return (ft_strdup("0x"));
	}
	return (NULL);
}

static char		*set_hex_base(t_tag *tag)
{
	if (tag->prec)
		return (ft_strjoin(tag->prec, tag->base));
	return (ft_strdup(tag->base));
}

int				handle_hex(t_tag *tag)
{
	char	*ret;
	char	*head;
	char	*base;
	int		len;

	head = set_hex_head(tag);
	len = 0;
	if (head)
		len = 2;
	tag = precision_utoa(tag, 16, tag->cap);
	base = set_hex_base(tag);
	if (tag->dot && ft_strcmp(base, "0") == 0 && !tag->prec)
	{
		free(base);
		base = ft_strdup("");
	}
	tag->width = create_width(tag, ft_strlen(base) + len);
	ret = oct_and_hex_helper(base, tag->width, tag->l_just, head);
	ft_putstr(ret);
	len = ft_strlen(ret);
	cleanup(tag, ret, base);
	free(head);
	return (len);
}

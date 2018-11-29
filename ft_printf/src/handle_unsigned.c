/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:35:46 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:36:07 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_base(t_tag *tag)
{
	if (tag->prec)
		return (ft_strjoin(tag->prec, tag->base));
	else
		return (ft_strdup(tag->base));
}

static char	*set_ret(t_tag *tag, char *base)
{
	if (tag->width)
	{
		if (tag->l_just)
			return (ft_strjoin(base, tag->width));
		else
			return (ft_strjoin(tag->width, base));
	}
	else
		return (ft_strdup(base));
}

int			handle_unsigned(t_tag *tag)
{
	char	*ret;
	int		len;
	char	*base;

	tag = precision_utoa(tag, 10, 0);
	base = set_base(tag);
	if (tag->dot && ft_strcmp(tag->base, "0") == 0 && !tag->prec)
	{
		free(base);
		base = ft_strdup("");
	}
	tag->width = create_width(tag, ft_strlen(base));
	ret = set_ret(tag, base);
	len = ft_strlen(ret);
	ft_putstr(ret);
	cleanup(tag, ret, base);
	return (len);
}

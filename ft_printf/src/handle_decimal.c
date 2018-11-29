/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:55:45 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:56:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_neg(t_tag *tag)
{
	if (tag->length == 'l')
	{
		if ((long)tag->arg < 0)
			return (1);
	}
	if (tag->length == 'v')
	{
		if ((long long)tag->arg < 0)
			return (1);
	}
	if (tag->length == 'h')
	{
		if ((short)tag->arg < 0)
			return (1);
	}
	if (tag->length == '0')
	{
		if ((int)tag->arg < 0)
			return (1);
	}
	return (0);
}

static char		*set_ret(t_tag *tag, char *base)
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

static int		print_sign(t_tag *tag, char *ret)
{
	if (tag->sign && !tag->neg && !tag->precision && !tag->width)
	{
		ft_putchar('+');
		return (1);
	}
	else if (tag->space && !tag->neg && !tag->width)
	{
		ft_putchar(' ');
		return (1);
	}
	else if (tag->neg && !tag->width && !tag->prec && ret[0] != '-')
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

int				handle_decimal(t_tag *tag)
{
	char	*ret;
	int		len;
	char	*base;

	tag->neg = is_neg(tag);
	tag = precision_itoa(tag, 10, 0);
	if (tag->dot && ft_strcmp(tag->base, "0") == 0 && !tag->prec)
	{
		free(tag->base);
		tag->base = ft_strdup("");
	}
	if (tag->prec)
		base = ft_strjoin(tag->prec, tag->base);
	else
		base = ft_strdup(tag->base);
	tag->width = create_width(tag, ft_strlen(base));
	ret = set_ret(tag, base);
	len = ft_strlen(ret);
	len += print_sign(tag, ret);
	ft_putstr(ret);
	cleanup(tag, ret, base);
	return (len);
}

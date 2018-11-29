/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars_and_strings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:40:07 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:45:16 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_char(t_tag *tag)
{
	int		len;

	len = 0;
	tag->width = NULL;
	if (tag->min_width > 0)
		tag->width = create_width(tag, 1);
	if (tag->width)
	{
		if (tag->l_just)
		{
			ft_putchar((char)tag->arg);
			ft_putstr(tag->width);
		}
		else
		{
			ft_putstr(tag->width);
			ft_putchar((char)tag->arg);
		}
		len = ft_strlen(tag->width);
		free(tag->width);
		return (1 + len);
	}
	ft_putchar((char)tag->arg);
	return (1);
}

int				handle_string_helper(t_tag *tag, int raw_len, int mal)
{
	int		width_len;

	if (tag->l_just)
	{
		ft_putstr(tag->base);
		ft_putstr(tag->width);
	}
	else
	{
		ft_putstr(tag->width);
		ft_putstr(tag->base);
	}
	if (mal)
		free(tag->base);
	width_len = ft_strlen(tag->width);
	free(tag->width);
	return (raw_len + width_len);
}

int				handle_string(t_tag *tag)
{
	int		raw_len;
	int		mal;

	mal = 0;
	if (tag->dot)
	{
		tag->base = ft_strnew((size_t)tag->precision);
		if (tag->precision)
			ft_strncpy(tag->base, (char*)tag->arg, (size_t)tag->precision);
		mal = 1;
	}
	else
		tag->base = (char*)tag->arg;
	if (!tag->base && !tag->dot)
		tag->base = "(null)";
	raw_len = ft_strlen(tag->base);
	tag->width = create_width(tag, raw_len);
	if (tag->width)
		return (handle_string_helper(tag, raw_len, mal));
	ft_putstr(tag->base);
	if (mal)
		free(tag->base);
	return (raw_len);
}

int				handle_percent(t_tag *tag)
{
	int		len;

	len = 0;
	tag->width = NULL;
	if (tag->min_width > 0)
		tag->width = create_width(tag, 1);
	if (tag->width)
	{
		if (tag->l_just)
		{
			ft_putchar('%');
			ft_putstr(tag->width);
		}
		else
		{
			ft_putstr(tag->width);
			ft_putchar('%');
		}
		len = ft_strlen(tag->width);
		free(tag->width);
		return (1 + len);
	}
	ft_putchar('%');
	return (1);
}

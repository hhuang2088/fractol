/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar_and_wstr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:24:52 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 16:25:25 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				handle_wchar(t_tag *tag)
{
	int		ret;

	tag->width = NULL;
	if (tag->min_width > 0)
		tag->width = create_width(tag, 1);
	if (tag->width)
	{
		if (tag->l_just)
		{
			ret = ft_putwi((wint_t)tag->arg);
			ft_putstr(tag->width);
		}
		else
		{
			ft_putstr(tag->width);
			ret = ft_putwi((wint_t)tag->arg);
		}
		ret += ft_strlen(tag->width);
		free(tag->width);
		return (ret);
	}
	ret = ft_putwi((wint_t)tag->arg);
	free(tag->width);
	return (ret);
}

static int		handle_ws_helper(t_tag *tag, int raw_len, wchar_t *ws)
{
	int		width_len;

	if (tag->l_just)
	{
		raw_len = ft_putws(ws);
		ft_putstr(tag->width);
	}
	else
	{
		ft_putstr(tag->width);
		raw_len = ft_putws(ws);
	}
	width_len = ft_strlen(tag->width);
	free(tag->width);
	return (raw_len + width_len);
}

int				handle_ws(t_tag *tag)
{
	size_t	len;
	wchar_t	*ws;
	int		mal;

	mal = 0;
	if (tag->dot)
	{
		ws = ft_wstrnew((size_t)tag->precision);
		if (tag->precision)
			ft_wstrncpy(ws, (wchar_t*)tag->arg, (size_t)tag->precision);
		mal = 1;
	}
	else
		ws = (wchar_t*)tag->arg;
	len = ft_wstrlen(ws);
	tag->width = create_width(tag, len);
	if (!ws)
		ws = L"(null)";
	if (tag->width)
		return (handle_ws_helper(tag, len, ws));
	len = ft_putws(ws);
	if (mal)
		free(ws);
	return (len);
}

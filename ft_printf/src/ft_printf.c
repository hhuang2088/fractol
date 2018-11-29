/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:32:09 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 14:53:01 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_handle(const char *fmt)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			if (!is_percent(fmt, i))
				cnt++;
			if (fmt[i + 1])
				i++;
		}
		i++;
	}
	return (cnt);
}

static int		go_to_point_after_flag(const char *format, int i)
{
	if (format[i] && format[i] == '%')
		i++;
	while (format[i])
	{
		if (is_type(format[i]))
		{
			i++;
			return (i);
		}
		else if (!is_length(format[i]) && !is_flag(format[i]) &&
		!ft_isdigit(format[i]) && ft_isascii(format[i]) && format[i] != '.')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

static int		print_format_with_arguments(const char *format,
		int len, int cnt)
{
	char	*ret;
	int		i;

	i = 0;
	if (format[i] == '%')
	{
		len += process_tag(format);
		i = go_to_point_after_flag(format, i);
		cnt--;
	}
	while (format[i] && format[i] != '%')
	{
		ft_putchar(format[i++]);
		len++;
	}
	if (format[i] && format[i] == '%')
	{
		ret = ft_strdup(format + i);
		len = print_format_with_arguments(ret, len, cnt);
		free(ret);
	}
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int				cnt;
	int				len;

	va_start(g_lst, format);
	cnt = count_handle(format);
	len = print_format_with_arguments(format, 0, cnt);
	va_end(g_lst);
	return (len);
}

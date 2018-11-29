/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:11:52 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:19:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_flag(char flag)
{
	char		*flags;
	size_t		i;

	i = 0;
	flags = "-0+# \0";
	while (i < ft_strlen(flags))
	{
		if (flags[i++] == flag)
			return (flags[i]);
	}
	return (0);
}

int				get_precision(const char *fmt)
{
	int		i;

	i = 0;
	if (fmt[i] == '%')
		i++;
	while (fmt[i] && fmt[i] != '.' && !is_type(fmt[i]))
		i++;
	if (fmt[i] == '.' && fmt[i + 1] >= '1' && fmt[i + 1] <= '9')
	{
		if (fmt[i + 1] >= '1' && fmt[i + 1] <= '9')
			return (ft_atoi(fmt + i + 1));
		else if (fmt[i + 1] == '*')
			return (va_arg(g_lst, int));
	}
	return (0);
}

char			get_type(const char *fmt)
{
	char	type;
	int		i;
	int		len;

	len = ft_strlen(fmt);
	i = 0;
	type = '\0';
	if (fmt[i] == '%')
		i++;
	while (i < len && (is_length(fmt[i]) || !ft_isalpha(fmt[i])) && \
		!is_type(fmt[i]))
		i++;
	if (fmt[i] && is_type(fmt[i]))
		type = fmt[i];
	return (type);
}

int				get_width(const char *fmt)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (fmt[i] && !is_type(fmt[i]) && fmt[i] != '.' && !(fmt[i] >= '1' \
				&& fmt[i] <= '9') && fmt[i] != '*')
		i++;
	if (fmt[i] >= '1' && fmt[i] <= '9')
		ret += ft_atoi(fmt + i);
	else if (fmt[i] == '*')
		ret = va_arg(g_lst, int);
	return (ret);
}

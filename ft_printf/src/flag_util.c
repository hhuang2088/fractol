/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:30:51 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:34:39 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(const char flag)
{
	int		i;
	char	*flags;

	i = 0;
	flags = "-0+# ";
	while (flags[i])
	{
		if (flag == flags[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_length(const char length)
{
	char	*mods;
	int		i;

	mods = "hljz\0";
	i = 0;
	while (mods[i])
	{
		if (length == mods[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_percent(const char *fmt, int i)
{
	if (fmt[i] == '%')
		i++;
	while (fmt[i] && (!ft_isalpha(fmt[i]) || !is_type(fmt[i]) ||
				is_flag(fmt[i]) || ft_isdigit(fmt[i]) || is_length(fmt[i])))
		i++;
	if (fmt[i] == '%')
		return (1);
	return (0);
}

int		is_type(const char c)
{
	int		i;
	char	*types;

	types = "%sSpdDioOuUxXcC\0";
	i = 0;
	while (types[i])
	{
		if (c == types[i])
			return (1);
		i++;
	}
	return (0);
}

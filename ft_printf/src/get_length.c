/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:01:27 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:05:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		compare_length(char new, char old)
{
	if (old == '0')
		return (1);
	else if (old == 'H')
	{
		if (new == 'j' || new == 'h' || new == 'l' || new == 'z'
				|| new == 'v' || new == 'j')
			return (1);
	}
	else if (old == 'h')
	{
		if (new == 'j' || new == 'l' || new == 'z' || new == 'v')
			return (1);
	}
	else if (old == 'j')
	{
		if (new == 'l' || new == 'z' || new == 'v')
			return (1);
	}
	else if (old == 'l' || old == 'z')
	{
		if (new == 'v')
			return (1);
	}
	return (0);
}

static char		get_length_helper(const char *fmt, char length, int i)
{
	if (fmt[i] == 'l')
	{
		if (fmt[i + 1] && fmt[i + 1] == 'l')
			length = (compare_length('v', length)) ? 'v' : length;
		else
			length = (compare_length('l', length)) ? 'l' : length;
	}
	else if (fmt[i] == 'h')
	{
		if (fmt[i + 1] && fmt[i + 1] == 'h')
			length = (compare_length('H', length)) ? 'H' : length;
		else
			length = (compare_length('h', length)) ? 'h' : length;
	}
	else
		length = (compare_length(fmt[i], length)) ? fmt[i] : length;
	return (length);
}

char			get_length(const char *fmt)
{
	int		i;
	int		len;
	char	length;

	i = 1;
	length = '0';
	len = ft_strlen(fmt);
	while (i < len && fmt[i] && !is_type(fmt[i]))
	{
		if (is_length(fmt[i]))
			length = get_length_helper(fmt, length, i);
		if (length == 'v' || length == 'H')
			i += 2;
		else
			i++;
	}
	return (length);
}

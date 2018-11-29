/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:53:33 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 16:03:26 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag_check(const char fmt_i, char *flags, int dot, int twice)
{
	if (fmt_i == '-' && flags[0] == '@')
		flags[0] = '-';
	if (fmt_i == '0' && flags[1] == '@' && !twice && !dot)
		flags[1] = '0';
	if (fmt_i == '+' && flags[2] == '@')
		flags[2] = '+';
	if (fmt_i == '#' && flags[3] == '@')
		flags[3] = '#';
	if (fmt_i == ' ' && flags[4] == '@')
		flags[4] = ' ';
}

static char		*scan_flag(const char *fmt, char *flags, int i)
{
	int		twice;
	int		dot;
	int		len;

	twice = 0;
	dot = 0;
	len = ft_strlen(fmt);
	while (i < len && fmt[i] && !is_type(fmt[i]))
	{
		if (fmt[i] >= '1' && fmt[i] <= '9')
		{
			while (ft_isdigit(fmt[i]))
				i++;
			continue;
		}
		if (fmt[i] == '.' && !dot)
			dot = 1;
		if (fmt[i] == '#' && flags[3] == '#')
			twice = 1;
		flag_check(fmt[i], flags, dot, twice);
		i++;
	}
	return (flags);
}

static char		*prepare_flag(const char *fmt)
{
	int		i;
	char	*flags;

	i = 0;
	flags = (char*)malloc(sizeof(char) * 6);
	while (i < 5)
		flags[i++] = '@';
	flags[i] = '\0';
	i = 1;
	return (scan_flag(fmt, flags, i));
}

static t_tag	*flag_helper(t_tag *tag, char *flags)
{
	if (flags[0] == '-')
		tag->l_just = 1;
	if (flags[1] == '0' &&\
			!tag->l_just && !tag->precision)
		tag->pad = '0';
	if (flags[2] == '+')
		tag->sign = 1;
	if (flags[3] == '#')
		tag->hash = 1;
	if (flags[4] == ' ')
		tag->space = 1;
	if (tag->type == 'D' || tag->type == 'O' || tag->type == 'U' ||
		tag->type == 'p')
		tag->length = 'l';
	if (tag->type == 'p')
		tag->header = 1;
	if (tag->length == 'l' && tag->type == 'c')
		tag->type = 'C';
	if (tag->length == 'l' && tag->type == 's')
		tag->type = 'S';
	return (tag);
}

int				process_tag(const char *fmt)
{
	t_tag	*tag;
	char	*flags;
	int		len;

	tag = init_tag(fmt);
	if (!tag->type)
		tag = handle_invalid(tag, fmt);
	if (!tag->type)
	{
		free(tag);
		return (0);
	}
	flags = prepare_flag(fmt);
	tag = flag_helper(tag, flags);
	tag = cast_int_with_length(tag);
	len = handle_tag(tag);
	free(tag);
	free(flags);
	return (len);
}

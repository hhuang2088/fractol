/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_utoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:27:54 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:19:41 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*zero_pad(int len)
{
	char	*prec;
	int		i;

	i = 0;
	if (len <= 0)
		prec = NULL;
	else
	{
		prec = ft_strnew(len);
		while (i < len)
			prec[i++] = '0';
	}
	return (prec);
}

static char		*get_unsigned(const t_tag *tag, int base, int cap)
{
	if (tag->length == 'l' || tag->type == 'U')
		return (ft_utoa_base(tag->arg_ulong, base, cap));
	else if (tag->length == 'v')
		return (ft_utoa_base(tag->arg_ull, base, cap));
	else if (tag->length == 'h')
		return (ft_utoa_base(tag->arg_ushort, base, cap));
	else if (tag->length == 'z')
		return (ft_utoa_base(tag->arg_sizet, base, cap));
	else if (tag->length == 'H')
		return (ft_utoa_base(tag->arg_uchar, base, cap));
	else if (tag->length == 'j')
		return (ft_utoa_base(tag->arg_uintmaxt, base, cap));
	return (ft_utoa_base((unsigned int)tag->arg, base, cap));
}

t_tag			*precision_utoa(t_tag *tag, int base, int cap)
{
	int						len;

	tag->base = get_unsigned(tag, base, cap);
	len = tag->precision - ft_strlen(tag->base);
	if (tag->type == 'o' && (tag->hash || tag->header))
		len--;
	tag->prec = zero_pad(len);
	return (tag);
}

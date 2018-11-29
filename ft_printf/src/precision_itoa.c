/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 08:52:37 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 14:59:40 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_negative(char *ret, int precision, int width, int l_just)
{
	int		len;

	len = precision - ft_strlen(ret);
	if (ret[0] == '-' && (len > 0 || width) && !l_just)
		return (ft_strdup(ret + 1));
	return (ft_strdup(ret));
}

static char	*get_dec(const t_tag *tag, int base, int cap)
{
	if (tag->length == 'l' || tag->type == 'D')
		return (ft_itoa_base(tag->arg_long, base, cap));
	else if (tag->length == 'v')
		return (ft_itoa_base(tag->arg_ll, base, cap));
	else if (tag->length == 'h')
		return (ft_itoa_base(tag->arg_short, base, cap));
	else if (tag->length == 'z')
		return (ft_itoa_base(tag->arg_sizet, base, cap));
	else if (tag->length == 'H')
		return (ft_itoa_base(tag->arg_char, base, cap));
	else if (tag->length == 'j')
		return (ft_itoa_base(tag->arg_intmaxt, base, cap));
	return (ft_itoa_base((int)tag->arg, base, cap));
}

static char	*zero_pad(int len, int neg, int sign, int l_just)
{
	char	*prec;
	int		i;
	int		space;

	space = 0;
	if (neg || sign)
		space = 1;
	i = 0;
	if (len <= 0)
		prec = NULL;
	else
	{
		prec = ft_strnew(len + space);
		if (neg)
			prec[i++] = '-';
		else if (sign && !neg)
			prec[i++] = '+';
		while (i < (len + space))
			prec[i++] = '0';
	}
	if (l_just && space && sign && len < 0 && !prec && !neg)
		return (ft_strdup("+"));
	return (prec);
}

t_tag		*precision_itoa(t_tag *tag, int base, int cap)
{
	int				len;
	char			*tmp;

	tmp = get_dec(tag, base, cap);
	tag->base = handle_negative(tmp, tag->precision, tag->min_width,
			tag->l_just);
	len = tag->precision - ft_strlen(tag->base);
	tag->prec = zero_pad(len, tag->neg, tag->sign, tag->l_just);
	free(tmp);
	return (tag);
}

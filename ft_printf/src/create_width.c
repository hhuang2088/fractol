/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:51:28 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:58:29 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*init_str(int size)
{
	if (size > 0)
		return (ft_strnew(size));
	return (NULL);
}

static int	set_sign_char_one(t_tag *tag, char *ret, int i)
{
	if (tag->pad == '0' && !tag->precision)
	{
		if (tag->neg)
			ret[i++] = '-';
		else if (!tag->neg && tag->sign && tag->type != 'u')
			ret[i++] = '+';
	}
	return (i);
}

static void	set_sign_char_two(t_tag *tag, char *ret, int i)
{
	if (tag->pad != '0')
	{
		if (tag->neg)
			ret[i] = '-';
		else if (!tag->neg && tag->sign)
			ret[i] = '+';
	}
	else
		ret[i] = tag->pad;
}

char		*create_width(t_tag *tag, int init_len)
{
	char	*ret;
	int		size;
	int		i;
	int		num;
	int		sign;

	i = 0;
	sign = (tag->neg || tag->sign) ? 1 : 0;
	size = tag->min_width - init_len;
	ret = init_str(size);
	num = (tag->type == 'd' || tag->type == 'D' || tag->type == 'i' \
			|| tag->type == 'u' || tag->type == 'U') ? 1 : 0;
	if (ret && num && !tag->l_just)
		i = set_sign_char_one(tag, ret, i);
	if (ret && i < size - 1 && !tag->sign && !tag->neg && tag->space)
		ret[i++] = ' ';
	while (ret && i < size - 1)
		ret[i++] = tag->pad;
	if (ret && num && !tag->l_just && sign &&
			(tag->precision - (int)ft_strlen(tag->base) <= 0)
			&& i < size && tag->type != 'u')
		set_sign_char_two(tag, ret, i);
	else if (ret && i < size)
		ret[i] = tag->pad;
	return (ret);
}

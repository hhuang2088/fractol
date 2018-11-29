/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:48:30 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:39:43 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_dot(const char *fmt)
{
	int		i;

	i = 0;
	if (fmt[i] == '%')
		i++;
	while (fmt[i] && fmt[i] != '.' && !is_type(fmt[i]))
		i++;
	if (fmt[i] == '.')
		return (1);
	return (0);
}

t_tag		*init_tag(const char *fmt)
{
	t_tag	*ret;
	int		i;

	if (!(ret = (t_tag*)malloc(sizeof(t_tag))))
		return (NULL);
	i = 0;
	ret->type = get_type(fmt);
	if (ret->type && ret->type != '%')
		ret->arg = va_arg(g_lst, void*);
	ret->min_width = get_width(fmt);
	ret->precision = get_precision(fmt);
	ret->length = get_length(fmt);
	ret->dot = find_dot(fmt);
	ret->space = 0;
	ret->cap = 0;
	ret->hash = 0;
	ret->header = 0;
	ret->l_just = 0;
	ret->pad = ' ';
	ret->sign = 0;
	ret->neg = 0;
	return (ret);
}

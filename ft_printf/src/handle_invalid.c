/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_invalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:27:51 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:28:15 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tag	*handle_invalid(t_tag *tag, const char *fmt)
{
	int		i;

	i = 0;
	if (fmt[i] == '%')
		i++;
	while (fmt[i] && (ft_isdigit(fmt[i]) || fmt[i] == '-' || is_flag(fmt[i]) ||
	fmt[i] == '.' || is_length(fmt[i])))
		i++;
	if (fmt[i] && !is_type(fmt[i]))
	{
		tag->type = 'c';
		tag->arg = (void*)(size_t)fmt[i];
	}
	return (tag);
}

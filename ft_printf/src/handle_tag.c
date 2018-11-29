/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:53:27 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:38:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_tag(t_tag *tag)
{
	if (tag->type == 's')
		return (handle_string(tag));
	if (tag->type == 'C')
		return (handle_wchar(tag));
	if (tag->type == 'S')
		return (handle_ws(tag));
	else if (tag->type == 'i' || tag->type == 'd' || tag->type == 'D')
		return (handle_decimal(tag));
	else if (tag->type == 'o' || tag->type == 'O')
		return (handle_oct(tag));
	else if (tag->type == 'x' || tag->type == 'X' || tag->type == 'p')
	{
		if (tag->type == 'X')
			tag->cap = 1;
		return (handle_hex(tag));
	}
	else if (tag->type == 'c')
		return (handle_char(tag));
	else if (tag->type == '%')
		return (handle_percent(tag));
	else if (tag->type == 'u' || tag->type == 'U')
		return (handle_unsigned(tag));
	return (0);
}

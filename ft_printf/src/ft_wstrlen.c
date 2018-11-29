/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:00:04 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:00:24 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_wstrlen(wchar_t *ws)
{
	size_t	len;
	size_t	limit;
	size_t	i;

	len = 0;
	i = 0;
	limit = 0;
	if (ws)
	{
		limit = ft_wcslen(ws);
		while (ws[i] && i < limit)
		{
			len += ft_wcharlen(ws[i]);
			i++;
		}
		return (len);
	}
	return (0);
}

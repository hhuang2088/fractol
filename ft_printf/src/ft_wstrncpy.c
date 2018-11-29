/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:22:33 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:39:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	size_t		lensrc;
	size_t		limit;
	size_t		i;

	lensrc = ft_wcslen((wchar_t*)src);
	limit = 0;
	i = 0;
	while (i < lensrc)
	{
		if (limit + ft_wcharlen(src[i]) <= len)
		{
			limit += ft_wcharlen(src[i]);
			dst[i] = src[i];
		}
		else
		{
			dst[i] = '\0';
			return (dst);
		}
		i++;
	}
	return (dst);
}

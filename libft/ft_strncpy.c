/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:22:33 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:39:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		lensrc;

	lensrc = ft_strlen(src);
	while (len-- > 0)
	{
		if (len < lensrc)
			dst[len] = src[len];
		else
			dst[len] = '\0';
	}
	return (dst);
}

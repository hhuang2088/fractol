/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 12:03:56 by hehuang           #+#    #+#             */
/*   Updated: 2017/01/01 23:58:14 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (len > 0)
	{
		len--;
		ptr1[len] = ptr2[len];
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	else
		return (ft_memrcpy(dst, src, len));
}

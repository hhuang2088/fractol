/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 12:44:26 by hehuang           #+#    #+#             */
/*   Updated: 2016/09/28 13:30:22 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	cmp;
	unsigned char	*ptr;

	i = 0;
	cmp = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (i < (int)n)
	{
		if (ptr[i] == cmp)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

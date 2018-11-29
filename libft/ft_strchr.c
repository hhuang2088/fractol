/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:23:16 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/01 00:56:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;
	char	c2;

	s_len = ft_strlen(s) + 1;
	c2 = (char)c;
	i = 0;
	while (i < s_len)
	{
		if (s[i] == c2)
			return ((char*)(s + i));
		i++;
	}
	return (NULL);
}

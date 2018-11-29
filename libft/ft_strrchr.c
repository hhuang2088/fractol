/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:51:07 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:40:17 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	k;
	int		found;
	size_t	s_len;
	char	c2;

	i = 0;
	k = 0;
	found = 0;
	s_len = ft_strlen(s) + 1;
	c2 = (char)c;
	while (i < s_len)
	{
		if (s[i] == c2)
		{
			found = 1;
			k = i;
		}
		i++;
	}
	if (found)
		return ((char*)(s + k));
	return (NULL);
}

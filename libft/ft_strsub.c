/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:33:57 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 11:35:09 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (!s || !ret)
		return (NULL);
	i = 0;
	if (!ret)
		return (NULL);
	while (i < len)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

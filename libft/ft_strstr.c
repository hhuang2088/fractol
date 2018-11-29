/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:11:52 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:44:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_match(const char *big, const char *little, int l)
{
	int		k;
	int		match;

	k = 0;
	match = 1;
	while (little[k] != '\0')
	{
		if (big[l] != little[k])
		{
			match = 0;
			break ;
		}
		k++;
		l++;
	}
	return (match);
}

char		*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	l;
	int		match;
	size_t	len_big;

	i = 0;
	l = 0;
	match = 0;
	len_big = ft_strlen(big) + 1;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (i < len_big)
	{
		if (big[i] == little[0])
		{
			l = i;
			match = get_match(big, little, l);
		}
		if (match)
			return ((char*)(big + l));
		i++;
	}
	return (NULL);
}

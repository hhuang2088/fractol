/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 06:51:57 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:39:46 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_match(const char *big, const char *little, size_t j, size_t len)
{
	int		match;
	size_t	k;

	k = 0;
	match = 1;
	while (little[k] != '\0')
	{
		if (big[j] != little[k] || j >= len)
		{
			match = 0;
			break ;
		}
		k++;
		j++;
	}
	return (match);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	int		match;

	i = 0;
	j = 0;
	match = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (i < len && big[i] != '\0')
	{
		if (!little)
			return ((char *)big);
		if (big[i] == little[0])
		{
			j = i;
			match = get_match(big, little, j, len);
		}
		if (match)
			break ;
		i++;
	}
	if (match)
		return ((char*)(big + j));
	return (NULL);
}

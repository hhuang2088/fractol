/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 23:11:12 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:38:36 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*copy;

	copy = (char*)s2;
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (j < n && copy[j] != '\0')
	{
		s1[i] = copy[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:07:44 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 11:38:02 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupper(char *str, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!str)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		ret[i] = ft_toupper(str[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

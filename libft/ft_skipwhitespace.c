/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipwhitespace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 23:09:04 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 10:28:06 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_skipwhitespace(char *str, int i)
{
	if (!str)
		return (i);
	while (str[i] && str[i] != '\0' && ft_iswhitespace(str[i]))
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 23:36:58 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 23:54:37 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skipwhitespace(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		negative;
	long	num;
	char	digit;

	num = 0;
	negative = 0;
	i = skipwhitespace(str);
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] != '\0') && (str[i] >= '0') && str[i] <= '9')
	{
		digit = (char)str[i];
		num *= 10;
		num += (long)(digit - '0');
		i++;
	}
	if (negative)
		num = -num;
	return ((int)num);
}

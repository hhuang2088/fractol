/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:37:52 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/25 05:15:37 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_digit(unsigned long long nbr, unsigned long long base)
{
	int		digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		digit++;
	}
	return (digit);
}

static char		get_num(unsigned long long mod, int cap)
{
	char		*values;
	char		*values2;

	values = "0123456789ABCDEF\0";
	values2 = "0123456789abcdef\0";
	if (cap)
		return (values[mod]);
	return (values2[mod]);
}

char			*ft_utoa_base(unsigned long long nbr, \
		unsigned long long base, int cap)
{
	int			digits;
	char		*ret;

	digits = get_digit(nbr, base);
	ret = (char*)malloc(sizeof(char) * (digits + 1));
	ret[digits--] = '\0';
	while (digits >= 0)
	{
		ret[digits--] = get_num(nbr % base, cap);
		nbr /= base;
	}
	return (ret);
}

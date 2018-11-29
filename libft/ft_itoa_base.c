/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:23:02 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/24 13:46:49 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_digit(long long nbr, long long base)
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

static char		get_num(long long mod, long long cap)
{
	long long	mod1;
	char		*values;
	char		*values2;

	mod1 = mod;
	if (mod < 0)
		mod1 = -mod;
	values = "0123456789ABCDEF\0";
	values2 = "0123456789abcdef\0";
	if (cap)
		return (values[mod1]);
	return (values2[mod1]);
}

char			*ft_itoa_base(long long nbr, long long base, long long cap)
{
	int			digits;
	int			neg;
	char		*ret;

	neg = 0;
	if (nbr < 0 && base == 10)
		neg = 1;
	digits = get_digit(nbr, base) + neg;
	ret = (char*)malloc(sizeof(char) * (digits + 1));
	ret[digits--] = '\0';
	while (digits >= neg)
	{
		ret[digits--] = get_num(nbr % base, cap);
		nbr /= base;
	}
	if (neg)
		ret[digits] = '-';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:54:45 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/07 22:10:56 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	get_digits(int n)
{
	long	dup;
	int		digits;

	dup = (long)n;
	if (n < 0)
	{
		dup = -dup;
	}
	digits = 0;
	if (n == 0)
		return (1);
	while (dup > 0)
	{
		digits += 1;
		dup /= 10;
	}
	return (digits);
}

char		*ft_itoa(int n)
{
	long	num;
	char	*ret;
	int		digits;
	int		negative;

	num = (long)n;
	negative = is_negative(n);
	if (is_negative(n))
		num = -num;
	digits = get_digits(n) + negative;
	ret = (char*)malloc(sizeof(char) * (digits + 1));
	if (ret == NULL)
		return (NULL);
	ret[digits--] = '\0';
	while (digits >= negative)
	{
		ret[digits] = '0' + (num % 10);
		num /= 10;
		digits--;
	}
	if (negative == 1)
		ret[digits] = '-';
	return (ret);
}

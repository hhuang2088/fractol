/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:29:42 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:29:57 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_two(wchar_t wi)
{
	ft_putchar(192 | (wi >> 6 & 63));
	ft_putchar(128 | (wi & 63));
	return (2);
}

static int	put_three(wchar_t wi)
{
	ft_putchar(224 | (wi >> 12 & 63));
	ft_putchar(128 | (wi >> 6 & 63));
	ft_putchar(128 | (wi & 63));
	return (3);
}

static int	put_four(wchar_t wi)
{
	ft_putchar(240 | ((wi >> 18) & 63));
	ft_putchar(128 | ((wi >> 12) & 63));
	ft_putchar(128 | ((wi >> 6) & 63));
	ft_putchar(128 | (wi & 63));
	return (4);
}

int			ft_putwi(wchar_t wi)
{
	if (wi <= 127)
	{
		ft_putchar(wi);
		return (1);
	}
	else if (wi <= 2047)
		return (put_two(wi));
	else if (wi <= 65535)
		return (put_three(wi));
	else
		return (put_four(wi));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:06:17 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:07:21 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putws(wchar_t *s)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (!s)
		return (ft_strlen(NULL));
	while (i < ft_wcslen(s))
		len += ft_putwi(s[i++]);
	return (len);
}

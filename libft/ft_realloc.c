/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:56:59 by hehuang           #+#    #+#             */
/*   Updated: 2017/01/09 23:04:23 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr && !size)
	{
		new_ptr = (char *)malloc(1);
		ft_memdel(&ptr);
		return (new_ptr);
	}
	new_ptr = (char *)malloc(size);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (new_ptr);
}

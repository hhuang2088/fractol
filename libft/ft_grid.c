/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 15:40:17 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 15:49:32 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_grid(int x, int y)
{
	int		i;
	char	**grid;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * y);
	if (!grid)
		return (NULL);
	while (i < x)
	{
		grid[i] = (char*)malloc(sizeof(char) * (x + 1));
		if (!grid[i++])
			return (NULL);
	}
	return (grid);
}

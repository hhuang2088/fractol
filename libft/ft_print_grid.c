/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:09:13 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/19 16:11:30 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_grid(char **grid)
{
	int		i;
	int		len_row;

	len_row = 0;
	i = 0;
	while (grid[i])
		len_row++;
	while (i < len_row)
		ft_putstr(grid[i++]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:48:06 by hehuang           #+#    #+#             */
/*   Updated: 2017/09/21 15:48:50 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cleanup(t_tag *tag, char *ret, char *base)
{
	free(tag->width);
	free(tag->base);
	free(tag->prec);
	free(ret);
	free(base);
}

char	*join_width_with_ret(char *ret, char *width, int l_just)
{
	if (l_just)
		return (ft_strjoin(ret, width));
	return (ft_strjoin(width, ret));
}

char	*get_base(char *head, char *base, char *width)
{
	if (head && width[0] == ' ')
		return (ft_strjoin(head, base));
	return (ft_strdup(base));
}

char	*get_base_with_no_width(char *head, char *base)
{
	if (head)
		return (ft_strjoin(head, base));
	return (ft_strdup(base));
}

char	*oct_and_hex_helper(char *base, char *width, int l_just, char *head)
{
	char	*ret;
	char	*tmp;

	if (width)
	{
		ret = get_base(head, base, width);
		tmp = ret;
		ret = join_width_with_ret(ret, width, l_just);
		free(tmp);
		if (head && width[0] == '0')
		{
			tmp = ret;
			ret = ft_strjoin(head, ret);
			free(tmp);
		}
	}
	else
		ret = get_base_with_no_width(head, base);
	return (ret);
}

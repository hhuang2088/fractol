/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:06:26 by hehuang           #+#    #+#             */
/*   Updated: 2017/01/23 15:52:11 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*read_from_file(int fd, char *str)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*copy;

	while (!(ft_strchr(str, '\n')))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)))
		{
			buff[ret] = '\0';
			copy = str;
			str = ft_strjoin(str, buff);
			free(copy);
		}
		else
			break ;
	}
	return (str);
}

static t_fdhandle		*init_fdhandle(t_fdhandle *head, const int fd)
{
	t_fdhandle		*handle;

	if (!(handle = (t_fdhandle*)malloc(sizeof(t_fdhandle))))
		return (NULL);
	handle->body = ft_strnew(0);
	if (head)
		handle->head = head;
	else
		handle->head = handle;
	handle->fd = fd;
	handle->next = NULL;
	return (handle);
}

int						get_next_line(const int fd, char **line)
{
	static t_fdhandle		*handle;
	char					dummy[1];
	int						place;
	char					*copy;

	if (fd < 0 || read(fd, dummy, 0) < 0 || !line)
		return (-1);
	if (!handle)
		handle = init_fdhandle(NULL, fd);
	while (handle->fd != fd && handle->next != NULL)
		handle = handle->next;
	if (handle->fd != fd && (handle->next = init_fdhandle(handle->head, fd)))
		handle = handle->next;
	handle->body = read_from_file(fd, handle->body);
	place = 0;
	while (handle->body[place] && handle->body[place] != '\n')
		place++;
	*line = ft_strncpy(ft_strnew(place), handle->body, place);
	place = handle->body[place] == '\n' ? place + 1 : place;
	copy = handle->body;
	handle->body = ft_strdup(handle->body + place);
	free(copy);
	handle = handle->head;
	return (place ? 1 : 0);
}

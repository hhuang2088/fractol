#include "libft.h"

int				get_list_size(t_list *list)
{
	int		count;

	count = 0;
	while (list && list->node)
	{
		++count;
		list->node = list->node->next;
	}
	list->node = list->head;
	return (count);
}

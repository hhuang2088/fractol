#include "libft.h"

void 		free_list(t_list *list)
{
	if (list->head)
		free_node(list->head);
	free(list);
}

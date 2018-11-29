#include "libft.h"

void 		node_free(t_node *node)
{
	if (node->next)
		node_free(node->next);
	free(node->content);
	free(node);
}

void 						list_free(t_list *list)
{
	if (list->head)
		node_free(list->head);
	free(list);
}

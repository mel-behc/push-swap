#include "push_swap.h"

void print_list(t_node *ptr)
{
	while (ptr != NULL)
	{
		printf("%d\n", ptr->nbr);
		ptr = ptr->next;
	}
}
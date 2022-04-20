#include "push_swap.h"

static int  *copie_tab(t_node **head, int *count, int *i)
{
	t_data  var;

	// var.i = 0;
	var.tmp = *head;
	var.tab = (int *)malloc(sizeof(int) * (*count));
	if (!var.tab)
		return (0);
	while (var.tmp)
	{
		var.tab[*i] = var.tmp->nbr;
		var.tmp = var.tmp->next;
		*i += 1;
	}
	return (var.tab);
}

int sorted_stack(t_node **stack, int *count)
{
    t_data  var;
    int     j;

    var.i = 0;
    var.tab = copie_tab(stack, count, &var.i);
    j = 1;
    while (var.i < *count && j < *count)
    {
        if (var.tab[j] < var.tab[var.i])
        {
            free(var.tab);
            return (0);
        }
        var.i++;
        j++;
    }
    free(var.tab);
    return (1);
}
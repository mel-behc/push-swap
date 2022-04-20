#include "push_swap.h"

static void	insertion_sort(int *tab, int len)
{
	t_data var;
	int	j;

	var.i = 1;
	while (var.i < len)
	{
		var.number = tab[var.i];
		j = var.i - 1;
		while (j >= 0 && tab[j] >	var.number)
		{
			tab[j + 1] = tab[j];
			j -= 1;
		}
		tab[j + 1] =	var.number;
		var.i++;
	}
}

int	*insert_tab(t_node *head, int *count)
{
	t_data var;

	var.i = 0;
	var.tmp = head;
	var.tab = (int *)malloc(sizeof(int) * (*count));
	if (!var.tab)
		return (0);
	while (var.i < *count)
	{
		var.tab[var.i] = var.tmp->nbr;
		var.tmp = var.tmp->next;
		var.i++;
	}
	insertion_sort(var.tab, *count);
	return (var.tab);
}

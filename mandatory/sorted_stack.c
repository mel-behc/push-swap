/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:44:18 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 21:45:30 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copie_tab(t_node **head, int *count)
{
	t_data	var;

	var.i = 0;
	var.tmp = *head;
	var.tab = (int *)malloc(sizeof(int) * (*count));
	if (!var.tab)
		return (0);
	while (var.tmp)
	{
		var.tab[var.i] = var.tmp->nbr;
		var.tmp = var.tmp->next;
		var.i++;
	}
	return (var.tab);
}

int	sorted_stack(t_node **stack, int *count)
{
	t_data	var;

	var.i = 0;
	var.tab = copie_tab(stack, count);
	while (var.i < (*count - 1))
	{
		if (var.tab[var.i] > var.tab[var.i + 1])
		{
			free(var.tab);
			return (0);
		}
		else
			var.i++;
	}
	free(var.tab);
	return (1);
}

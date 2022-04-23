/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:43:27 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 21:43:47 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_a(t_node **stack_a, t_node **stack_b, int *count, int index)
{
	t_data	var;

	var.tmp = *stack_b;
	var.tab = insert_tab(*stack_b, count);
	while (index >= 0)
	{
		if (var.tmp->nbr == var.tab[index])
		{
			while (var.tmp != *stack_b)
			{
				if ((find_index(*stack_b, var.tmp->nbr)) <= (*count / 2))
					rotate_b(stack_b);
				else
					reverse_rotate_b(stack_b);
			}
			push_a(stack_a, stack_b);
			var.tmp = *stack_b;
			*count -= 1;
			index--;
		}
		else
			var.tmp = var.tmp->next;
	}
	free(var.tab);
}

void	sort_hundred_nbr(t_node **stack_a, int *count)
{
	t_data	var;

	var.stack_b = NULL;
	if (*count <= 100)
		var.devider = 3;
	else
		var.devider = 5;
	push_to_b(stack_a, &var.stack_b, count, var.devider);
	var.count_b = count_list(&var.stack_b);
	var.index = var.count_b - 1;
	push_to_a(stack_a, &var.stack_b, &var.count_b, var.index);
}

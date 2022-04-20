/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:50:55 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:51:52 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_small_nbr(t_node **stack)
{
	t_data	var;

	var.tmp = *stack;
	var.tmp2 = *stack;
	while (var.tmp->next && var.tmp2->next)
	{
		if (var.tmp->nbr < var.tmp2->nbr)
			var.tmp2 = var.tmp2->next;
		else
		{
			var.tmp = var.tmp2;
			var.tmp2 = var.tmp2->next;
		}
	}
	if (var.tmp->nbr > var.tmp2->nbr)
		var.tmp = var.tmp2;
	return (var.tmp->nbr);
}

static void	putnbr_intop(t_node **stack, int *length)
{
	t_data	var;

	var.tmp = *stack;
	while (var.tmp->next)
	{
		if (var.tmp->nbr == get_small_nbr(stack))
			break ;
		var.tmp = var.tmp->next;
	}
	var.i = find_index(*stack, var.tmp->nbr);
	while (var.tmp != *stack)
	{
		if (var.i > (*length / 2))
		{
			reverse_rotate_a(stack, length);
			var.i++;
		}
		else if (--var.i > -1)
			rotate_a(stack);
	}
}

void	sort_five_nbrs(t_node **stack_a, int *count)
{
	t_node	*stack_b;
	int		i;

	stack_b = NULL;
	i = 0;
	while (i < 2)
	{
		putnbr_intop(stack_a, count);
		push_b(stack_a, &stack_b);
		i++;
	}
	sort_three_nbrs(stack_a, count);
	push_a(stack_a, &stack_b);
	push_a(stack_a, &stack_b);
}
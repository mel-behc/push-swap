/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:41:39 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 21:42:04 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	moove_nbr_ina(t_node **stack, int nbr)
{
	t_data	var;

	var.tmp = *stack;
	while (var.tmp->next)
	{
		if (var.tmp->nbr == nbr)
		{
			while (var.tmp != *stack)
				rotate_a(stack);
			break ;
		}
		else
			var.tmp = var.tmp->next;
	}
}

static void	moove_nbr_inb(t_node **stack, int *tab, int index)
{
	t_data	var;

	var.tmp = *stack;
	if (var.tmp->nbr <= tab[index / 2])
	{
		while (var.tmp->next)
			rotate_b(stack);
	}
}

static void	rest_of_stack(t_node **stk_a, t_node **stk_b, int *count, int index)
{
	if (index < 5)
	{
		while (*count > 0)
		{
			putnbr_intop(stk_a, count);
			push_b(stk_a, stk_b);
			*count -= 1;
		}
	}
	else
		return ;
}

static int	initiate_vras(t_node **stack, int **tab, int *count, int *index)
{
	int	devider;

	if (*count > 100)
		devider = 5;
	else
		devider = 3;
	free(*tab);
	*tab = insert_tab(*stack, count);
	*index = *count / devider;
	return (0);
}

void	push_to_b(t_node **stack_a, t_node **stack_b, int *count, int devider)
{
	t_data	var;

	var.tmp = *stack_a;
	var.tab = insert_tab(*stack_a, count);
	var.index = *count / devider;
	var.length = 0;
	while (var.tmp->next && *count > 0)
	{
		if (var.tmp->nbr < var.tab[var.index])
		{
			moove_nbr_ina(stack_a, var.tmp->nbr);
			push_b(stack_a, stack_b);
			moove_nbr_inb(stack_b, var.tab, var.index);
			*count -= 1;
			var.tmp = *stack_a;
			if (++var.length == var.index)
				var.length = initiate_vras(stack_a, &var.tab, \
						count, &var.index);
			rest_of_stack(stack_a, stack_b, count, var.index);
		}
		else
			var.tmp = var.tmp->next;
	}
	free(var.tab);
}

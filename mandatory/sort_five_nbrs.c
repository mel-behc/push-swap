/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:50:55 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 23:36:36 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_nbrs(t_node **stack_a, int *count)
{
	t_node	*stack_b;

	stack_b = NULL;
	while (*count > 3)
	{
		putnbr_intop(stack_a, count);
		push_b(stack_a, &stack_b);
		*count -= 1;
	}
	if (!sorted_stack(stack_a, count))
		sort_three_nbrs(stack_a, count);
	push_a(stack_a, &stack_b);
	push_a(stack_a, &stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nbrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:52:00 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:52:11 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*ptr;

	tmp = *stack;
	ptr = *stack;
	while (ptr && ptr->next)
		ptr = ptr->next;
	tmp = tmp->next;
	if ((tmp->nbr < (*stack)->nbr) && (tmp->nbr < ptr->nbr) \
			&& ((*stack)->nbr < ptr->nbr))
		swap_a(stack);
	else if ((tmp->nbr < (*stack)->nbr) && (tmp->nbr < ptr->nbr) \
			&& ((*stack)->nbr > ptr->nbr))
	{
		rotate_a(stack);
	}
	else if ((tmp->nbr > (*stack)->nbr) && (tmp->nbr > ptr->nbr) \
			&& ((*stack)->nbr < ptr->nbr))
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

void	sort_three_nbrs(t_node **stack, int *count)
{
	t_node	*tmp;
	t_node	*ptr;

	tmp = *stack;
	ptr = *stack;
	while (ptr && ptr->next)
		ptr = ptr->next;
	tmp = tmp->next;
	check_stack(stack);
	if ((tmp->nbr > (*stack)->nbr) && (tmp->nbr > ptr->nbr) \
			&& ((*stack)->nbr > ptr->nbr))
		reverse_rotate_a(stack, count);
	else if ((tmp->nbr < (*stack)->nbr) && (tmp->nbr > ptr->nbr) \
			&& ((*stack)->nbr > ptr->nbr))
	{
		swap_a(stack);
		reverse_rotate_a(stack, count);
	}
}

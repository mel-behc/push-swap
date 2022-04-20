/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instractions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:48:52 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:49:03 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		data;

	tmp = *stack_b;
	data = tmp->nbr;
	insert_at_top(stack_a, data);
	delete_node(stack_b);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		data;

	tmp = *stack_a;
	data = tmp->nbr;
	insert_at_top(stack_b, data);
	delete_node(stack_a);
}

void	swap_a(t_node **list)
{
	t_node	*tmp;
	t_node	*ptr;
	t_node	*tmp2;

	tmp = *list;
	ptr = *list;
	tmp = tmp->next;
	*list = tmp;
	tmp2 = *list;
	tmp = tmp->next;
	ptr->next = tmp;
	tmp2->next = ptr;
}
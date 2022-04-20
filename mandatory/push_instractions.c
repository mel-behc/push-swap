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
	ft_putstr("pa\n");
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		data;

	tmp = *stack_a;
	data = tmp->nbr;
	insert_at_top(stack_b, data);
	delete_node(stack_a);
	ft_putstr("pb\n");
}

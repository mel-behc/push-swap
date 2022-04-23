/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instractions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:50:39 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:50:50 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_node **list)
{
	t_data	var;

	var.tmp = *list;
	var.tmp2 = *list;
	var.counter = count_list(list);
	var.i = 0;
	while (var.tmp && var.tmp->next)
		var.tmp = var.tmp->next;
	*list = var.tmp;
	var.tmp->next = var.tmp2;
	while (var.i < var.counter)
	{
		var.i++;
		var.tmp = var.tmp->next;
		if (var.i == var.counter - 1)
			var.tmp->next = NULL;
	}
}

void	reverse_rotate_b(t_node **list)
{
	t_data	var;

	var.tmp = *list;
	var.tmp2 = *list;
	var.counter = count_list(list);
	var.i = 0;
	while (var.tmp && var.tmp->next)
		var.tmp = var.tmp->next;
	*list = var.tmp;
	var.tmp->next = var.tmp2;
	while (var.i < var.counter)
	{
		var.i++;
		var.tmp = var.tmp->next;
		if (var.i == var.counter - 1)
			var.tmp->next = NULL;
	}
}

void	rotate_a(t_node **list)
{
	t_node	*tmp;
	t_node	*ptr;

	tmp = *list;
	ptr = *list;
	tmp = tmp->next;
	*list = tmp;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = ptr;
	ptr->next = NULL;
}

void	rotate_b(t_node **list)
{
	t_node	*tmp;
	t_node	*ptr;

	tmp = *list;
	ptr = *list;
	tmp = tmp->next;
	*list = tmp;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = ptr;
	ptr->next = NULL;
}

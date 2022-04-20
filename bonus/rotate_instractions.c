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

void	reverse_rotate_a(t_node **list, int *count)
{
	t_node	*tmp;
	t_node	*ptr;
	int		i;

	tmp = *list;
	ptr = *list;
	i = 0;
	while (tmp && tmp->next)
		tmp = tmp->next;
	*list = tmp;
	tmp->next = ptr;
	while (i < *count)
	{
		i++;
		tmp = tmp->next;
		if (i == *count - 1)
			tmp->next = NULL;
	}
}

void	reverse_rotate_b(t_node **list, int *count)
{
	t_node	*tmp;
	t_node	*ptr;
	int		i;

	tmp = *list;
	ptr = *list;
	i = 0;
	while (tmp && tmp->next)
		tmp = tmp->next;
	*list = tmp;
	tmp->next = ptr;
	while (i < *count)
	{
		i++;
		tmp = tmp->next;
		if (i == *count - 1)
			tmp->next = NULL;
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

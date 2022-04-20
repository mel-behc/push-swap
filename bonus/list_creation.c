/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:34:48 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:37:46 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_at_end(t_node **list, int nbr)
{
	t_node	*tmp;
	t_node	*new_node;

	tmp = *list;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	new_node->next = NULL;
	if (*list == NULL)
		*list = new_node;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

void	insert_at_top(t_node **list, int nbr)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->nbr = nbr;
	tmp->next = *list;
	*list = tmp;
}

void	delete_node(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	*list = (*list)->next;
	free(tmp);
	tmp = NULL;
}

int	count_list(t_node **head)
{
	t_node	*ptr;
	int		i;

	ptr = *head;
	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int	find_index(t_node *list, int nbr)
{
	t_node	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp->next)
	{
		if (tmp->nbr == nbr)
			break ;
		else
			i++;
		tmp = tmp->next;
	}
	return (i);
}
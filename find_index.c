/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:34:14 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:34:26 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

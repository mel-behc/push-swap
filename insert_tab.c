/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:34:32 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:34:42 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *tab, int len)
{
	int	i;
	int	j;
	int	nbr;

	i = 1;
	while (i < len)
	{
		nbr = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > nbr)
		{
			tab[j + 1] = tab[j];
			j -= 1;
		}
		tab[j + 1] = nbr;
		i++;
	}
}

int	*insert_tab(t_nd *head, int *count)
{
	t_nd	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tmp = head;
	tab = (int *)malloc(sizeof(int) * (*count));
	if (!tab)
		return (0);
	while (i < *count)
	{
		tab[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	insertion_sort(tab, *count);
	return (tab);
}

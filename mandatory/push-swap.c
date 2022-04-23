/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:37:58 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 23:34:57 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	execute_instractions(t_node **stack, int *element_counter)
{
	if (!sorted_stack(stack, element_counter))
	{
		if (*element_counter <= 3)
			sort_three_nbrs(stack, element_counter);
		else if (*element_counter <= 5)
			sort_five_nbrs(stack, element_counter);
		else if (*element_counter <= 100 || *element_counter >= 500)
			sort_hundred_nbr(stack, element_counter);
	}
	return (0);
	
}

int	main(int ac, char **av)
{
	t_data	var;

	var.i = 0;
	var.counter = ac - 1;
	var.stack_a = NULL;
	if (ac == 1)
		return (0);
	else
	{
		check_args(av, var.counter);
		while (var.i < var.counter)
		{
			var.number = read_args(av[var.i + 1]);
			insert_at_end(&var.stack_a, var.number);
			var.i++;
		}
		execute_instractions(&var.stack_a, &var.counter);
	}
	while (var.stack_a)
		delete_node(&var.stack_a);
	return (0);
}

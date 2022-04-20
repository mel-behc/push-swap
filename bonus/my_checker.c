/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:37:58 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:38:36 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_mooves(t_node **stack_a, t_node **stack_b, char *args, int *count)
{
	if (!ft_strncmp("sa", args, 2))
		swap_a(stack_a);
	else if (!ft_strncmp("ra", args, 2))
		rotate_a(stack_a);
	else if (!ft_strncmp("rb", args, 2))
		rotate_b(stack_a);
	else if (!ft_strncmp("rra", args, 3))
		reverse_rotate_a(stack_a, count);
	else if (!ft_strncmp("rrb", args, 3))
		reverse_rotate_b(stack_a, count);
	else if (!ft_strncmp("pa", args, 2))
	{
		if (*stack_b != NULL)
			push_a(stack_a, stack_b);
	}
	else if (!ft_strncmp("pb", args, 2))	
		push_b(stack_a, stack_b);
	else if (!ft_strncmp("rrr", args, 3))
		args = get_next_line(0);
	return (1);
}

static void good_stack(t_node **stack, t_node **stack_b, int *length)
{
	t_data	var;
	
	while (var.args)
	{
		if (check_mooves(stack, stack_b, var.args, &var.counter))
			var.args = get_next_line(0);
		else
			break ;
	}
	var.i = sorted_stack(stack, length);
	if (var.i == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_data	var;

	var.i = 0;
	var.counter = ac - 1;
	var.stack_a = NULL;
	var.stack_b = NULL;
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
		good_stack(&var.stack_a, &var.stack_b, &var.counter);
	}
	while (var.stack_a)
		delete_node(&var.stack_a);
	return (0);
}
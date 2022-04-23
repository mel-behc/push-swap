/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:37:58 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 21:39:35 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_mooves(t_node **st_a, t_node **st_b, char *args)
{
	// printf("I'm in check mooves\n");
	// printf("the length of list == %d\n", *count);
	if (!ft_strncmp("sa\n", args, 3))
		swap_a(st_a);
	else if (!ft_strncmp("ra\n", args, 3))
		rotate_a(st_a);
	else if (!ft_strncmp("rb\n", args, 3))
		rotate_b(st_b);
	else if (!ft_strncmp("rra\n", args, 4))
		reverse_rotate_a(st_a);
	else if (!ft_strncmp("rrb\n", args, 4))
		reverse_rotate_b(st_b);
	else if (!ft_strncmp("pa\n", args, 3))
	{
		if (*st_b != NULL)
			push_a(st_a, st_b);
	}
	else if (!ft_strncmp("pb\n", args, 3))
		push_b(st_a, st_b);
	else if (!ft_strncmp("rrr\n", args, 4))
		args = get_next_line(0);
	else if (!ft_strncmp("sb\n", args, 3) || !ft_strncmp("ss\n", args, 3))
		args = get_next_line(0);
	else if (!ft_strncmp("rr\n", args, 3))
		args = get_next_line(0);
	// free(args);
	// printf("I'm out of check mooves by :)\n");
	return (1);
}

static void	good_stack(t_node *stack, t_node *stack_b, int *length)
{
	t_data	var;

	var.args = get_next_line(0);
	while (var.args)
	{
		// printf("Welcome to good stack\n");
		// printf("var.args === %s\n", var.args);
		if (check_mooves(&stack, &stack_b, var.args))
			var.args = get_next_line(0);
		// printf("I'm out of good stack by :)\n");
		// else
		// {
		// 	break ;
		// }
	}
	var.i = sorted_stack(&stack, length);
	if (var.i)
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
		good_stack(var.stack_a, var.stack_b, &var.counter);
	}
	// while (var.stack_a)
	// 	delete_node(&var.stack_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:38:44 by mel-behc          #+#    #+#             */
/*   Updated: 2022/04/20 01:46:36 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_node
{
	int				nbr;
	struct t_node	*next;
}	t_node;

typedef struct t_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tmp;
	t_node	*tmp2;
	int		*tab;
	int		counter;
	int		count_b;
	int		number;
	int		index;
	int		length;
	int		devider;
	int		i;
}	t_data;

void	error_function(void);
long	ft_atol(const char *str);
void	ft_putstr(char *str);
int	count_list(t_node **head);
long	read_args(char *arg);
int		*insert_tab(t_node *head, int *count);
void	check_args(char **arg, int ac);
void	putnbr_intop(t_node **stack, int *length);
void	insert_at_end(t_node **list, int nbr);
void	insert_at_top(t_node **list, int nbr);
void	delete_node(t_node **list);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **list, int *count);
void	reverse_rotate_b(t_node **list, int *count);
void	rotate_a(t_node **list);
void	rotate_b(t_node **list);
void	swap_a(t_node **list);
int		find_index(t_node *list, int nbr);
void	sort_three_nbrs(t_node **stack, int *count);
void	sort_five_nbrs(t_node **stack_a, int *count);
void	push_to_b(t_node **stack_a, t_node **stack_b, int *count, int devider);
void	sort_hundred_nbr(t_node **stack_a, int *count);
void	print_list(t_node *ptr);

#endif

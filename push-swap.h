#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// typedef struct t_node
// {
//     int         nbr;
//     struct t_node *next;
// }   t_nd;

typedef struct  t_data
{
    // // t_node  *stack_a;
    // t_node  *stack_b;
    // t_node  *tmp;
    int     *tab;
    int     counter;
    int     number;
}   t_data;

void    error_function();
long     ft_atol(const char *str);
void    non_numeric_args(char *arg);
long    read_args(char *arg);

#endif
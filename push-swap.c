#include "push-swap.h"

static void execute_instractions(t_node **stack, int element_counter)
{
    if (element_counter == 3)
        sort_three_nbrs(stack, element_counter);
}


int main(int ac, char **av)
{
    t_data  var;

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
            // printf("heloooooooo\n");
            insert_at_end(&var.stack_a, var.number);
            var.i++;
        }
        // print_list(var.stack_a);
        execute_instractions(&var.stack_a, var.counter);
    }
    return (0);
}
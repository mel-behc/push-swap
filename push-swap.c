#include "push-swap.h"

int main(int ac, char **av)
{
    t_data  var;
    int     i;

    var.counter = ac - 1;
    i = 0;
    if (ac == 1)
        return (0);
    else
    {
        while (i < var.counter)
        {
            non_numeric_args(av[i + 1]);
            i++;
        }
    }
    return (0);
}
#include "push-swap.h"

static int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

void non_numeric_args(char *arg)
{
    int     i;
    int    number;

    i = 1;
    while (arg[i])
    {
        if ((arg[i] == '-' || !ft_isdigit(arg[i])) && i > 10)
            error_function();
        i++;
    }
    number = read_args(arg);
}


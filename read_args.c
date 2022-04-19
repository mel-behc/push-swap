#include "push-swap.h"

long read_args(char *arg)
{
    long number;

    number = ft_atol(arg);
    if (number > 2147483647 || number < -2147483648)
        error_function();
    return number;
} 
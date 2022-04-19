#include "push-swap.h"

static int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

static void non_numeric_args(char *arg)
{
    int     i;

    i = 1;
    while (arg[i])
    {
        if ((arg[0] == '-' && !ft_isdigit(arg[i])) || i > 10)
            error_function();
        else if ((arg[0] != '-' && !ft_isdigit(arg[0])) || i > 10)
            error_function();
        i++;
    }
}

static int check_duplicate(int *tab, int ac)
{
	t_data	var;
	int		j;

	var.i = 0;
	while (var.i < ac)
	{
		j = var.i + 1;
		while (j < ac)
		{
			if (tab[var.i] == tab[j])
				return (0);
			else
				j++;
		}
		var.i++;
	}
	return (1);
}

void check_args(char **arg, int ac)
{
    t_data  var;

    var.i = 0;
    var.tab = (int *)malloc(sizeof(int) * ac);
    if (!var.tab)
        return ;
    while (var.i < ac)
    {
        non_numeric_args(arg[var.i + 1]);
        var.number = read_args(arg[var.i + 1]);
        var.tab[var.i] = var.number;
        var.i++;
    }
    if (!check_duplicate(var.tab, ac))
    {
        free(var.tab);
        error_function();
    }
}
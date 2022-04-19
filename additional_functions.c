#include "push-swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	f;
	int		signe;

	i = 0;
	f = 0;
	signe = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		f = (f * 10) + str[i] - '0';
		i++;
	}
	return (f * signe);
}

void error_function()
{
    ft_putstr("Error\n");
    exit (0);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
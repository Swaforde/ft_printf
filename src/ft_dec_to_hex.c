#include "../include/ft_printf.h"

void	ft_convert(int n, int mod)
{
		if (n >= 16)
		{
			ft_convert(n / 16, mod);
		}
		n %= 16;
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (mod == 1)
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (mod == 2)
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
}

int	ft_dec_to_hex(int n, int mod)
{
	int	t;
	int	i;

	t = n;
	i = 0; 
	while (t >= 16)
	{
		t /= 16;
		i++;
	}
	i++;
	ft_convert(n, mod);
	return (i);
}

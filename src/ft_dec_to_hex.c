#include "../include/ft_printf.h"

void	ft_convert(unsigned n, int mod)
{
		if (n >= 16)
		{
			ft_convert(n / 16, mod);
			ft_convert(n % 16, mod);
		}
		else
		{
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
}

int	ft_dec_to_hex(unsigned n, int mod)
{
	unsigned i;
	int	t;

	i = n;
	t = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_convert(n, mod);
	while (i != 0)
	{
		i /= 16;
		t ++;
	}
	return (t);
}

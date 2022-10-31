#include "../include/ft_printf.h"

int	ft_increment_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_increment_putstr(char *s)
{
	int	index;
	int	return_value;

	index = 0;
	return_value = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[index] != '\0')
	{
		write (1, s + index, 1);
		index ++;
		return_value++;
	}
	return (return_value);
}

int	ft_increment_percent()
{
	write (1, "%", 1);
	return (1);
}
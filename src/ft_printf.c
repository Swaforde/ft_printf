#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*str_itoa;
	int		char_readed;
	int		i;

	i = 0;
	char_readed = 0;
	va_start (args, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				char_readed += ft_increment_percent();
			if (str[i] == 'c')
				char_readed += ft_increment_putchar(va_arg(args, int));
			if (str[i] == 's')
				char_readed += ft_increment_putstr(va_arg(args, char *));
			if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
			{
				str_itoa = ft_itoa(va_arg(args, int));
				char_readed += ft_increment_putstr(str_itoa);
				free (str_itoa);
			}
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			char_readed++;
		}
		i++;
	}
	va_end(args);
	return (char_readed);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/10/18 10:43:06 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_check_format(const char *str, int i, va_list args)
{
	int char_readed;
	char	*str_itoa;

	char_readed = 0;
	if (str[i] == '%')
		char_readed += ft_increment_percent();
	if (str[i] == 'c')
		char_readed += ft_increment_putchar(va_arg(args, int));
	if (str[i] == 's')
		char_readed += ft_increment_putstr(va_arg(args, char *));
	if (str[i] == 'd' || str[i] == 'i')
	{
		str_itoa = ft_itoa(va_arg(args, int));
		char_readed += ft_increment_putstr(str_itoa);
		free (str_itoa);
	}
	if (str[i] == 'u')
	{
		str_itoa = ft_increment_itoa(va_arg(args, unsigned int));
		char_readed += ft_increment_putstr(str_itoa);
		free (str_itoa);
	}
	if (str[i] == 'x')
		char_readed += ft_dec_to_hex(va_arg(args, int), 1);
	if (str[i] == 'X')
		char_readed += ft_dec_to_hex(va_arg(args, int), 2);
	if (str[i] == 'p')
		char_readed += ft_print_ptr(va_arg(args, unsigned long long));
	return (char_readed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_readed;
	char *str_itoa;
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
			if (str[i] == 'd' || str[i] == 'i')
			{
				str_itoa = ft_itoa(va_arg(args, int));
				char_readed += ft_increment_putstr(str_itoa);
				free (str_itoa);
			}
			if (str[i] == 'u')
			{
				str_itoa = ft_increment_itoa(va_arg(args, unsigned int));
				char_readed += ft_increment_putstr(str_itoa);
				free (str_itoa);
			}
			if (str[i] == 'x')
				char_readed += ft_dec_to_hex(va_arg(args, int), 1);
			if (str[i] == 'X')
				char_readed += ft_dec_to_hex(va_arg(args, int), 2);
			if (str[i] == 'p')
				char_readed += ft_print_ptr(va_arg(args, unsigned long long));	
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

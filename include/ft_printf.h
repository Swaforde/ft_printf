#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_increment_putchar(int c);
int	ft_increment_putstr(char *s);
int	ft_increment_percent();

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouvera <tbouvera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:53:03 by tbouvera          #+#    #+#             */
/*   Updated: 2022/11/01 10:54:15 by tbouvera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_increment_putchar(int c);
int		ft_increment_putstr(char *s);
int		ft_increment_percent(void);
int		ft_dec_to_hex(unsigned int n, int mod);
char	*ft_increment_itoa(unsigned int n);
int		ft_print_ptr(unsigned long long ptr);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:24:30 by aennaki           #+#    #+#             */
/*   Updated: 2022/11/01 01:37:06 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long ptr, char *base);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_printf(const char *fmt, ...);
int		ft_printfmt(const char *fmt, va_list ap, int i, int c);

#endif

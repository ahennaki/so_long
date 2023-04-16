/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:35:16 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/23 17:07:46 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printfmt(const char *fmt, va_list ap, int i, int c)
{
	if (fmt[i] == 'd' || fmt[i] == 'i')
		c = ft_putnbr(va_arg(ap, int));
	else if (fmt[i] == 's')
		c = ft_putstr(va_arg(ap, char *));
	else if (fmt[i] == 'c')
		c = ft_putchar(va_arg(ap, int));
	else if (fmt[i] == 'p')
	{
		c = write(1, "0x", 2);
		c = ft_putptr(va_arg(ap, unsigned long), "0123456789abcdef");
	}
	else if (fmt[i] == 'u')
		c = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (fmt[i] == 'x')
		c = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (fmt[i] == 'X')
		c = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (fmt[i] == '%')
		c = ft_putchar('%');
	else
		c = ft_putchar(fmt[i]);
	return (c);
}

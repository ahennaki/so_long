/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:41:53 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/25 15:18:33 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		c;

	if (write(1, &fmt[0], 0) < 0)
		return (-1);
	c = 0;
	i = -1;
	va_start(ap, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			if (!fmt[i + 1])
				return (c);
			c += ft_printfmt(fmt, ap, ++i, 0);
		}
		else
			c += ft_putchar(fmt[i]);
	}
	va_end(ap);
	return (c);
}

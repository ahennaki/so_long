/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:32:57 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/23 17:08:02 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	c;

	c = 0;
	if (!str)
		return (write(1, "(null)", 6));
	i = -1;
	while (str[++i])
		c += ft_putchar(str[i]);
	return (c);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		c;

	nb = n;
	c = 0;
	if (nb < 0)
	{
		nb *= (-1);
		c += ft_putchar('-');
	}
	if (nb > 9)
		c += ft_putnbr((nb / 10));
	c += ft_putchar((nb % 10 + '0'));
	return (c);
}

int	ft_putptr(unsigned long ptr, char *base)
{
	int				c;
	unsigned long	i;
	unsigned long	nb;

	i = 0;
	c = 0;
	while (base[i])
		i++;
	nb = ptr;
	if (nb >= i)
		c += ft_putptr(nb / i, base);
	c += ft_putchar(base[nb % i]);
	return (c);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	long	i;
	long	nb;
	int		c;

	c = 0;
	i = 0;
	while (base[i])
		i++;
	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= i)
		c += ft_putnbr_base(nb / i, base);
	c += ft_putchar(base[nb % i]);
	return (c);
}

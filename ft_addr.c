/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:08:29 by olachhab          #+#    #+#             */
/*   Updated: 2024/11/27 11:14:34 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthexa(n / 16);
	}
	n = n % 16;
	if (n < 10)
	{
		count += ft_putchar(n + '0');
	}
	else
	{
		count += ft_putchar(n - 10 + 'a');
	}
	return (count);
}

int	ft_addr(void *ptr)
{
	unsigned long	num;
	int				count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	num = (unsigned long)ptr;
	count += ft_putchar('0');
	count += ft_putchar('x');
	if (num == 0)
	{
		count += ft_putchar('0');
	}
	else
	{
		count += ft_puthexa(num);
	}
	return (count);
}

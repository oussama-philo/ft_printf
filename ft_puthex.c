/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:40 by olachhab          #+#    #+#             */
/*   Updated: 2024/11/27 11:14:07 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int type)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	if (n >= 16)
	{
		count += ft_puthex(n / 16, type);
	}
	n = n % 16;
	if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		if (type == 'x')
			count += ft_putchar(n - 10 + 'a');
		else if (type == 'X')
			count += ft_putchar(n - 10 + 'A');
	}
	return (count);
}

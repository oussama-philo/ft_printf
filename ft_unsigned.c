/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:53 by olachhab          #+#    #+#             */
/*   Updated: 2024/11/27 11:09:54 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int nb)
{
	int					count;
	unsigned long long	num;

	num = nb;
	count = 0;
	if (num == 0 && count == 0)
	{
		count += ft_putchar('0');
	}
	else if (num >= 10)
	{
		count += ft_unsigned(num / 10);
		count += ft_unsigned(num % 10);
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}

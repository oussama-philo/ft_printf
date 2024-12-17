/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:43 by olachhab          #+#    #+#             */
/*   Updated: 2024/12/11 11:54:51 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb < 0)
	{
		printed_chars += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		printed_chars += ft_putnbr(nb / 10);
		printed_chars += ft_putnbr(nb % 10);
	}
	else
		printed_chars += ft_putchar(nb + '0');
	return (printed_chars);
}

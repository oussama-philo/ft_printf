/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:57:18 by olachhab          #+#    #+#             */
/*   Updated: 2024/12/12 11:18:48 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hash_flag(t_format *current, va_list args)
{
	int				printed_chars;
	unsigned int	value;

	printed_chars = 0;
	if (current->type == 'x' || current->type == 'X')
	{
		value = va_arg(args, unsigned int);
		if (value != 0)
		{
			if (current->type == 'x')
			{
				write(1, "0x", 2);
			}
			else if (current->type == 'X')
			{
				write(1, "0X", 2);
			}
			printed_chars += 2;
		}
		printed_chars += ft_puthex(value, current->type);
	}
	else if (current->type == 'p')
		printed_chars += ft_addr(va_arg(args, void *));
	return (printed_chars);
}

int	handle_space_flag(t_format *current, va_list args)
{
	int	printed_chars;
	int	value;

	printed_chars = 0;
	if (current->type == 'd' || current->type == 'i')
	{
		if (!current->flag_plus)
		{
			value = va_arg(args, int);
			if (value >= 0)
				printed_chars += write(1, " ", 1);
			printed_chars += ft_putnbr(value);
			return (printed_chars);
		}
	}
	else if (current->type == 's')
	{
		if (current->flag_space)
		{
			printed_chars += ft_putstr(va_arg(args, char *));
			return (printed_chars);
		}
	}
	return (0);
}

int	handle_plus_flag(t_format *current, va_list args)
{
	int	printed_chars;
	int	value;

	printed_chars = 0;
	if (current->type == 'd' || current->type == 'i')
	{
		value = va_arg(args, int);
		if (value >= 0)
		{
			write(1, "+", 1);
			printed_chars++;
		}
		printed_chars += ft_putnbr(value);
	}
	return (printed_chars);
}

int	handle_type(t_format *current, va_list args)
{
	int	printed_chars;

	if (current->type)
	{
		printed_chars = 0;
		if (current->type == 'd' || current->type == 'i')
			printed_chars += ft_putnbr(va_arg(args, int));
		else if (current->type == 'c')
			printed_chars += ft_putchar(va_arg(args, int));
		else if (current->type == 's')
			printed_chars += ft_putstr(va_arg(args, char *));
		else if (current->type == 'x' || current->type == 'X')
			printed_chars += ft_puthex(va_arg(args, unsigned int),
					current->type);
		else if (current->type == 'p')
			printed_chars += ft_addr(va_arg(args, void *));
		else if (current->type == 'u')
			printed_chars += ft_unsigned(va_arg(args, unsigned int));
		else if (current->type == '%')
			printed_chars += write(1, "%", 1);
		return (printed_chars);
	}
	else
		return (-1);
}

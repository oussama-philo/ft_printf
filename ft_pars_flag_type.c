/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flag_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:11:04 by olachhab          #+#    #+#             */
/*   Updated: 2024/12/11 10:46:54 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char *format, int *i, t_format *node)
{
	while (ft_strchr("# +", format[*i]))
	{
		if (format[*i] == '#')
			node->flag_hash = 1;
		else if (format[*i] == ' ')
			node->flag_space = 1;
		else if (format[*i] == '+')
			node->flag_plus = 1;
		(*i)++;
	}
}

int	parse_type(const char *format, int *i, t_format *node)
{
	if (ft_strchr("cspdixXu%", format[*i]))
	{
		node->type = format[*i];
		(*i)++;
		return (1);
	}
	return (0);
}

int	handle_flags(t_format *current, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (current->flag_hash)
		printed_chars += handle_hash_flag(current, args);
	if (current->flag_space)
		printed_chars += handle_space_flag(current, args);
	if (current->flag_plus)
		printed_chars += handle_plus_flag(current, args);
	return (printed_chars);
}

int	handle_specifier(t_format *current, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (current->type != 0 && current->flag_plus == 0
		&& current->flag_space == 0 && current->flag_hash == 0)
		printed_chars += handle_type(current, args);
	return (printed_chars);
}

int	handle_format_specifier(const char *format, int *i,
			t_format **current, va_list args)
{
	int	total_printed;

	total_printed = 0;
	(*i)++;
	while (format[*i] && ft_strchr("# +", format[*i]))
		(*i)++;
	if (format[*i] && ft_strchr("cspdixXu%", format[*i]))
	{
		total_printed += handle_flags(*current, args);
		total_printed += handle_specifier(*current, args);
		(*i)++;
		*current = (*current)->next;
	}
	return (total_printed);
}

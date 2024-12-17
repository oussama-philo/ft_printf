/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:29 by olachhab          #+#    #+#             */
/*   Updated: 2024/12/17 10:07:44 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_list(t_format *head)
{
	t_format	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

static t_format	*pass_format(const char *format)
{
	int			i;
	t_format	*node;
	t_format	*head;

	head = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			node = create_node();
			if (!node)
				return (NULL);
			parse_flags(format, &i, node);
			if (parse_type(format, &i, node))
			{
				add_node(&head, node);
			}
		}
		else
			i++;
	}
	return (head);
}

int	process_format_string(const char *format, va_list args, t_format *head)
{
	t_format	*current;
	int			i;
	int			total_printed;

	if (!format)
		return (-1);
	current = head;
	total_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && current)
		{
			total_printed += handle_format_specifier(format, &i,
					&current, args);
		}
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				return (-1);
			total_printed += write(1, &format[i], 1);
			i++;
		}
	}
	return (total_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	*head;
	int			total_printed;

	if (!format)
		return (-1);
	head = pass_format(format);
	va_start(args, format);
	total_printed = process_format_string(format, args, head);
	va_end(args);
	free_list(head);
	return (total_printed);
}

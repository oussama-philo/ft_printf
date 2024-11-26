#include "ft_printf.h"

void free_list(t_format *head)
{
	t_format *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int process_specifier(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (type == 'p')
		return (ft_addr(va_arg(args, void *)));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(args, unsigned int), type));
	else if (type == '%')
		return (write(1, "%", 1));
	return (0);
}

t_format *pass_format(const char *format)
{
	int i;
	t_format *node;
	t_format *head;

	head = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (ft_strchr("cspdixXu%", format[i]))
			{
				node = create_node(format[i]);
				if (!node)
				{
					return (NULL);
				}
				add_node(&head, node);
			}
		}
		i++;
	}
	return (head);
}

int process_format_string(const char *format, va_list args, t_format *head)
{
	t_format *current;
	int i;
	int total_printed;

	if (!format)
		return (-1);
	current = head;
	i = 0;
	total_printed = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (current)
			{
				total_printed += process_specifier(current->type, args);
				current = current->next;
			}
		}
		else
			total_printed += write(1, &format[i], 1);
		i++;
	}
	return (total_printed);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	t_format *head;
	int total_printed;

	if (!format)
		return (-1);
	head = pass_format(format);
	va_start(args, format);
	total_printed = process_format_string(format, args, head);
	va_end(args);
	free_list(head);
	return (total_printed);
}

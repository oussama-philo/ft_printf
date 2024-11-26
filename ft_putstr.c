#include "ft_printf.h"

int ft_putstr(char *str)
{
	int count;
	int i;

	if (str == NULL)
	{
		return ("NULL");
	}
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

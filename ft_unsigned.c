#include "ft_printf.h"

int ft_unsigned(unsigned long nb)
{
	int count;

	count = 0;
	if (nb == 0 && count == 0)
	{
		count += ft_putchar('0');
	}
	else if (nb >= 10)
	{
		count += ft_unsigned(nb / 10);
		count += ft_unsigned(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

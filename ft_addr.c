#include "ft_printf.h"

static int ft_puthexa(unsigned long n)
{
	int count = 0;

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

int ft_addr(void *ptr)
{
	unsigned long num;
	int count;

	num = (unsigned long)ptr;
	count = 0;
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

#include "ft_printf.h"

int main()
{
	int a = ft_printf("%u", 255);
	ft_printf("\n");
	ft_printf("%d", a);
	return 0;
}

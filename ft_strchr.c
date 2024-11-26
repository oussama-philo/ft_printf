#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;
	const char		*ptr;

	target = (unsigned char)c;
	ptr = s;
	while (*ptr)
	{
		if (*ptr == target)
		{
			return ((char *)ptr);
		}
		ptr++;
	}
	if (*ptr == target)
	{
		return ((char *)ptr);
	}
	return (NULL);
}

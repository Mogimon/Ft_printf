#include "ft_printf.h"

int	ft_hex(unsigned long long num, const char c)
{
	int	count;

	// printf("%llu, %c\n", num, c);
	count = 0;
	if (num >= 16)
	{
		count += ft_hex((num / 16), c);
		count += ft_hex((num % 16), c);
	}
	else if (num > 9)
	{
		if (c == 'x')
			count += ft_printchar(num + 87);
		else if (c == 'X')
			count += ft_printchar(num + 55);
	}
	else
		count += ft_printchar(num + '0');
	return (count);
}
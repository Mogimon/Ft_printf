#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_unsigned(n / 10);
		count += ft_unsigned(n % 10);
	}
	else
		count += ft_printchar(n + '0');
	return (count);
}
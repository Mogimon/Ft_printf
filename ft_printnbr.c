#include "ft_printf.h"

int	ft_printnbr(int n)
{
	unsigned long	num;
	int	count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_printchar('-');
		num *= -1;
	}
	if (num > 9)
	{
		count += ft_printnbr(num / 10);
		count += ft_printnbr(num % 10);
	}
	else
		count += ft_printchar(num + '0');
	return (count);
}
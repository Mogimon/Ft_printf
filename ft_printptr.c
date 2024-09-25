#include "ft_printf.h"

int	ft_printptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_hex(ptr, 'x');
	return (count);
}
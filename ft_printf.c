#include "ft_printf.h"

int ft_classify(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == '%')
		len += write(1, "%%", 1);
	else if ((c == 'd') || (c == 'i'))
		len += ft_printnbr(va_arg(args, int));
	else if ((c == 'x') || (c == 'X'))
		len += ft_hex(va_arg(args, unsigned int), c);
	else if (c == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'u')
		len += ft_unsigned(va_arg(args, unsigned int));
	return (len);
}
int ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			len += ft_classify(args, format[++i]);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
int	sum (int count, ...)
{
	va_list	args;
	int	total;

	total = 0;
	va_start(args, count);
	for (int	i = 0; i < count; i++)
	{
		total += va_arg(args, int);
	}
	va_end(args);
	return total;
}
int	main (void)
{
	char	*a = "sdf";

	printf("printf sum of %%, %c, %s ", 'A', "hello");
	printf("%x, %X = %d %p\n", 10, 10, 55, a);
	ft_printf("printf sum of %%, %c, %s ", 'A', "hello");
	ft_printf("%x, %X = %d %p\n", 10, 10, 55, a);

	return (0);
}
#include "ft_printf.h"

void	ft_classify(va_list args, char c)
{
	// (void) args;
	if (c == '%')
		write(1, "%%", 1);
	else if ((c == 'd') || (c == 'i') || (c == 'u'))
		ft_printnbr(va_arg(args, int));
	else if ((c == 'x') || (c == 'X'))
		printf("%d", va_arg(args, int));
		// ft_hex(va_arg(args, unsigned int), c);
	else if (c == 'c')
		ft_printchar(va_arg(args, int));
	else if (c == 's')
		// write(1, "A", 1);
		 printf("%s", va_arg(args, char *));
		// // ft_printstr(va_arg(args, char *));
		// }
	else if (c == 'p')
		ft_printptr(va_arg(args, unsigned long long));
}
int ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	// t_printf	tab;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_classify(args, format[++i]);
		else
			write(1, &format[i], 1);
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
	// char	*a = "sdf";

	printf("sum of %%, %c, %x, %X = %d \n", 'A', 10, 10, sum(3, 3, 4, 6));
	ft_printf("sum of %%, %c, %x, %X = %d \n", 'A', 10, 10, sum(3, 3, 4, 6));

	return (0);
}
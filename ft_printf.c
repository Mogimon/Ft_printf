#include "ft_printf.h"

void	ft_classify(va_list args, char c)
{
	// (void) args;
	if (c == '%')
		write(1, "%", 1);
	else if ((c == 'd') || (c == 'i') || (c == 'u'))
		write(1, "deci", 4);
	else if ((c == 'x') || (c == 'X'))
		{
			printf("%d\n", va_arg(args, int));
			ft_hex(va_arg(args, int), c);
		}
	else if (c == 'c')
		ft_printchar(va_arg(args, int));
	else if (c == 's')
		{
			// char	*str;

			// str = va_arg(args, char *);
			// while (*str != '\0')
			// 	write(1, str++, 1);
			//ft_printstr(va_arg(args, char *));
		}
	else if (c == 'p')
		write(1, "ptr", 3);
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
	printf("sum of %%, %c, %s, %x, %X = %d\n", 'A', "hello", 10, 10, sum(3, 3, 4, 6));
	ft_printf("sum of %%, %c, %s, %x, %X = %d\n", 'A', "hello", 10, 10, sum(3, 3, 4, 6));

	return (0);
}
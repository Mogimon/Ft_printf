#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	m;
	printf("%s", s);
	m = 0;
	if (!s)
		return (write(1, "NULL", 5));
	while (s[m])
		write (1, &s[m++], 1);
	return (1);
}
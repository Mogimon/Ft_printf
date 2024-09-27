#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	m;

	m = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[m])
		write (1, &s[m++], 1);
	return (m);
}